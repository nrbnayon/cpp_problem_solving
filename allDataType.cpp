#include <iostream>
#include <string>
#include <vector>
#include <array>
using namespace std;

int main() {
    cout << "=== C++ DATA TYPES ===\n\n";
    
    // 1. INTEGER TYPES
    cout << "1. INTEGER TYPES:\n";
    int a = 10;                    // 4 bytes, -2^31 to 2^31-1
    short b = 100;                 // 2 bytes, -32768 to 32767
    long c = 100000L;              // 4 or 8 bytes
    long long d = 9999999999LL;    // 8 bytes
    
    cout << "int: " << a << " (size: " << sizeof(a) << " bytes)\n";
    cout << "short: " << b << " (size: " << sizeof(b) << " bytes)\n";
    cout << "long: " << c << " (size: " << sizeof(c) << " bytes)\n";
    cout << "long long: " << d << " (size: " << sizeof(d) << " bytes)\n\n";
    
    // 2. UNSIGNED INTEGER TYPES
    cout << "2. UNSIGNED INTEGER TYPES:\n";
    unsigned int ua = 50;
    unsigned short ub = 200;
    unsigned long uc = 300000UL;
    unsigned long long ud = 10000000000ULL;
    
    cout << "unsigned int: " << ua << "\n";
    cout << "unsigned short: " << ub << "\n";
    cout << "unsigned long: " << uc << "\n";
    cout << "unsigned long long: " << ud << "\n\n";
    
    // 3. CHARACTER TYPES
    cout << "3. CHARACTER TYPES:\n";
    char ch = 'A';                 // 1 byte
    signed char sch = -50;         // 1 byte, -128 to 127
    unsigned char uch = 200;       // 1 byte, 0 to 255
    wchar_t wch = L'Ω';           // Wide character (2 or 4 bytes)
    
    cout << "char: " << ch << " (ASCII: " << (int)ch << ")\n";
    cout << "signed char: " << (int)sch << "\n";
    cout << "unsigned char: " << (int)uch << "\n";
    cout << "wchar_t: " << (int)wch << "\n\n";
    
    // 4. FLOATING POINT TYPES
    cout << "4. FLOATING POINT TYPES:\n";
    float f = 3.14159f;            // 4 bytes, ~7 decimal digits
    double dbl = 3.141592653589;   // 8 bytes, ~15 decimal digits
    long double ldbl = 3.14159265358979323846L; // 12 or 16 bytes
    
    cout << "float: " << f << " (size: " << sizeof(f) << " bytes)\n";
    cout << "double: " << dbl << " (size: " << sizeof(dbl) << " bytes)\n";
    cout << "long double: " << ldbl << " (size: " << sizeof(ldbl) << " bytes)\n\n";
    
    // 5. BOOLEAN TYPE
    cout << "5. BOOLEAN TYPE:\n";
    bool isTrue = true;            // 1 byte, true or false
    bool isFalse = false;
    
    cout << "bool true: " << isTrue << "\n";
    cout << "bool false: " << isFalse << "\n\n";
    
    // 6. VOID TYPE
    cout << "6. VOID TYPE:\n";
    cout << "void - represents absence of type (used in functions)\n\n";
    
    // 7. STRING TYPE
    cout << "7. STRING TYPE:\n";
    string str = "Hello, World!";  // Standard library string
    char str_array[] = "C-style";  // C-style string (char array)
    
    cout << "string: " << str << "\n";
    cout << "char array: " << str_array << "\n\n";
    
    // 8. POINTER TYPES
    cout << "8. POINTER TYPES:\n";
    int num = 42;
    int* ptr = &num;               // Pointer to int
    
    cout << "int value: " << num << "\n";
    cout << "pointer address: " << ptr << "\n";
    cout << "pointer value: " << *ptr << "\n\n";
    
    // 9. REFERENCE TYPES
    cout << "9. REFERENCE TYPES:\n";
    int original = 100;
    int& ref = original;           // Reference to int
    
    cout << "original: " << original << "\n";
    cout << "reference: " << ref << "\n";
    ref = 200;
    cout << "after changing ref, original: " << original << "\n\n";
    
    // 10. ARRAY TYPES
    cout << "10. ARRAY TYPES:\n";
    int arr[5] = {1, 2, 3, 4, 5};  // C-style array
    array<int, 3> stdArr = {10, 20, 30}; // STL array
    
    cout << "C-style array: ";
    for(int i = 0; i < 5; i++) cout << arr[i] << " ";
    cout << "\nSTL array: ";
    for(int val : stdArr) cout << val << " ";
    cout << "\n\n";
    
    // 11. VECTOR (DYNAMIC ARRAY)
    cout << "11. VECTOR (DYNAMIC ARRAY):\n";
    vector<int> vec = {5, 10, 15, 20};
    vec.push_back(25);
    
    cout << "vector: ";
    for(int val : vec) cout << val << " ";
    cout << "\n\n";
    
    // 12. ENUM TYPE
    cout << "12. ENUM TYPE:\n";
    enum Color {RED, GREEN, BLUE};
    Color myColor = GREEN;
    
    cout << "enum Color: " << myColor << " (GREEN)\n\n";
    
    // 13. STRUCT TYPE
    cout << "13. STRUCT TYPE:\n";
    struct Person {
        string name;
        int age;
    };
    Person p = {"John", 25};
    
    cout << "struct Person: " << p.name << ", " << p.age << " years old\n\n";
    
    // 14. AUTO TYPE (C++11)
    cout << "14. AUTO TYPE (C++11):\n";
    auto autoInt = 42;             // Automatically deduced as int
    auto autoDouble = 3.14;        // Automatically deduced as double
    auto autoStr = "Hello";        // Automatically deduced as const char*
    
    cout << "auto int: " << autoInt << "\n";
    cout << "auto double: " << autoDouble << "\n";
    cout << "auto string: " << autoStr << "\n\n";
    
    // 15. NULLPTR TYPE (C++11)
    cout << "15. NULLPTR TYPE (C++11):\n";
    int* nullPtr = nullptr;        // Null pointer
    cout << "nullptr: " << nullPtr << "\n\n";
    
    // SIZE TABLE
    cout << "=== SIZE TABLE ===\n";
    cout << "char: " << sizeof(char) << " byte(s)\n";
    cout << "short: " << sizeof(short) << " byte(s)\n";
    cout << "int: " << sizeof(int) << " byte(s)\n";
    cout << "long: " << sizeof(long) << " byte(s)\n";
    cout << "long long: " << sizeof(long long) << " byte(s)\n";
    cout << "float: " << sizeof(float) << " byte(s)\n";
    cout << "double: " << sizeof(double) << " byte(s)\n";
    cout << "long double: " << sizeof(long double) << " byte(s)\n";
    cout << "bool: " << sizeof(bool) << " byte(s)\n";
    cout << "pointer: " << sizeof(void*) << " byte(s)\n";
    
    return 0;
}