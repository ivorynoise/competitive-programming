// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <bits/stdc++.h>
using namespace std;
#define pc(i) cout << "Case #" << i << ": "
#define scd(i) scanf("%d", &i)
#define all(v) v.begin(), v.end()

int sgn(int x){
    return x < 0 ? -1 : 1;
}

void solve(int arr[], int n) {
    vector<int> odd, even;
    for(int i = 0; i < n; i+=2){
        odd.push_back(arr[i]);
    }

    for(int i = 1; i < n; i +=2){
        even.push_back(arr[i]);
    }   

    sort(all(odd));
    sort(all(even));
    sort(arr, arr + n);

    std::vector<int> ans;
    int i = 0, j = 0;
    while(i < odd.size() && j < even.size()){
        ans.push_back(odd[i]); ++i;
        ans.push_back(even[j]); ++j;
    }
    if (i < odd.size()){
        ans.push_back(odd[i]); ++i;
    }

    bool isError = false;
    for(int i = 0; i < n; ++i){
        if (ans[i] != arr[i]){
            isError = true;
            cout << i << endl;
            break;
        }
    }
    if (!isError) cout << "OK" << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; ++i) {
            scd(arr[i]);
        }
        pc(i+1);
        solve(arr, n);
        delete [] arr;
    }
    return 0;
}