#include "ImageProcessing.h"

void processImage(char* file) {
    // Image file
    std::ifstream infile;
    infile.open(file, std::ios_base::binary);

    // Output image file
    std::ofstream outfile;
    outfile.open("./Output/output.jpg", std::ios_base::binary);

    // Grab binary data from JPG File
    std::vector<char> data = std::vector<char>(std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>());
    
    // Process data to end of JPG File
    int position {0};
    char marker {0};
    do {
        marker = read_int8(data, &position);

        switch (marker)
        {
        // case START_OF_IMAGE:
        //     processSOI(data, &position, outfile);
        //     break;
        // case APPLICATION_0:
        //     processApp(data, &position, outfile);
        //     break;
        // case QUANTIZATION_TABLE:
        //     processQuantTable(data, &position, outfile);
        //     break;
        // case START_OF_FRAME:
        //     processSOF(data, &position, outfile);
        //     break;
        // case HUFFMAN_TABLE:
        //     processHTable(data, &position, outfile);
        //     break;
        // case START_OF_SCAN:
        //     processSOS(data, &position, outfile);
        //     break;
        default:
            outfile << marker;
            //std::cout << "DEBUG MESSAGE: Invalid Marker" << std::endl;
            break;
        }

    } while (marker != END_OF_IMAGE);
    // Output to Marker to JPG
    outfile << END_OF_IMAGE;

    infile.close();
}

void printNum(uint16_t n) {
    std::cout << std::setw(2) << std::setfill('0') << std::hex << n << std::endl;
}

void processSOI(std::vector<char>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Start of Image" << std::endl;
    // Output to Marker to JPG
    outfile << START_OF_IMAGE;
}

void processApp(std::vector<char>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Application 0..." << std::endl;

    // Output to Marker to JPG
    outfile << APPLICATION_0;

    // Create and store data
    application_0 app_0;
    app_0.length = read_int16(data, position);
    app_0.id_1 = read_int32(data, position);
    app_0.id_2 = read_int8(data, position);
    app_0.version = read_int16(data, position);
    app_0.units = read_int8(data, position);
    app_0.density = read_int32(data, position);
    app_0.thumbnail = read_int16(data, position);

    // Display Data 
    std::cout << "Length: " << std::bitset<16>(app_0.length) << std::endl;
    std::cout << "ID 1: " << std::bitset<32>(app_0.id_1) << std::endl;
    std::cout << "ID 2: " << std::bitset<8>(app_0.id_2) << std::endl;
    std::cout << "Version: " << std::bitset<16>(app_0.version) << std::endl;
    std::cout << "Units: " << std::bitset<8>(app_0.units) << std::endl;
    std::cout << "Density: " << std::bitset<32>(app_0.density) << std::endl;
    std::cout << "Thumbnail: " << std::bitset<16>(app_0.thumbnail) << std::endl;

    // Output Data to JPG
    outfile << app_0.length << app_0.id_1 << app_0.id_2 << app_0.version 
        << app_0.units << app_0.density << app_0.thumbnail;
}

void processQuantTable(std::vector<char>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Quantization Table..." << std::endl;

    // Output to Marker to JPG
    outfile << QUANTIZATION_TABLE;
}

void processSOF(std::vector<char>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Start of Frame..." << std::endl;

    // Output to Marker to JPG
    outfile << START_OF_FRAME;
}

void processHTable(std::vector<char>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Huffman Table..." << std::endl;

    // Output to Marker to JPG
    outfile << HUFFMAN_TABLE;
}

void processSOS(std::vector<char>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Start of Scan..." << std::endl;

    // Output to Marker to JPG
    outfile << START_OF_SCAN;
}

u_int8_t read_int8(std::vector<char>& data, int* position) {
    u_int8_t temp = (data.at(*position) & 0xff);
    *position += SIZE_OF_U8INT;
    return temp;
}

uint16_t read_int16(std::vector<char>& data, int* position) {
    uint16_t temp = ((data.at(*position) & 0xff) << BYTE) | (data.at(*position + 1) & 0xff);
    *position += SIZE_OF_U16INT;
    return temp;
}

uint32_t read_int32(std::vector<char>& data, int* position) {
    uint16_t temp = ((data.at(*position) & 0xff) << BYTE * 3) | 
                    ((data.at(*position + 1) & 0xff) << BYTE * 2) |
                    ((data.at(*position + 2) & 0xff) << BYTE) |
                    (data.at(*position + 3) & 0xff);
    *position += SIZE_OF_U32INT;
    return temp;
}