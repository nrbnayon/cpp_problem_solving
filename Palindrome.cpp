// (String Palindrome Check)
#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    bool isPalindrome = true;
    int n = str.length();

    for (int i = 0; i < n / 2; i++) {
        if (str[i] != str[n - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}


// Example for Numbers 
#include <iostream>
using namespace std;

int main() {
    int num, originalNum, reversedNum = 0, remainder;

    cout << "Enter a number: ";
    cin >> num;

    originalNum = num;

    while (num != 0) {
        remainder = num % 10;
        reversedNum = reversedNum * 10 + remainder;
        num /= 10;
    }

    if (originalNum == reversedNum)
        cout << "Palindrome Number" << endl;
    else
        cout << "Not Palindrome Number" << endl;

    return 0;
}


// 🧩 Pseudo Code for String Palindrome

START
  INPUT text
  SET length = length of text
  SET isPalindrome = true

  FOR i = 0 TO (length / 2) - 1
      IF text[i] != text[length - i - 1] THEN
          isPalindrome = false
          BREAK
      END IF
  END FOR

  IF isPalindrome == true THEN
      PRINT "Palindrome"
  ELSE
      PRINT "Not Palindrome"
  END IF
END



// ALL Types palindrome 

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

// 1. Check if a string is palindrome (case-insensitive, ignoring spaces)
bool isPalindrome(string s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++;
        right--;
    }
    return true;
}

// 2. Check if a number is palindrome
bool isPalindromeNumber(int n) {
    if (n < 0) return false;
    int original = n, reversed = 0;
    while (n > 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return original == reversed;
}

// 3. Longest Palindromic Substring (Expand Around Center - O(n^2))
string longestPalindrome(string s) {
    if (s.empty()) return "";
    int start = 0, maxLen = 1;
    
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        int len = right - left - 1;
        if (len > maxLen) {
            maxLen = len;
            start = left + 1;
        }
    };
    
    for (int i = 0; i < s.length(); i++) {
        expandAroundCenter(i, i);     // odd length
        expandAroundCenter(i, i + 1); // even length
    }
    return s.substr(start, maxLen);
}

// 4. Count Palindromic Substrings
int countPalindromicSubstrings(string s) {
    int count = 0;
    auto expandAroundCenter = [&](int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
    };
    
    for (int i = 0; i < s.length(); i++) {
        expandAroundCenter(i, i);
        expandAroundCenter(i, i + 1);
    }
    return count;
}

// 5. Minimum Insertions to Make Palindrome
int minInsertions(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int len = 2; len <= n; len++) {
        for (int i = 0; i <= n - len; i++) {
            int j = i + len - 1;
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1];
            } else {
                dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
            }
        }
    }
    return dp[0][n - 1];
}

// 6. Longest Palindromic Subsequence (LCS approach)
int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    
    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

