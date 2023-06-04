// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <cstring>
using namespace std;
int cnt = 0;
int memo[100][100];

bool match(char pattern[100], int i, char str[100], int be) {
  ++cnt;
  if (pattern[i] == '\0' && str[be] == '\0'){
    return true;
  }
  if (pattern[i] == '\0'){
    return false;
  }
  if (str[be] == '\0'){
    if (pattern[i] == '*'){
      return memo[be][i] = match(pattern, i + 1, str, be);
    }
    return false;
  }

  // if (memo[be][i] != -1) return memo[be][i];

  if (pattern[i] == '?'){
    return memo[be][i] = match(pattern, i+1, str, be+1);
  }
  if (pattern[i] == '*'){
    bool inclusive = match(pattern, i, str, be+1);   // matches 1 or more chars
    bool exclusive = match(pattern, i + 1, str, be); // matches 0 chars
    return memo[be][i] = inclusive || exclusive;
  }

  return memo[be][i] = pattern[i] == str[be] && match(pattern, i + 1, str, be + 1);

}



int main() {
  memset(memo, -1, sizeof memo);
  char pattern[100];
  cin >> pattern;

  char str[100];
  cin >> str;

  cout << match(pattern, 0, str, 0) << endl;
  cout << cnt;
}