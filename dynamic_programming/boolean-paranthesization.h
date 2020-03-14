// boolean paranthesization

bool eval(char x, char y, char op) {
    bool a = x == 'T';
    bool b = y == 'T';

    switch (op) {
    case '^' : return a != b;
    case '&' : return a && b;
    case '|' : return a || b;
    }
}


int cnt = 0;
int T[10][10] = {}, F[10][10] = {};

//*****                     be     en                be     en
int numWays(string sym, int i, int j, string op, int x, int y, bool req) {
    ++cnt;
    // if no operand
    if (i > j) {
        return 0;
    }

    // if no operator cant generate anything
    if (x > y) {
        bool a = sym[i] == 'T';
        return a == req;
    }

    // if just one operator
    if (x == y) {
        if (eval(sym[i], sym[j], op[x]) == req) return 1;
        return 0;
    }

    if (req) {
        if (T[i][j]) return T[i][j];
    }
    if (!req) {
        if (F[i][j]) return T[i][j];
    }

    int ans = 0;

    for (int k = x; k <= y; ++k) {
        switch (op[k]) {
        case '^' :
            ans += min( numWays(sym, i, k, op, x, k - 1, false),
                        numWays(sym, k + 1, j, op, k + 1, y, true));
            ans += min( numWays(sym, i, k, op, x, k - 1, true),
                        numWays(sym, k + 1, j, op, k + 1, y, false));
            break;
        case '&' :
            ans += min( numWays(sym, i, k, op, x, k - 1, true),
                        numWays(sym, k + 1, j, op, k + 1, y, true));
            break;
        case '|' :
            ans += min( numWays(sym, i, k, op, x, k - 1, true),
                        numWays(sym, k + 1, j, op, k + 1, y, true));
            ans += min( numWays(sym, i, k, op, x, k - 1, false),
                        numWays(sym, k + 1, j, op, k + 1, y, true));
            ans += min( numWays(sym, i, k, op, x, k - 1, true),
                        numWays(sym, k + 1, j, op, k + 1, y, false));
        }
    }
    if (req) T[i][j] = ans;
    if (!req) F[i][j]  = ans;
    return ans;
}

// bottom up
int numWays2(string expr, string op) {
    int n1 = expr.size();
    int n2 = op.size();

    const int D = 1e3;
    int T[D][D] = {}, F[D][D] = {};

    for (int i = 0; i < n1; ++i) {
        T[i][i] = expr[i] == 'T';
        F[i][i] = expr[i] == 'F';
    }

    for (int len = 2; len <= n1; ++len) {
        for (int j = 0; j <= n1 - len; ++j) {
            int srt = j;
            int end = j + len - 1;
            int ans1 = 0;
            int ans2 = 0;

            for (int k = 1; k <= len - 1; ++k) {
                int l = srt + k - 1;
                switch (op[l]) {
                case '^' :
                    ans1 += T[srt][l] * F[l + 1][end] +
                            F[srt][l] * T[l + 1][end];
                    ans2 += T[srt][l] * T[l + 1][end] +
                            F[srt][l] * F[l + 1][end];
                    break;
                case '|' :
                    ans1 += T[srt][l] * T[l + 1][end] +
                            F[srt][l] * T[l + 1][end] +
                            T[srt][l] * F[l + 1][end];
                    ans2 += F[srt][l] * F[l + 1][end];
                    break;
                case '&' :
                    ans1 += T[srt][l] * T[l + 1][end];
                    ans2 += T[srt][l] * F[l + 1][end] +
                            F[srt][l] * T[l + 1][end] +
                            F[srt][l] * F[l + 1][end];
                }
            }
            T[srt][end] = ans1;
            F[srt][end] = ans2;

        }
    }
    printTwoD(T, n1, n1);
    printTwoD(F, n1, n1);
    return T[0][n1 - 1];
}