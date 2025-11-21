// --- square ----
// *****
// *****
// *****
// *****
// *****

#include <iostream>
#include <string>
using namespace std;

// int main(){
//     int n = 5;

//     for (int i = 0; i < n; i++){
//         for (int j = 0; j < n; j++){
//             cout << "* ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// --- Increasing Triangle Pattern ----
// * 
// * *
// * * *
// * * * *
// * * * * *

// int main(){
//     int n = 5;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j <= i; j++){
//             cout << "* ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// --- Decreasing Triangle Pattern ----
// * * * * * 
// * * * *
// * * *
// * *
// *
// int main(){
//     int n = 5;
//     for (int i = 0; i < n; i++){
//         for (int j = i; j < n; j++){
//             cout << "* ";
//         }
//         cout << "\n";
//     }
//     return 0;
// }

// --- Right Sided Triangle Pattern ----
//          *
//        * *
//      * * *
//    * * * *
//  * * * * *
// int main() {
//     int n = 5;

//     for (int i = 0; i < n; i++) {

//         // print spaces
//         for (int j = 0; j < n - i - 1; j++) {
//             cout << "  ";
//         }

//         // print stars
//         for (int j = 0; j <= i; j++) {
//             cout << " *";
//         }

//         cout << "\n";
//     }

//     return 0;
// }

//   * * * * * 
//     * * * *
//       * * *
//         * *
//           *
// int main(){
//     int n = 5;
//     for (int i = 0; i < n; i++){
//         for (int j = 0; j <= i; j++){
//             cout << "  ";
//         }
//         for (int j = i; j < n; j++){
//             cout << "* ";
//         }
        
//         cout << "\n";
//     }
// }

// ------Hill pattern --------
//         * 
//       * * *
//     * * * * *
//   * * * * * * *
// * * * * * * * * *

// int main() {
//     int n = 5;

//     for (int i = 0; i < n; i++) {

//         // print spaces
//         for (int j = 0; j < n - i - 1; j++) {
//             cout << "  ";
//         }

//         // left side stars
//         for (int j = 0; j <= i; j++) {
//             cout << "* ";
//         }

//         // right side stars
//         for (int j = 0; j < i; j++) {
//             cout << "* ";
//         }

//         cout << "\n";
//     }

//     return 0;
// }