// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
enum type{buy, sell};

int b[100][100], s[100][100];

int n = 0;
int maxProfit(const vector<int>& arr, int be, type t, int txn, int buyVal){
    if (txn == 0) return 0;
    if (be >= n) return 0;

    if (t==buy && b[be][txn] != -1) return b[be][txn];
    if (t==sell && s[be][txn] != -1)return s[be][txn];

    if (txn && t == buy){
        int p1 = maxProfit(arr, be+1, sell, txn-1, arr[be]);
        int p2 = maxProfit(arr, be+1, buy, txn, buyVal);
        return b[be][txn] = max(p1,p2);
    }
    else if (txn && t == sell){
        int p1=0, p2=0;
        if (arr[be] - buyVal >= 0){
            p1 = maxProfit(arr, be+1, buy, txn-1, 0) + arr[be]-buyVal;
        }
        p2=maxProfit(arr, be+1, sell, txn, buyVal);
        return s[be][txn] = max(p1,p2);
    }
    return 0;
}

int /*Solution::*/maxProfit(const vector<int> &A) {
    memset(b, -1, sizeof b);
    memset(s, -1, sizeof s);
    n = A.size();
    return maxProfit(A, 0, buy, 4, 0);
}

int main(){
    vector<int> a = {1,10, 51, 50};
    int ans = maxProfit(a);
    cout << ans;
    
}