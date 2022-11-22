#include "ImageProcessing.h"

void processImage(char* file) {
    // Image file
    std::ifstream infile;
    infile.open(file, std::ios_base::binary);

    // Output image file
    std::ofstream outfile;
    outfile.open("./Output/output.jpg", std::ios_base::binary);

    // Grab binary data from JPG File
    std::vector<int> data = std::vector<int>(std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>());
    
    // Process data to end of JPG File
    int position {0};
    int marker {0};
    do {
        marker = getMarker(data, &position);

        switch (marker)
        {
        case START_OF_IMAGE:
            processSOI(data, &position, outfile);
            break;
        case APPLICATION_0:
            processApp(data, &position, outfile);
            break;
        case QUANTIZATION_TABLE:
            processQuantTable(data, &position, outfile);
            break;
        case START_OF_FRAME:
            processSOF(data, &position, outfile);
            break;
        case HUFFMAN_TABLE:
            processHTable(data, &position, outfile);
            break;
        case START_OF_SCAN:
            processSOS(data, &position, outfile);
            break;
        default:
            std::cout << "DEBUG MESSAGE: Invalid Marker" << std::endl;
            break;
        }

    } while (marker != END_OF_IMAGE);

    infile.close();
}

void printNum(int n) {
    std::cout << std::setw(2) << std::setfill('0') << std::hex << n << std::endl;
}

uint32_t getMarker(std::vector<int>& data, int* position) {
    uint32_t temp {0};
    for (int i {0}; i < SIZE_OF_MARKER; i++) {
        // Left Shift 8
        temp = temp << BYTE;
        // Set Lowest 8 Bits
        temp = temp | ((data).at(i + *position) & 0xff);
    }
    // Update position
    *position += SIZE_OF_MARKER;
    return temp;
}

void processSOI(std::vector<int>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Start of Image" << std::endl;
    // Output to Marker to JPG
    outfile << START_OF_IMAGE;
}

void processApp(std::vector<int>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Application 0..." << std::endl;

    // Output to Marker to JPG
    outfile << APPLICATION_0;

    // Create Struct for this
    uint16_t length {0};
    uint32_t id_1 {0};
    uint8_t id_2 {0};



    length = ((data.at(*position) & 0xff) << BYTE) | (data.at(*position + 1) & 0xff);
    *position += SIZE_OF_LENGTH;
    printNum(length);
}

void processQuantTable(std::vector<int>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Quantization Table..." << std::endl;
}

void processSOF(std::vector<int>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Start of Frame..." << std::endl;
}

void processHTable(std::vector<int>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Huffman Table..." << std::endl;
}

void processSOS(std::vector<int>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Start of Scan..." << std::endl;
}