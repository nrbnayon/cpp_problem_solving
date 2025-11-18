#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    
    cout << "Original array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // Reverse array in-place using two pointers
    int left = 0;
    int right = n - 1;
    
    while(left < right){
        // Swap elements
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        
        left++;
        right--;
    }
    
    cout << "Reversed array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/*
PSEUDOCODE:
-----------
START
    INPUT n (size of array)
    DECLARE array of size n
    
    INPUT n elements into array
    
    SET left = 0
    SET right = n - 1
    
    WHILE left < right DO
        SWAP array[left] and array[right]
        INCREMENT left
        DECREMENT right
    END WHILE
    
    PRINT reversed array
END

Time Complexity: O(n)
Space Complexity: O(1) - in-place reversal
*/