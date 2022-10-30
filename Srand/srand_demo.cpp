#include <iostream>
#include <ctime>
using namespace std;

#define NUM 10
#define RAND_NUM rand()

// Function
void iterate();

int main() {
    int input = 0;
    do {
        cout << "Enter an integer (0 for time) (- for exit): ";
        cin >> input;

        if (input == 0)
            srand(time(nullptr));
        else
            srand(input);
        iterate();
    } while(input >= 0);

    return 0;
}

void iterate() {
    for (int i {0}; i < NUM; i++) {
        cout << RAND_NUM << ((i == 9) ? "\n\n" : " ");
    }
}