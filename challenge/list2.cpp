#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>


using namespace std;

vector<string> list;

bool search(const char *cur, int pos, const int length, int &c)
{

  int static len = 0;
  if (pos == length)
  {
    if (c++ < 2 || length == len)
    {
      len = length;
      cout<< cur << endl;
    } // print out the first two longest string including a possible tie.
    
    return true;
  }//done
  
  for (int i = 0; i < list.size(); i++  )
  {
    if (list[i].length() + pos  > length ) return false; //pruning
    if(list[i][0] != cur[pos]) continue;
    
    
    if  ( cur != list[i] && strncmp(cur+pos, list[i].c_str(), list[i].length()) == 0 )
    {
      if (search(cur, pos + list[i].length(), length, c) )
        return true;
    }// if compare
  }
  return false;
}

struct cmp{
  
  bool operator()(string a, string b)
  {
    if (a.length() == b.length())
      return a[0] < b[0];
    return a.length() < b.length();
  }
  
};

int main()
{
  int count = 0;
  cmp compare;
  string str;
  
  while(cin >> str)
    list.push_back(str);
  
  sort(list.begin(), list.end(), compare);//sort from short to long
  
  
  for( int i = list.size()-1; i >= 0; i--)
  {
    search( list[i].c_str(), 0, list[i].length(), count);
  }
  cout << "number of strings can be constructed by other strings : " << count <<endl;
  
  return 0;
}
