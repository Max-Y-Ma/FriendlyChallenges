#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

// Function Prototypes
void getUserInput(string&);
bool checkMethod1(string&);
bool checkMethod2(string&);
void displayPalindrom(string&, bool);
string lowerNoSpace(string&);

int main() { 
    string user_input {};
    getUserInput(user_input);
    cout << "Method 1: " << endl;
    displayPalindrom(user_input, checkMethod1(user_input));
    cout << "Method 2: " << endl;
    displayPalindrom(user_input, checkMethod2(user_input));
    return 0;
}

void getUserInput(string& s) {
    cout << "Enter a Palindrome: ";
    getline(cin, s);

    cout << "\n";
    cout << "You entered: " << s << endl;
}

bool checkMethod1(string& s) {
    string temp {};
    string lower {};

    lower = lowerNoSpace(s);

    // Iterate in Reverse Order
    for (string::iterator it = lower.end() - 1; it != lower.begin() - 1; it--) {
        temp.push_back(*it);
    }

    if(equal(lower.begin(), lower.end(), temp.begin()))
        return true;
    else
        return false;
}

string lowerNoSpace(string& s) {
    string temp{};
    // Convert to Lowercase and Remove Spaces
    for (string::iterator it = s.begin(); it != s.end(); it++) {
        if (*it == ' ' )
            continue;
        temp.push_back(tolower(*it));
    }

    return temp;
}

bool checkMethod2(string& s) {
    char* left;
    char* right;
    string temp = lowerNoSpace(s);
    if (temp.length() % 2 == 0) {   // Even Length
        left = &(temp.at((temp.length()/2) - 1));
	right = left + 1;
    }
    else {    // Odd Length
        left = &(temp.at((temp.length()/2) - 1));
        right = left + 2;
    }

    // Compare
    for (long unsigned int i{0}; i < temp.length()/2; i++) {
        if (tolower(*left) != tolower(*right))
            return false;
    }
    return true;
}

void displayPalindrom(string& s, bool flag) {
    if (flag)
        cout << s << " is a Palindrom!" << endl;
    else
        cout << s << " is NOT a Palindrom!" << endl;
}
