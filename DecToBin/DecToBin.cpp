#include <iostream>
#include <string>
using namespace std;

// Function Prototypes
int getUserInput();
void convertToBinary(int, string&);
void printOutput(int, string&);

int main() {
    int decimal {0};
    string binary {};

    while(1) {
        decimal = getUserInput();
        convertToBinary(decimal, binary);
        printOutput(decimal, binary);
    }
    
    return 0;
}

int getUserInput() {
    int temp {0};
    cout << "Enter a Decimal to Convert to Binary (-1 to exit): ";
    cin >> temp;
    return temp;
}

void convertToBinary(int d, string& s) {
    // Account for 0
    if (d == 0) {
        s.push_back('0');
        return;
    }

    // Repeated division by 2 appending result to string
    string temp {};
    for (int i = d; i != 1; i /= 2) {
        if (i % 2)
            temp.push_back('1');
        else
            temp.push_back('0');
    }
    // Account for first digit always being 1
    temp.push_back('1');

    // Reverse string for output
    for (unsigned int i{0}; i < temp.length(); ++i) {
        s.push_back(temp.at(temp.length() - i - 1));
    }
}

void printOutput(int d, string& s) {
    cout << d << " in binary is " << s << endl;
    s = {};
}