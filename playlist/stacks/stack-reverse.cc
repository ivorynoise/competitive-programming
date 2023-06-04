// Deepak Aggarwal, Coding Blocks
#include <iostream>
#include <stack>
using namespace std;

void transfer(stack<int>& s1, stack<int>& s2, int n){
    for(int i = 0; i < n; ++i){
        s2.push(s1.top());
        s1.pop();
    }
}

void reverseStack(stack<int>& s1){
    stack<int> s2;
    int n = s1.size();

    for(int i = 0; i < n; ++i){
        int x = s1.top();
        s1.pop();
        transfer(s1, s2, n - i - 1);
        s1.push(x);
        transfer(s2,s1,n-i-1);
    }
}

void insertAtBottom(stack<int>&s, int x){
    if (s.empty()){
        s.push(x);
        return;
    }

    int y = s.top();
    s.pop();
    insertAtBottom(s, x);
    s.push(y);
}

void reverseStackRec(stack<int>& s){
    if (s.empty()) return;

    int x = s.top(); 
    s.pop();
    reverseStackRec(s);
    insertAtBottom(s,x);
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    reverseStackRec(s);

    while(s.empty() == false){
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}