// 7. Palindrome Partitioning (All possible partitions)
void partitionHelper(string s, int start, vector<string>& current, vector<vector<string>>& result) {
    if (start == s.length()) {
        result.push_back(current);
        return;
    }
    for (int end = start; end < s.length(); end++) {
        string sub = s.substr(start, end - start + 1);
        if (isPalindrome(sub)) {
            current.push_back(sub);
            partitionHelper(s, end + 1, current, result);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;
    partitionHelper(s, 0, current, result);
    return result;
}

// 8. Minimum Cuts for Palindrome Partitioning
int minCut(string s) {
    int n = s.length();
    vector<vector<bool>> isPalin(n, vector<bool>(n, false));
    vector<int> cuts(n);
    
    for (int i = 0; i < n; i++) {
        cuts[i] = i;
        for (int j = 0; j <= i; j++) {
            if (s[j] == s[i] && (i - j <= 1 || isPalin[j + 1][i - 1])) {
                isPalin[j][i] = true;
                cuts[i] = (j == 0) ? 0 : min(cuts[i], cuts[j - 1] + 1);
            }
        }
    }
    return cuts[n - 1];
}

// 9. Check if string can be rearranged to form palindrome
bool canFormPalindrome(string s) {
    vector<int> freq(256, 0);
    for (char c : s) freq[c]++;
    
    int oddCount = 0;
    for (int f : freq) {
        if (f % 2 != 0) oddCount++;
    }
    return oddCount <= 1;
}

// 10. Shortest Palindrome (Add characters at beginning)
string shortestPalindrome(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    string combined = s + "#" + rev;
    
    // KMP failure function
    int n = combined.length();
    vector<int> lps(n, 0);
    for (int i = 1; i < n; i++) {
        int j = lps[i - 1];
        while (j > 0 && combined[i] != combined[j]) j = lps[j - 1];
        if (combined[i] == combined[j]) j++;
        lps[i] = j;
    }
    
    int charsToAdd = s.length() - lps[n - 1];
    return rev.substr(0, charsToAdd) + s;
}

int main() {
    // Test cases
    cout << "1. Is 'A man a plan a canal Panama' palindrome? " 
         << (isPalindrome("A man a plan a canal Panama") ? "Yes" : "No") << endl;
    
    cout << "2. Is 12321 palindrome number? " 
         << (isPalindromeNumber(12321) ? "Yes" : "No") << endl;
    
    cout << "3. Longest palindrome in 'babad': " 
         << longestPalindrome("babad") << endl;
    
    cout << "4. Count palindromic substrings in 'aaa': " 
         << countPalindromicSubstrings("aaa") << endl;
    
    cout << "5. Min insertions for 'abcd': " 
         << minInsertions("abcd") << endl;
    
    cout << "6. Longest palindromic subsequence in 'bbbab': " 
         << longestPalindromeSubseq("bbbab") << endl;
    
    cout << "7. Min cuts for 'aab': " 
         << minCut("aab") << endl;
    
    cout << "8. Can 'tactcoa' form palindrome? " 
         << (canFormPalindrome("tactcoa") ? "Yes" : "No") << endl;
    
    cout << "9. Shortest palindrome from 'aacecaaa': " 
         << shortestPalindrome("aacecaaa") << endl;
    
    return 0;
}

//
═══════════════════════════════════════════════════════════════════
    PALINDROME ALGORITHMS - COMPLETE PSEUDOCODE COLLECTION
═══════════════════════════════════════════════════════════════════

┌─────────────────────────────────────────────────────────────────┐
│ 1. CHECK IF STRING IS PALINDROME (Two Pointer Approach)        │
│    Time: O(n), Space: O(1)                                      │
└─────────────────────────────────────────────────────────────────┘

ALGORITHM isPalindrome(s)
INPUT: string s
OUTPUT: boolean (true if palindrome, false otherwise)

BEGIN
    left ← 0
    right ← LENGTH(s) - 1
    
    WHILE left < right DO
        // Skip non-alphanumeric from left
        WHILE left < right AND NOT isAlphanumeric(s[left]) DO
            left ← left + 1
        END WHILE
        
        // Skip non-alphanumeric from right
        WHILE left < right AND NOT isAlphanumeric(s[right]) DO
            right ← right - 1
        END WHILE
        
        // Compare characters (case-insensitive)
        IF toLowerCase(s[left]) ≠ toLowerCase(s[right]) THEN
            RETURN false
        END IF
        
        left ← left + 1
        right ← right - 1
    END WHILE
    
    RETURN true
END


┌─────────────────────────────────────────────────────────────────┐
│ 2. CHECK IF NUMBER IS PALINDROME                               │
│    Time: O(log n), Space: O(1)                                  │
└─────────────────────────────────────────────────────────────────┘

ALGORITHM isPalindromeNumber(n)
INPUT: integer n
OUTPUT: boolean

BEGIN
    IF n < 0 THEN
        RETURN false
    END IF
    
    original ← n
    reversed ← 0
    
    WHILE n > 0 DO
        digit ← n MOD 10
        reversed ← reversed × 10 + digit
        n ← n DIV 10
    END WHILE
    
    RETURN (original = reversed)
END


┌─────────────────────────────────────────────────────────────────┐
│ 3. LONGEST PALINDROMIC SUBSTRING (Expand Around Center)        │
│    Time: O(n²), Space: O(1)                                     │
└─────────────────────────────────────────────────────────────────┘

ALGORITHM longestPalindrome(s)
INPUT: string s
OUTPUT: string (longest palindromic substring)

BEGIN
    IF s is empty THEN
        RETURN ""
    END IF
    
    start ← 0
    maxLength ← 1
    n ← LENGTH(s)
    
    PROCEDURE expandAroundCenter(left, right)
    BEGIN
        WHILE left ≥ 0 AND right < n AND s[left] = s[right] DO
            left ← left - 1
            right ← right + 1
        END WHILE
        
        currentLength ← right - left - 1
        
        IF currentLength > maxLength THEN
            maxLength ← currentLength
            start ← left + 1
        END IF
    END PROCEDURE
    
    FOR i ← 0 TO n - 1 DO
        expandAroundCenter(i, i)        // Odd length palindromes
        expandAroundCenter(i, i + 1)    // Even length palindromes
    END FOR
    
    RETURN SUBSTRING(s, start, start + maxLength - 1)
END


┌─────────────────────────────────────────────────────────────────┐
│ 4. COUNT PALINDROMIC SUBSTRINGS                                │
│    Time: O(n²), Space: O(1)                                     │
└─────────────────────────────────────────────────────────────────┘

ALGORITHM countPalindromicSubstrings(s)
INPUT: string s
OUTPUT: integer (count of palindromic substrings)

BEGIN
    count ← 0
    n ← LENGTH(s)
    
    PROCEDURE expandAroundCenter(left, right)
    BEGIN
        WHILE left ≥ 0 AND right < n AND s[left] = s[right] DO
            count ← count + 1
            left ← left - 1
            right ← right + 1
        END WHILE
    END PROCEDURE
    
    FOR i ← 0 TO n - 1 DO
        expandAroundCenter(i, i)        // Odd length
        expandAroundCenter(i, i + 1)    // Even length
    END FOR
    
    RETURN count
END


┌─────────────────────────────────────────────────────────────────┐
│ 5. MINIMUM INSERTIONS TO MAKE PALINDROME                       │
│    Time: O(n²), Space: O(n²)                                    │
└─────────────────────────────────────────────────────────────────┘

ALGORITHM minInsertions(s)
INPUT: string s
OUTPUT: integer (minimum insertions needed)

BEGIN
    n ← LENGTH(s)
    CREATE dp[n][n] ← all zeros
    
    // dp[i][j] = min insertions for substring s[i..j]
    
    FOR length ← 2 TO n DO
        FOR i ← 0 TO n - length DO
            j ← i + length - 1
            
            IF s[i] = s[j] THEN
                dp[i][j] ← dp[i + 1][j - 1]
            ELSE
                dp[i][j] ← MIN(dp[i + 1][j], dp[i][j - 1]) + 1
            END IF
        END FOR
    END FOR
    
    RETURN dp[0][n - 1]
END


┌─────────────────────────────────────────────────────────────────┐
│ 6. LONGEST PALINDROMIC SUBSEQUENCE                             │
│    Time: O(n²), Space: O(n²)                                    │
└─────────────────────────────────────────────────────────────────┘

ALGORITHM longestPalindromeSubseq(s)
INPUT: string s
OUTPUT: integer (length of longest palindromic subsequence)

BEGIN
    n ← LENGTH(s)
    CREATE dp[n][n] ← all zeros
    
    // dp[i][j] = length of LPS in s[i..j]
    
    FOR i ← n - 1 DOWN TO 0 DO
        dp[i][i] ← 1  // Single character is palindrome
        
        FOR j ← i + 1 TO n - 1 DO
            IF s[i] = s[j] THEN
                dp[i][j] ← dp[i + 1][j - 1] + 2
            ELSE
                dp[i][j] ← MAX(dp[i + 1][j], dp[i][j - 1])
            END IF
        END FOR
    END FOR
    
    RETURN dp[0][n - 1]
END


┌─────────────────────────────────────────────────────────────────┐
│ 7. PALINDROME PARTITIONING (All Partitions)                    │
│    Time: O(n × 2^n), Space: O(n)                                │
└─────────────────────────────────────────────────────────────────┘

ALGORITHM palindromePartition(s)
INPUT: string s
OUTPUT: list of all possible palindrome partitions

BEGIN
    result ← empty list
    current ← empty list
    
    PROCEDURE partitionHelper(start)
    BEGIN
        IF start = LENGTH(s) THEN
            ADD COPY(current) to result
            RETURN
        END IF
        
        FOR end ← start TO LENGTH(s) - 1 DO
            substring ← s[start..end]
            
            IF isPalindrome(substring) THEN
                ADD substring to current
                partitionHelper(end + 1)
                REMOVE last element from current  // Backtrack
            END IF
        END FOR
    END PROCEDURE
    
    partitionHelper(0)
    RETURN result
END


┌─────────────────────────────────────────────────────────────────┐
│ 8. MINIMUM CUTS FOR PALINDROME PARTITIONING                    │
│    Time: O(n²), Space: O(n²)                                    │
└─────────────────────────────────────────────────────────────────┘

ALGORITHM minCut(s)
INPUT: string s
OUTPUT: integer (minimum cuts needed)

BEGIN
    n ← LENGTH(s)
    CREATE isPalindrome[n][n] ← all false
    CREATE cuts[n]
    
    FOR i ← 0 TO n - 1 DO
        cuts[i] ← i  // Maximum possible cuts for s[0..i]
        
        FOR j ← 0 TO i DO
            // Check if s[j..i] is palindrome
            condition ← (s[j] = s[i]) AND 
                       (i - j ≤ 1 OR isPalindrome[j + 1][i - 1])
            
            IF condition THEN
                isPalindrome[j][i] ← true
                
                IF j = 0 THEN
                    cuts[i] ← 0  // Entire string is palindrome
                ELSE
                    cuts[i] ← MIN(cuts[i], cuts[j - 1] + 1)
                END IF
            END IF
        END FOR
    END FOR
    
    RETURN cuts[n - 1]
END


┌─────────────────────────────────────────────────────────────────┐
│ 9. CAN STRING BE REARRANGED TO FORM PALINDROME                 │
│    Time: O(n), Space: O(1)                                      │
└─────────────────────────────────────────────────────────────────┘

ALGORITHM canFormPalindrome(s)
INPUT: string s
OUTPUT: boolean

BEGIN
    CREATE frequency[256] ← all zeros  // ASCII characters
    
    // Count character frequencies
    FOR each character c in s DO
        frequency[c] ← frequency[c] + 1
    END FOR
    
    oddCount ← 0
    
    // Count characters with odd frequency
    FOR i ← 0 TO 255 DO
        IF frequency[i] MOD 2 ≠ 0 THEN
            oddCount ← oddCount + 1
        END IF
    END FOR
    
    // At most one character can have odd frequency
    RETURN (oddCount ≤ 1)
END


┌─────────────────────────────────────────────────────────────────┐
│ 10. SHORTEST PALINDROME (KMP Algorithm)                        │
│     Time: O(n), Space: O(n)                                     │
└─────────────────────────────────────────────────────────────────┘

ALGORITHM shortestPalindrome(s)
INPUT: string s
OUTPUT: string (shortest palindrome by adding prefix)

BEGIN
    reversed ← REVERSE(s)
    combined ← s + "#" + reversed
    n ← LENGTH(combined)
    
    // Build KMP failure function (Longest Prefix Suffix array)
    CREATE lps[n] ← all zeros
    
    FOR i ← 1 TO n - 1 DO
        j ← lps[i - 1]
        
        WHILE j > 0 AND combined[i] ≠ combined[j] DO
            j ← lps[j - 1]
        END WHILE
        
        IF combined[i] = combined[j] THEN
            j ← j + 1
        END IF
        
        lps[i] ← j
    END FOR
    
    // Characters to add = original length - matched prefix length
    charsToAdd ← LENGTH(s) - lps[n - 1]
    prefix ← SUBSTRING(reversed, 0, charsToAdd - 1)
    
    RETURN prefix + s
END


═══════════════════════════════════════════════════════════════════
                    COMPLEXITY SUMMARY TABLE
═══════════════════════════════════════════════════════════════════

Algorithm                        Time         Space
────────────────────────────────────────────────────────────────
1. isPalindrome                  O(n)         O(1)
2. isPalindromeNumber            O(log n)     O(1)
3. longestPalindrome             O(n²)        O(1)
4. countPalindromicSubstrings    O(n²)        O(1)
5. minInsertions                 O(n²)        O(n²)
6. longestPalindromeSubseq       O(n²)        O(n²)
7. palindromePartition           O(n×2ⁿ)      O(n)
8. minCut                        O(n²)        O(n²)
9. canFormPalindrome             O(n)         O(1)
10. shortestPalindrome           O(n)         O(n)
════════════════════════════════════════════════════════════════════