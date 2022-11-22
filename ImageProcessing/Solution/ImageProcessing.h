#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

// Includes
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>

// Defines
#define START_OF_IMAGE          0xFFD8
#define APPLICATION_0           0xFFE0
#define QUANTIZATION_TABLE      0xFFDB
#define START_OF_FRAME          0xFFC0
#define HUFFMAN_TABLE           0xFFC4
#define START_OF_SCAN           0xFFDA
#define END_OF_IMAGE            0xFFD9
#define SIZE_OF_MARKER          0x0002
#define SIZE_OF_LENGTH          0x0002
#define BYTE                    0x0008

// Function Prototypes
void printNum(int n);
void processImage(char* file);
uint32_t getMarker(std::vector<int>& data, int* position);
void processSOI(std::vector<int>& data, int* position, std::ofstream& outfile);
void processApp(std::vector<int>& data, int* position, std::ofstream& outfile);
void processQuantTable(std::vector<int>& data, int* position, std::ofstream& outfile);
void processSOF(std::vector<int>& data, int* position, std::ofstream& outfile);
void processHTable(std::vector<int>& data, int* position, std::ofstream& outfile);
void processSOS(std::vector<int>& data, int* position, std::ofstream& outfile);

#endif