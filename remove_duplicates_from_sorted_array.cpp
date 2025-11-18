#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of sorted array: ";
    cin >> n;
    
   vector<int> arr(n); // int arr[n];
    cout << "Enter " << n << " sorted elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Remove duplicates using two pointers
    if(n == 0){
        cout << "Array is empty" << endl;
        return 0;
    }
    
    int uniqueIndex = 0;
    
    for(int i = 1; i < n; i++){
        if(arr[i] != arr[uniqueIndex]){
            uniqueIndex++;
            arr[uniqueIndex] = arr[i];
        }
    }
    
    int newSize = uniqueIndex + 1;
    
    cout << "Array after removing duplicates: ";
    for(int i = 0; i < newSize; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "New size: " << newSize << endl;
    
    return 0;
}

/*
PSEUDOCODE:
-----------
START
    INPUT n (size of sorted array)
    DECLARE array of size n
    
    INPUT n sorted elements into array
    
    IF n == 0 THEN
        PRINT "Array is empty"
        EXIT
    END IF
    
    SET uniqueIndex = 0
    
    FOR i = 1 to n-1 DO
        IF array[i] != array[uniqueIndex] THEN
            INCREMENT uniqueIndex
            SET array[uniqueIndex] = array[i]
        END IF
    END FOR
    
    SET newSize = uniqueIndex + 1
    
    PRINT array from index 0 to newSize-1
    PRINT newSize
END

Time Complexity: O(n)
Space Complexity: O(1) - in-place removal

Example:
Input:  [1, 1, 2, 2, 3, 4, 4, 5]
Output: [1, 2, 3, 4, 5]
*/