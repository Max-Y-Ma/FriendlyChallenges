#include <iostream>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

// Macros
#define RANDOM_NUM (rand()%8 + 1)

// Function Prototypes
void generateMatrix();
void matrixMult(const char*, const char*);
void cleanEnvironment();
void printMatrix(const char*);

int main() {
    generateMatrix();
    matrixMult("matrix1.txt", "matrix2.txt");
    //cleanEnvironment();
    return 0;
}

void generateMatrix() {
    // Initialize random seed
    srand (time(0));

    // Generate Matrix #1: Maximum Size 8x8
    ofstream outfile;
    outfile.open("matrix1.txt");
    // Random Generated Numbers
    int rand1 = RANDOM_NUM, rand2 = RANDOM_NUM, rand3 = RANDOM_NUM;
    outfile << rand1 << ' ' << rand2 << '\n';
    for (int i{0}; i < rand1; i++) {
        for (int j{0}; j < rand2; j++) {
            outfile << RANDOM_NUM << ' ';
        }
        outfile << '\n';
    }
    outfile.close();
    printMatrix("matrix1.txt");

    // Generate Matrix #2: Maximum Size 8x8
    outfile.open("matrix2.txt");
    outfile << rand2 << ' ' << rand3 << '\n';
    for (int i{0}; i < rand2; i++) {
        for (int j{0}; j < rand3; j++) {
            outfile << RANDOM_NUM << ' ';
        }
        outfile << '\n';
    }
    outfile.close();
    printMatrix("matrix2.txt");
}

void matrixMult(const char* matrix1, const char* matrix2) {
    // Input Files
    ifstream infile_matrix1, infile_matrix2;
    infile_matrix1.open(matrix1);
    infile_matrix2.open(matrix2);

    // Output File
    ofstream outfile;
    outfile.open("output.txt");

    // Store Matrix #1
    int length1, length2, temp;
    infile_matrix1 >> length1;
    infile_matrix1 >> length2;
    int matrix_array1[length1][length2];
    for (int i{0}; i < length1; i++) {
        for (int j{0}; j < length2; j++) {
            infile_matrix1 >> temp;
            matrix_array1[i][j] = temp;
        }
    }
    infile_matrix1.close();

    // Store Matrix #2
    int length3;
    infile_matrix2 >> length2;
    infile_matrix2 >> length3;
    int matrix_array2 [length2][length3];
    for (int i{0}; i < length2; i++) {
        for (int j{0}; j < length3; j++) {
            infile_matrix2 >> temp;
            matrix_array2[i][j] = temp;
        }
    }
    infile_matrix2.close();

    // Matrix Multiplication
    outfile << length1 << ' ' << length3 << '\n';
    for (int i{0}; i < length1; i++) {
        for (int j{0}; j < length3; j++) {
            // Calculate Matrix Position
            temp = 0;
            for (int k{0}; k < length2; k++) {
                temp += (matrix_array1[i][k]) * (matrix_array2[k][j]);
            }
            outfile << temp << ' ';
        }
        outfile << '\n';
    }
    outfile.close();

    printMatrix("output.txt");
}

void cleanEnvironment() {
    remove("matrix1.txt");
    remove("matrix2.txt");
}

void printMatrix(const char* name) {
    // Process File
    ifstream infile;
    infile.open(name);

    int length1, length2, tempi;
    infile >> length1;
    infile >> length2;
    cout << name << ": " << endl; 
    for (int i{0}; i < length1; i++) {
        for (int j{0}; j < length2; j++) {
            infile >> tempi;
            cout << tempi << ' ';
        }
        cout << endl;
    }
    cout << endl;
}