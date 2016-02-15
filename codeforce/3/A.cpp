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
#include <stack>

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;

int matrix[500][500];


int main()
{
  int n;
  cin >> n;
  char c;
  int count=0;
  int x = 250;
  int y =250;
  set<pair<int, int> > group;
 
  string command;
  cin >> command;
  for(int start = 0; start < n; start++)
  {
    int end;
  for ( end = start+1; end < n; end++){
    x = y = 250;
    memset(matrix,0,sizeof(matrix));
    matrix[x][y]=1;
    for(int i = start; i <= end; i++){
    c = command[i];
    if (c=='L')
    {
      x--;

    }
    
    if (c=='R')
    {
      x++;

    }
    
    if (c=='D')
    {
      y--;

    }
    
    if (c=='U')
    {
      y++;
  
    }
    }
    if(x == y && x== 250)
      count++;
  }
    
    //cout << command.substr(start, end-start+1) << "count: "<< count << endl;
  
  }
  
  cout << count<<endl;

  return 0;
}