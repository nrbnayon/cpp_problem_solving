#include <iostream>
#include <string>
using namespace std;

int main() {
    int number;
    cout << "Enter the number: " << endl;
    cin >> number;

    // Convert number to string for easier manipulation
    string numStr = to_string(number);
    bool isPalindrome = true;
    
    int numberLength = numStr.length();
    
    // Check if the number is a palindrome by comparing the first and last digits
    for (int i = 0; i < numberLength / 2; i++) {
        if (numStr[i] != numStr[numberLength - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    // Output result
    if (isPalindrome) {
        cout << "This is a palindrome" << endl;
    } else {
        cout << "This is not a palindrome" << endl;
    }

    return 0;
}
// function isPalindrome(str) {
//   str = str.toLowerCase().replace(/[^a-z0-9]/g, '');
//   return str === str.split('').reverse().join('');
// }
