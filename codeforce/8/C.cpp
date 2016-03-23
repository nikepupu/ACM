#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;
struct cmp
{
  bool operator () (string a, string b){
   
    return (a + b < b + a);    
    
  }
};

int main()
{
  cmp compare;
  int n, p;
  cin >> n;
  vector<string> s;
  for(int i = 0; i < n; i++)
  {
    string temp;
    cin >> temp;
    s.push_back(temp);
  }

  sort(s.begin(), s.end(), compare);

  string S;
  for(int i =0; i < n; i++)
    cout << s[i];
  

  cout << endl;

  return 0;
}