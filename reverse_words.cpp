#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int main() {
    string text = "Text with multiple words";
    vector<string> words;
    stringstream ss(text);
    string word;
    
    while (ss >> word) {
        words.push_back(word);
    }
    
    for (int i = words.size() - 1; i >= 0; i--) {
        cout << words[i];
        if (i > 0) cout << " ";
    }
    
    return 0;
}

// Here's the easy explanation with pseudocode:

// ## Easy Explanation

// The algorithm works in 3 simple steps:

// 1. **Split the text into words** - Read each word separated by spaces
// 2. **Store words in a list** - Keep all words in order
// 3. **Print backwards** - Start from the last word and go to the first

// ## Pseudocode

// ```
// ALGORITHM ReverseWords

// INPUT: text = "Hello World Example"

// STEP 1: Create empty list called 'words'

// STEP 2: Split text by spaces and store in 'words'
//     words = ["Hello", "World", "Example"]

// STEP 3: Loop from last index to first index
//     FOR i = length(words) - 1 DOWN TO 0:
//         PRINT words[i]
//         IF i > 0:
//             PRINT space
//         END IF
//     END FOR

// OUTPUT: "Example World Hello"

// END ALGORITHM
// ```

// ## Detailed Pseudocode

// ```
// BEGIN
//     DECLARE text = "Text with multiple words"
//     DECLARE words as empty list
//     DECLARE word as string
    
//     // Step 1: Split text into words
//     FOR each word in text separated by spaces:
//         ADD word to words list
//     END FOR
    
//     // Now words = ["Text", "with", "multiple", "words"]
    
//     // Step 2: Print in reverse order
//     FOR i = size of words - 1 DOWN TO 0:
//         PRINT words[i]
//         IF i is not 0:
//             PRINT " "  // Add space between words
//         END IF
//     END FOR
    
//     // Output: "words multiple with Text"
// END
// ```

// ## Example Walkthrough

// ```
// Input: "Hello World"

// After splitting:
// words[0] = "Hello"
// words[1] = "World"

// Reverse loop (i goes from 1 to 0):
// i = 1: Print "World"
// i = 0: Print " Hello"

// Output: "World Hello"
// ```

// That's it! Just split, store, and print backwards.



// Pseudocode
// FUNCTION reverseWords(text):
//     CREATE empty stack
    
//     // Step 1: Split string and push to stack
//     FOR each word in text (split by spaces):
//         stack.push(word)
//     END FOR
    
//     // Step 2: Pop from stack to get reversed order
//     result = ""
//     WHILE stack is not empty:
//         result = result + stack.pop()
//         IF stack is not empty:
//             result = result + " "  // Add space between words
//         END IF
//     END WHILE
    
//     RETURN result
// END FUNCTION

// // Example:
// Input: "Hello World Test"
// Stack after pushing: [Hello, World, Test]  (Test on top)
// Popping order: Test -> World -> Hello
// Output: "Test World Hello"



// using js
// function reverseWords(str) {
//   return str.trim().split(/\s+/).reverse().join(' ');
// }
// console.log(reverseWords("Hello world from JavaScript"));
