#include <iostream>
using namespace std;


int main(){
    int number, originalNumber, reversedNumber = 0, remainder;

    cout << "Enter a number :: " << endl;
    cin >> number;
    originalNumber = number;

    while(number !=0 ){
        remainder = number % 10;
        reversedNumber = reversedNumber * 10 + remainder;
        number = number / 10;
 // number /= 10; // number = 1 / 10 = 0   → loop stops
    }
// Takes the last digit (% 10)

// Adds that digit to the back of reversedNumber

// Removes the last digit from the original number (/ 10)

// Repeats until nothing is left

    if (originalNumber == reversedNumber)
        cout << "Palindrome Number" << endl;
    else
        cout << "Not Palindrome Number" << endl;

    return 0;
}


// ALGORITHM isPalindromeNumber(n)
// INPUT: integer n
// OUTPUT: boolean

// BEGIN
//     IF n < 0 THEN
//         RETURN false
//     END IF
    
//     original ← n
//     reversed ← 0
    
//     WHILE n > 0 DO
//         digit ← n MOD 10
//         reversed ← reversed × 10 + digit
//         n ← n DIV 10
//     END WHILE
    
//     RETURN (original = reversed)
// END