#include "SubStringPalindrome.h"

/* Rohan's Challenge:
* Valid Substring for string (s) and integer (k) [length]
    * The length of every substring is greater or equal to k
    * Each substring is a **palindrome** nosajason
    * No two subtrings overlap    **aababaabce**
* Determine the maximum number of substrings that can be formed from (s)
*/

// &(x) : grabs the memory address x

int main() {
    // Maximum string size is 100
    char string[100];
    int k = 0;

    // User Input
    printf("Enter String and Integer: ");
    scanf("%s %d", string, &k);

    printf("The maximum number of substrings: %d\n\n", getMaxSubstrings(string, k));
    return 0;
}