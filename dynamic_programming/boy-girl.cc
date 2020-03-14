#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vec;
typedef vector<vec> m;


const int D = 1010;
int boySrc[D][D] = {};
int girlSrc[D][D] = {};
int boyDest[D][D] = {};
int girlDest[D][D] = {};

int calBurnt(int arr[][D], int m, int n) {
    // boy calories from src
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // first row or first col
            if (i == 0 && j == 0) {
                boySrc[i][j] = arr[i][j];
            }
            else if (i == 0) {
                boySrc[i][j] = arr[i][j] + boySrc[i][j - 1];
            }
            else if (j == 0) {
                boySrc[i][j] = arr[i][j] + boySrc[i - 1][j];
            }
            else {
                boySrc[i][j] = max(
                                   arr[i][j] + boySrc[i - 1][j],
                                   arr[i][j] + boySrc[i][j - 1]
                               );
            }
        }
    }

    // girl calories from src
    for (int i = m - 1; i >= 0; --i) {
        for (int j = 0; j < n; ++j) {
            if (j == 0 && i == m - 1) {
                girlSrc[i][j] = arr[i][j];
            }
            else if (j == 0) {
                girlSrc[i][j] = arr[i][j] + girlSrc[i + 1][j];
            }
            else if (i == m - 1) {
                girlSrc[i][j] = arr[i][j] + girlSrc[i][j - 1];
            }
            else {
                girlSrc[i][j] = max(
                                    arr[i][j] + girlSrc[i + 1][j],
                                    arr[i][j] + girlSrc[i][j - 1]
                                );
            }
        }
    }

    // boy calories from dest
    for (int i = m - 1; i >= 0; --i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i == m - 1 && j == n - 1) {
                boyDest[i][j] = arr[i][j];
            }
            else if (i == m - 1) {
                boyDest[i][j] = arr[i][j] + boyDest[i][j + 1];
            }
            else if (j == n - 1) {
                boyDest[i][j] = arr[i][j] + boyDest[i + 1][j];
            }
            else {
                boyDest[i][j] = max(
                                    arr[i][j] + boyDest[i + 1][j],
                                    arr[i][j] + boyDest[i][j + 1]
                                );
            }
        }
    }

    // girl calories from dest
    for (int i = 0; i < m; ++i) {
        for (int j = n - 1; j >= 0; --j) {
            if (i == 0 && j == n - 1) {
                girlDest[i][j] = arr[i][j];
            }
            else if (i == 0) {
                girlDest[i][j] = arr[i][j] + girlDest[i][j + 1];
            }
            else if (j == n - 1) {
                girlDest[i][j] = arr[i][j] + girlDest[i - 1][j];
            }
            else {
                girlDest[i][j] = max(
                                     arr[i][j] + girlDest[i][j + 1],
                                     arr[i][j] + girlDest[i - 1][j]
                                 );
            }

        }
    }

    int maxans = 0;
    // actual ans
    for (int i = 1; i < m - 1; ++i) {
        for (int j = 1; j < n - 1; ++j) {
            int topBottomBoy = (boySrc[i-1][j] + boyDest[i + 1][j]);
            int leftRightGirl = (girlSrc[i][j - 1] + girlDest[i][j + 1]);
            int ans1 = topBottomBoy + leftRightGirl;
            int bottomTopGirl = girlSrc[i+1][j] + girlDest[i - 1][j];
            int leftRightBoy = boySrc[i][j - 1] + boyDest[i][j+ 1];
            int ans2 = bottomTopGirl + leftRightBoy;
            maxans = max(maxans,max(ans1, ans2));
        }
    }
    return maxans;
}

int main(){
    int arr[D][D];
    int m, n;
    cin >> m >> n;
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin >> arr[i][j];
        }
    }

    int ans = calBurnt(arr, m, n);
    cout << ans;
}