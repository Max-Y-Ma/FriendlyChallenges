#include "ImageProcessing.h"

void processImage(char* file) {
    // Image file
    std::ifstream infile;
    infile.open(file, std::ios_base::binary);

    // Output image file
    std::ofstream outfile;
    outfile.open("./Output/output.jpg", std::ios_base::binary);

    // Grab binary data from JPG File
    std::vector<u_int8_t> data = std::vector<u_int8_t>(std::istreambuf_iterator<char>(infile), std::istreambuf_iterator<char>());
    
    // Process data to end of JPG File
    int position {0};
    u_int8_t marker[2];
    u_int16_t m;
    do {
        // Read Marker in Two Bytes
        marker[1] = read_int8(data, &position);
        marker[0] = read_int8(data, &position);

        // Reconstruct Marker
        m = marker[1];
        m = m << 8;
        m = m | marker[0];

        switch (m)
        {
        // case START_OF_IMAGE:
        //     processSOI(data, &position, outfile);
        //     break;
        // case APPLICATION_0:
        //     processApp(data, &position, outfile);
        //     break;
        case QUANTIZATION_TABLE:
            outfile << marker[1] << marker[0];
            processQuantTable(data, &position, outfile);
            break;
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
            // Metadata, Otherstuff
            outfile << marker[1] << marker[0];
            break;
        }
    } while (m != END_OF_IMAGE);

    infile.close();
}

void printNum(uint16_t n) {
    std::cout << std::setw(2) << std::setfill('0') << std::hex << n << std::endl;
}

void processSOI(std::vector<u_int8_t>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Start of Image" << std::endl;

    // Output to Marker to JPG
    outfile << START_OF_IMAGE;
}

void processApp(std::vector<u_int8_t>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Application 0..." << std::endl;

    // Output to Marker to JPG
    outfile << APPLICATION_0;
}

void processQuantTable(std::vector<u_int8_t>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Quantization Table..." << std::endl;

    // Quantization Table Struct
    quantization_table qtable;
    qtable.length[1] = read_int8(data, position);
    qtable.length[0] = read_int8(data, position);
    qtable.destination = read_int8(data, position);

    // Read Quantization Table
    std:: cout << "Quant Table: " << std::bitset<8>(qtable.destination) << std::endl;
    for (int i {0}; i < QTABLE_SIZE; i++) {
        for (int j {0}; j < QTABLE_SIZE; j++) {
            qtable.table[i][j] = read_int8(data, position);
        }
    }

    // Output Length and Destination to JPG
    outfile << qtable.length[1] << qtable.length[0] << qtable.destination;

    uint8_t Chrominance = 10;
    uint8_t Luminance = 5;
    // Output New Quantization Table to JPG
    for (int i {0}; i < QTABLE_SIZE; i++) {
        for (int j {0}; j < QTABLE_SIZE; j++) {
            /*ADD YOUR CODE HERE */
            /*ADD YOUR CODE HERE */
            /*ADD YOUR CODE HERE */
            /*ADD YOUR CODE HERE */
            /*ADD YOUR CODE HERE */
            /*ADD YOUR CODE HERE */
            /*ADD YOUR CODE HERE */
            /*ADD YOUR CODE HERE */
            /*ADD YOUR CODE HERE */
            
        }
    }
}

void processSOF(std::vector<u_int8_t>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Start of Frame..." << std::endl;

    // Output to Marker to JPG
    outfile << START_OF_FRAME;
}

void processHTable(std::vector<u_int8_t>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Huffman Table..." << std::endl;

    // Output to Marker to JPG
    outfile << HUFFMAN_TABLE;
}

void processSOS(std::vector<u_int8_t>& data, int* position, std::ofstream& outfile) {
    std::cout << "DEBUG MESSAGE: Processing Start of Scan..." << std::endl;

    // Output to Marker to JPG
    outfile << START_OF_SCAN;
}

u_int8_t read_int8(std::vector<u_int8_t>& data, int* position) {
    u_int8_t temp = (data.at(*position) & 0xff);
    *position += SIZE_OF_U8INT;
    return temp;
}