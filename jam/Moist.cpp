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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;

int main()
{
  
  int T, N, i, j, count;
  string str;
  vector<string> list;
  cin >> T;
  
  for (int k = 1; k <= T; k++)
  {
    cin >> N;
    cin.get();
    list.clear();
    count = 0;
    while(N--)
    {
      getline(cin, str);
      list.push_back(str);
    }
    
    for (i = 1; i < list.size(); i++)
    {
      for (j = 0; j < i; j++)
      {
        if (list[i] < list[j] ){
          count++;
          break;
        }
      }
      
    }
    
    cout << "Case #" << k << ": "<<count<<endl;
  }
  
  return 0;
}