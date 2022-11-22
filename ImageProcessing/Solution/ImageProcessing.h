#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

// Includes
#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <bitset>

// Defines
#define START_OF_IMAGE          0xFFD8
#define APPLICATION_0           0xFFE0
#define QUANTIZATION_TABLE      0xFFDB
#define START_OF_FRAME          0xFFC0
#define HUFFMAN_TABLE           0xFFC4
#define START_OF_SCAN           0xFFDA
#define END_OF_IMAGE            0xFFD9
#define SIZE_OF_MARKER          0x0002
#define SIZE_OF_U8INT           0x0001
#define SIZE_OF_U16INT          0x0002
#define SIZE_OF_U32INT          0x0004
#define BYTE                    0x0008

// Datatypes
struct {
    u_int16_t   length;
    u_int32_t   id_1;
    u_int8_t    id_2;
    u_int16_t   version;
    u_int8_t    units;
    u_int32_t   density;
    u_int16_t   thumbnail;
} typedef application_0;

struct {
    u_int16_t           length;
    u_int8_t            destination;
    u_int8_t            table[8][8];
} typedef quantization_table;

struct {
    u_int16_t           length;
    u_int16_t           precision;
    u_int16_t           line_nb;
    u_int8_t            samples;
    u_int8_t            components;
    u_int8_t            id_1;
    u_int8_t            factor_1;
    u_int8_t            table_1;
    u_int8_t            id_2;
    u_int8_t            factor_2;
    u_int8_t            table_2;
    u_int8_t            id_3;
    u_int8_t            factor_3;
    u_int8_t            table_3;
} typedef start_of_frame;

struct {
    u_int16_t           length;
    u_int8_t            class_destination;
    u_int8_t            table[32] ;
} typedef huffman_table;

struct {
    u_int16_t           length;
    u_int8_t            components;
    u_int8_t            table[16];
    u_int8_t            data[64];
} typedef start_of_scan;

// Function Prototypes
void printNum(int n);
void processImage(char* file);
void processSOI(std::vector<char>& data, int* position, std::ofstream& outfile);
void processApp(std::vector<char>& data, int* position, std::ofstream& outfile);
void processQuantTable(std::vector<char>& data, int* position, std::ofstream& outfile);
void processSOF(std::vector<char>& data, int* position, std::ofstream& outfile);
void processHTable(std::vector<char>& data, int* position, std::ofstream& outfile);
void processSOS(std::vector<char>& data, int* position, std::ofstream& outfile);
uint8_t read_int8(std::vector<char>& data, int* position);
uint16_t read_int16(std::vector<char>& data, int* position);
uint32_t read_int32(std::vector<char>& data, int* position);

#endif