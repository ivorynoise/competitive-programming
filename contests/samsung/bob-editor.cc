// Bob and the editor
#include <bits/stdc++.h>
using namespace std;
string buffer;
vector<string> v;
int lineNo = -1;  // 0 based
int nLines = 0;

void insertIntoFile(const string& s, bool shouldappend) {
    if (shouldappend && lineNo != -1){
        v[lineNo].append(s);
    }
    else {
        ++lineNo;
        v.insert(v.begin() + lineNo, s);
        ++nLines;
    }
}

void deleteCurLine() {
    if (lineNo == -1) return;
    v.erase(v.begin() + lineNo);
    --nLines;
    --lineNo;
    if (lineNo == -1 && nLines != 0) lineNo = 0;
}

void deleteCurLineAndCopy() {
    buffer = v[lineNo];
    deleteCurLine();
}

void updateBuffer() {
    buffer = v[lineNo];
}

void pasteBufferToEnd() {
    v[lineNo].append(buffer);
}

void moveCursorToEnd(int m) {
    lineNo = m;
}

int main() {
    int N;
    cin >> N; cin.get();

    string curLine;
    for (int i = 0; i < N; ++i) {
        getline(cin, curLine);
        insertIntoFile(curLine, false);
    }

    int q;
    cin >> q; cin.get();

    for (int i = 0; i < q; ++i) {
        char cmd[10];
        cin >> cmd; cin.get();

        switch (cmd[0]) {
            case 'd' :
                if (cmd[1] == 'd') {
                    deleteCurLine();
                }
                else if(cmd[1] == 'y'){
                    deleteCurLineAndCopy();
                }
                break;

            case ':':
            {
                int m = atoi(&cmd[1]);
                --m;
                moveCursorToEnd(m);
                break;
            }

            case 'i':
            {
                int m; cin >> m; cin.get();
                string tmp;
                bool shouldappend = true;
                for (int i = 0; i < m; ++i) {
                    getline(cin, tmp);     // the first line needs to be appended
                    insertIntoFile(tmp, shouldappend);  // the lines needs to be inserted
                    shouldappend = false;
                }
                break;
            }

            case 'y':
                updateBuffer();
                break;

            case 'p':
                pasteBufferToEnd(); // move the cursor to the end
                break;
        }
    }

    for (auto it = v.begin(); it != v.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}