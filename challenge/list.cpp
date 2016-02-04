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


using namespace std;


multimap<char, string> list;
set<string> res;
int c = 0;
int ind[27];

bool search(string &cur, int pos, const int length)
{
  
  if (pos == length)
  {
    res.insert(cur);
    return true;
  }//finished
  
  auto temp = list.equal_range(cur[pos]);
  
  for (auto it = temp.first; it != temp.second; it++  )
  {
  
    if  ( cur != it->second && cur.substr(pos, (it->second).length() ).compare(it->second) == 0 )
    {
      if (search(cur, pos + (it->second).length(), length) )
        return true;
      
    }// if compare
  }
  
  return false;
}


int main()
{
  vector<string> res;
  string str;
  int fre[27] = {0};
  int sum = 0;
  
  
  while(cin >> str)
  {
    list.insert(pair<char, string>(str[0], str));
    fre[str[0]-'a']++;
  }
  
  
  
  for( auto it = list.begin(); it != list.end(); it++ )
  {
    
    search( (*it).second, 0, (*it).second.length());
  }
  //go over the list from big to small
  auto it = res.begin();
  cout << *it << endl;
  it++;
  cout << *it << endl;
  cout << "num of words can be constructed: " << res.size();
  
  return 0;
}

