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

int main()
{
  string a, b;
  int c = 0;
  cin >> a >> b;
  //vector<int > m;
  
  int found;
  int status = 1;
  while(found != string::npos)
  {
    if (status != 1)
    found = a.find(b, found +b.length());
    else
    found = a.find(b);
    status = 0;

    c++;
    //cout << "hi";
  }
  c--;
  
  cout << c<<endl;
  return 0;
}