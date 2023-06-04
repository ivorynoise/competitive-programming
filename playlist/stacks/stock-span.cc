// Deepak Aggarwal, Coding Blocks
#include <iostream>
#include <stack>
using namespace std;

void printSpan(int arr[], int n){
    stack<int> s;
    int ans[100] = {};
    for(int day = 0; day < n; ++day){
        int curPrice = arr[day];
        while(s.empty() == false && arr[s.top()] < curPrice){
            s.pop();
        }

        int betterDay = s.empty() ? 0 : s.top();
        int span = day - betterDay;
        ans[day] = span;
        s.push(day);
    }

    for(int i = 0; i < n; ++i){
        cout << ans[i] << " ";
    }
}

int main(){
    int n = 7;
    int arr[100] = {100, 80, 60, 70, 60, 75, 85};

    printSpan(arr, n);

    return 0;
}