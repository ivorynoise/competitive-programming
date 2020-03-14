#include <bits/stdc++.h>
using namespace std;

bool isVow(char c) {
    switch (tolower(c)) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u': return true;
    }
    return false;
}

void removeVow(char s[]) {
    int j = -1;
    int cur = 0;
    while (s[cur]) {
        if (isVow(s[cur])) {
            if (j == -1) j = cur;
        }
        else {
            if (j != -1) {
                swap(s[cur], s[j]);
                ++j;
            }
        }
        ++cur;
    }
    if (j != -1) swap(s[cur], s[j]);
}

int main() {
    char str[100];
    cin >> str;

    removeVow(str);
    cout << "X" << str << "X" ;
}