#include <iostream>
#include <vector>
using namespace std;

#define START 0

// Function Prototypes
void getUserInput(string&);
void createPermutations(vector<string>&, string, int, int);
void sortPermutations(vector<string>&, unsigned long int);
void removeDup(vector<string>&);
void vecSwap(vector<string>&, int, int);
void printPermutations(vector<string>&);
string findAnswer(vector<string>&, string&);

int main() {
    while (1) {
        vector<string> word_permutations {};
        string word {};

        getUserInput(word);
        createPermutations(word_permutations, word, START, word.length() - 1);\
        sortPermutations(word_permutations, START);
        removeDup(word_permutations);
        printPermutations(word_permutations);

        cout << "Answer is: " << findAnswer(word_permutations, word) << "\n" << endl;
    }

    return 0;
}

void getUserInput(string& s) {
    cout << "Enter a String: ";
    getline(cin, s);
}

void createPermutations(vector<string>& v, string s, int start, int end) {
    // Base Case #1: No more swaps
    if (start == end) {
        v.push_back(s);
    }

    // Permuate the next substring
    else {
        for (int i = start; i <= end; i++) {
            // Swap
            std::swap(s[start], s[i]);

            // Recursive Call
            createPermutations(v, s, start + 1, end);

            // Back Track
            std::swap(s[start], s[i]);
        }
    }
}

void sortPermutations(vector<string>& v, unsigned long int count) {
    // Base Case
    if (count == v.size() - 1) {
        return;
    }

    // Sort + Recursive Call
    for (unsigned long int i {0}; i < v.size() - 1; i++) {
        if ((v.at(i)).compare(v.at(i+1)) > 0) {
            vecSwap(v, i, i+1);
        }
    }
    sortPermutations(v, count + 1);
}

void removeDup(vector<string>& v) {
    for (unsigned long int i {0}; i < v.size() - 1; i++) {
        if ((v.at(i)).compare(v.at(i+1)) == 0) {
            v.erase(v.begin()+i);
        }
    }
}

void vecSwap(vector<string>& v, int a, int b) {
    string temp = v.at(a);
    v.at(a) = v.at(b);
    v.at(b) = temp;
}

void printPermutations(vector<string>& v) {
    for (auto element : v) {
        cout << element << endl;
    }
}

string findAnswer(vector<string>& v, string& s) {
    for (unsigned long int i {0}; i < v.size() - 1; i++) {
        if ((v.at(i)).compare(s) == 0) {
            return v.at(i+1);
        }
    }
    return v.at(v.size()-1);
}