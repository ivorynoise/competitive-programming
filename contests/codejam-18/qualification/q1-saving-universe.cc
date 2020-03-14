// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <bits/stdc++.h>
using namespace std;
#define pc(i) cout << "Case #" << i << ": ";

// CSSCCSSC
void solve(int threshold, string& seq, int t) {
    const int n = seq.size();
    int cIdx = seq.size() - 1;
    int sIdx = seq.size() - 1;
    int total_damage = 0;
    vector<int> cnt(n, 0);

    for (int i = 0; i < n; ++i) {
        if (seq[i] == 'C') {
            cnt[i] = i > 0 ? cnt[i - 1] + 1 : 1;
        }
        else {
            int charge = cnt[i] = i > 0 ? cnt[i - 1] : 0;
            total_damage += (1 << charge);
        }
    }

    int nSwap = 0;
    while (cIdx >= 0 && sIdx > 0 && total_damage > threshold) {
        while (cIdx >= 0 && seq[cIdx] != 'C') --cIdx;
        while (sIdx > 0 && seq[sIdx] != 'S') --sIdx;
        if (cIdx < 0 || sIdx <= 0) break;

        if (cIdx > sIdx) {
            cIdx = sIdx - 1; 
            continue;
        }

        int excess = total_damage - threshold;
        int swap_avail = sIdx - cIdx;
        int charge = cnt[cIdx] -1;
        int strength = 1<<charge;
        int swap_req = ceil(excess/strength);
        int swap_done = min(swap_avail, swap_req);
        nSwap += swap_done;
        int damage_prevented = (strength)*swap_done;
        total_damage -= damage_prevented;
        cnt[cIdx]--;

        --sIdx; --cIdx;
    }

    if (total_damage > threshold){
        pc(t);
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        pc(t);
        cout << nSwap << endl;
    }
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int threshold;
        cin >> threshold;
        string seq;
        cin >> seq;
        solve(threshold, seq, i+1);
    }
    return 0;
}