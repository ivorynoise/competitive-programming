// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
using namespace std;
#define pb push_back
#define p push

#define pb push_back
#define p push

string tmp;
vector<string> ans;
int n = 0;

bool isOpen(char c) {
    return c == '{' or c == '[';
}

bool isClose(char c) {
    return c == '}' or c == ']';
}

void indent() {
    for(int i = 0; i < n; ++i) {
        tmp.pb('\t');
    }
}
void push(char c) {
    tmp.pb(c);
}
void push(string s) {
    ans.pb(s);
    tmp = "";
}

vector<string> prettyJSON(string s) {
    n = 0;
    ans.clear();
    tmp = "";
    bool inside = false;

    for (int i = 0; i < s.size(); ++i) {
        char c = s[i];

        if (isOpen(c)) {
            if (tmp.size() != 0) {
                p(c);
                p(tmp);
                ++n;
                inside = false;
                continue;
            }
            indent();
            p(c);
            p(tmp);
            ++n;  inside = false;
        }
        else if (isClose(c)) {
            if (tmp.size() != 0) {
                p(tmp);
            }

            --n;
            indent();
            p(c);

            ++i;
            if (i < s.size() && s[i] == ',') {
                --i; continue;
            }
            --i;
            p(tmp);
            inside = false;
        }
        else if (c == ',') {
            p(c);
            p(tmp); inside = false;
        }
        else {
            if (!inside) {
                indent();
            }
            p(c); inside = true;
        }
    }
    return ans;
}

int main() {
    string s;
    getline(cin, s);
    auto ans = prettyJSON(s);
    for (auto a : ans) cout << a << endl;
}