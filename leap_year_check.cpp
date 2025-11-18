#include <iostream>
using namespace std;

int main(){
    int year;
    cout << "Enter year :: ";
    cin >> year; 

    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        cout << "This is a leap year" << endl;
    }else {
        cout << "This is not a leap year" << endl;
    }
    
    return 0;
}


// Easy Pseudocode

// START
//     INPUT year
    
//     IF year is divisible by 400 THEN
//         PRINT "Leap year"
//     ELSE IF year is divisible by 100 THEN
//         PRINT "Not a leap year"
//     ELSE IF year is divisible by 4 THEN
//         PRINT "Leap year"
//     ELSE
//         PRINT "Not a leap year"
//     END IF
    
// END