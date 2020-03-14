#include <bits/stdc++.h>
using namespace std;

void printStr(string& s) {
    cout << "X" << s << "X" << endl;
}

void removeDup1(string& s) {
    bool duplicateFound = false;
    int len = s.size();
    do {
        int i = 0;
        int j = i;
        duplicateFound = false;
        while (j < len) {
            int k = j + 1;
            while (k < len && s[j] == s[k]) {
                ++k;
            }
            if (j == k - 1) {
                swap(s[i], s[j]);
                ++i;
            }
            else {
                duplicateFound = true;
            }
            j = k;
        }
        len = i+1;
    } while (duplicateFound);
}



// This function recursively removes duplicates
// and returns modified string
char* removeDup(char * str, int n)
{
    int len = strlen(str);
    int k = 0; // To store index of result
 
    // Start from second character and add
    // unique ones
    int i;
    for (i=1; i< len; i++)
    {
        // If different, increment k and add
        // previous character
        if (str[i-1] != str[i])
            str[k++] = str[i-1];
 
        else
            // Keep skipping (removing) characters
            // while they are same.
            while (str[i-1] == str[i])
                i++;
    }
 
    // Add last character and terminator
    str[k++] = str[i-1];
    str[k] =  '\0';
 
    // Recur for string if there were some removed
    // character
    if (k != n)
        removeDup(str, k);// Shlemial Painter's Algorithm
 
    // If all characters were unique
    else return str;
}


char* removeDup2(char* s, int n){
    if (n == 0) return s;
    int i = 1;
    bool df = false;
    while(s[i-1] == s[i]) {
        ++i;
        df = true;
    }
    char* ans = removeDup2(s+i, n-i);
    if (df) return ans;
    if (ans[0] == s[i-1]) return ans+1;
    ans[-1]=s[i-1];
    return &ans[-1];
} 

int main() {
    string str;
    // getline(cin, str);
    // removeDup(str);

    char ch[100];
    char*ptr;
    cin >> ch;
    ptr = removeDup2(ch, strlen(ch));

    cout << ptr;
}