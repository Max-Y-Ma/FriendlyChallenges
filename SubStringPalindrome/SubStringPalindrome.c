#include "SubStringPalindrome.h"

/* Rohan's Challenge:
* Valid Substring for string (s) and integer (k)
    * The length of every substring is greater or equal to k
    * Each substring is a palindrome
    * No two subtrings overlap
* Determine the maximum number of substrings that can be formed from (s)
*/

#define LENGTH (*(&s + 1) - s)

int getMaxSubstrings(char* s, int k) {
    // Static Variables
    static int num, count, tempe, tempo = 0;

    // Base Case
    if (*s == '\0')
        return num;

    // Check Palindromes
    tempe = 0;
    tempo = 0;
    for (int i = 0; i <= count; i++) {
        // Check Opposing Sides (ODD)
        if (*(s-i) == *(s+i)) {
            tempe = 2*i + 1;
        }
        else {
            break;
        }
    }

    for (int i = 0; i <= count; i++) {
        // Check Left and Right Sides (EVEN)
        if (*(s-i) == *(s+i+1)) {
            tempo = 2*i + 2;
        }
        else {
            break;
        }
    }

    // Valid Palindrome
    if (tempe >= k) {
        num++;
        // Print Substring
        for (int j = -(tempe/2); j <= tempe/2; j++) {
            printf("%c", *(s+j));
        }
        printf("\n");
    }
    if (tempo >= k) {
        num++;
        // Print Substring
        for (int j = -(tempo/2 - 1); j <= tempo/2; j++) {
            printf("%c", *(s+j));
        }
        printf("\n");
    }

    // Recursive Case
    if (count + 1 == LENGTH - 1)
        count = count;
    else if (count + 1 == LENGTH)
        count--;
    else
        count++;

    return getMaxSubstrings(s + 1, k);
}