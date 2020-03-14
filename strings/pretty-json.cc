// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
using namespace std;

void indent(int n, string& ans) {
    while (n--) {
        // cout << "\t";
        ans.push_back('\t');
    }

}

void enter() {
    // cout << endl;
}

void prettyJson(const string& s) {
    int curIndent = 0;
    bool insidePair = false;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '{' || s[i] == '[') {
            if (i == 0) {
                cout << s[i];
                enter();
                curIndent++;
            }
            else {
                enter();
                indent(curIndent);
                cout << s[i];
                enter();
                curIndent++;
            }
            insidePair = false;
        }
        else if (s[i] == '}' || s[i] == ']' ) {
            curIndent--;
            enter();
            indent(curIndent);
            cout << s[i];
            insidePair = false;
        }
        else if (s[i] == ',') {
            cout << s[i];
            enter();
            insidePair = false;
        }
        else {
            if (!insidePair) {
                indent(curIndent);
            }
            cout << s[i];
            insidePair = true;
        }
    }
}

int main() {
    string s;
    getline(cin, s);
    prettyJson(s);
}