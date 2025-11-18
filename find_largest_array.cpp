#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int arraySize;
    cout << "Enter the size of array :: ";
    cin >> arraySize;

    vector<int> arr(arraySize);  

    cout << "Enter " << arraySize << " Elements:: ";

    for (int i = 0; i < arraySize; i++) {
        cin >> arr[i];
    }

    int largest = INT_MIN;
    for (int i = 0; i < arraySize; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    cout << "Largest element :: " << largest << endl;

    return 0;
}


/*
PSEUDOCODE:
-----------
START
    INPUT n (size of array)
    DECLARE array of size n
    
    INPUT n elements into array
    
    SET largest = first element of array
    
    FOR i = 1 to n-1 DO
        IF array[i] > largest THEN
            SET largest = array[i]
        END IF
    END FOR
    
    PRINT largest
END

Time Complexity: O(n)
Space Complexity: O(1)
*/

// --Minimum array find

// #include <iostream>
// #include <vector>
// #include <climits>
// using namespace std;

// int main() {
//     int arraySize;
//     cout << "Enter the size of array :: ";
//     cin >> arraySize;

//     vector<int> arr(arraySize);

//     cout << "Enter " << arraySize << " Elements ";

//     for (int i = 0; i < arraySize; i++) {
//         cin >> arr[i];
//     }

//     // Find smallest element
//     int smallest = INT_MAX;
//     for (int i = 0; i < arraySize; i++) {
//         if (arr[i] < smallest) {
//             smallest = arr[i];
//         }
//     }

//     cout << "Smallest element :: " << smallest << endl;

//     return 0;
// }

// Time Complexity: O(n)
// Space Complexity: O(1)