#include <iostream>
#include <vector>
using namespace std;

int main(){

    int n;
    cout << "Enter number of shorted array :: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " sorted elements: ";
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    cout << "Original array :: ";
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    if(n == 0){
        cout << "Array is empty:: " << endl;
        return 0;
    }

    int uniqueIndex = 0;

    for (int i = 1; i < n; i++){
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