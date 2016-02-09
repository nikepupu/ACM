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


using namespace std;

int colnum;


int main()
{
  string str;
  vector<string> table;
  vector<pair<int , int> > I;
  
  int i, j, a, b, x ,y;
  while(cin >> str)
  {
    if (str == "")
    {
      talle.clear();
      continue;
    }
    
    colnum = str.length();
    table.push_back(str);
   
    for (i =0; i < table.size(); i++)
      for (j = 0; j < colnum; j++ )
        if (table[i][j] == 'I')
          I.push_back(make_pair(i, j) );
        
    int count = 0;
    for (i = 0; i < I.size(); i++)
    {
      x = I[i].first, y = I[i].second;
      a = 0, b= 0;
      if (x-1 >= 0 && table[x-1] == 'W')
        a = 1;
      if (y-1 >= 0 && table[y-1] == 'W')
        a = 1;
      if (x+1 < table.size() && table[x+1] == 'W')
        a = 1;
      if (y+1 < colnum && table[y+1] == 'W')
        a = 1;
      
      if (x-1 >= 0 && table[x-1] == 'N')
        b = 1;
      if (y-1 >= 0 && table[y-1] == 'N')
        b = 1;
      if (x+1 < table.size() && table[x+1] == 'N')
        b = 1;
      if (y+1 < colnum && table[y+1] == 'N')
        b = 1;
      
    }
    
    
  }

  return 0;
}