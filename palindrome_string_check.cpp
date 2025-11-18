#include <iostream>
#include <string>
using namespace std;

int main(){
    string text = "Nayon";
    // cout << "Enter any string text :: ";
    // cin >> text;

    bool isPalindrome = true;
    int n = text.length();

    for (int i = 0; i < n / 2; i++){
        if (text[i] != text[n - i - 1]){
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome){
        cout << "Palindrome" << endl;
    } else {
        cout << "Not Palindrome" << endl;
    }
}

// ------------ Pseudo Code

// START
// INPUT text
//     SET length = length of text
//         SET isPalindrome = true(bool)
        
//         FOR i=0 TO (length / 2) - 1
//             IF text[i] != text[length - i - 1] THEN
//                 isPalindrome = false
//                 BREAK
//             END IF
//         END FOR

//     IF isPalindrome == true THEN
//         PRINT "Palindrome"
//     ELSE
//         PRINT "Not Palindrome"
//     END IF
// END



// ALGORITHM isPalindrome(s)
// INPUT: string s
// OUTPUT: boolean (true if palindrome, false otherwise)

// BEGIN
//     left ← 0
//     right ← LENGTH(s) - 1
    
//     WHILE left < right DO
//         // Skip non-alphanumeric from left
//         WHILE left < right AND NOT isAlphanumeric(s[left]) DO
//             left ← left + 1
//         END WHILE
        
//         // Skip non-alphanumeric from right
//         WHILE left < right AND NOT isAlphanumeric(s[right]) DO
//             right ← right - 1
//         END WHILE
        
//         // Compare characters (case-insensitive)
//         IF toLowerCase(s[left]) ≠ toLowerCase(s[right]) THEN
//             RETURN false
//         END IF
        
//         left ← left + 1
//         right ← right - 1
//     END WHILE
    
//     RETURN true
// END
