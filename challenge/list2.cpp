#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct cmp{
  
  bool operator()(string a, string b)
  {
    return a.length() < b.length();
  }
  
};

cmp compare;
vector<string> list;
map <char, vector<string> > listwords;


bool search(string &cur, int pos, const int length, int &c)
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
  
  
  for (int i = 0; i < listwords[cur[pos]].size(); i++  )
  {
    if (listwords[cur[pos]][i].length() + pos > length) return false;
    if (length == listwords[cur[pos]][i].length()) return false;
    if(cur.substr(pos, listwords[cur[pos]][i].length()).compare(listwords[cur[pos]][i]) == 0 )
    {
      if (search(cur, pos + listwords[cur[pos]][i].length(), length, c) ){
          //cout << listwords[cur[pos]][i] << endl;
        return true;
      }
    }// if compare
  }
  return false;
}


int main()
{
  int count = 0;
  string str;
  
  for(int i = 0; i < 26; i++)
  {
    listwords[i + 'a'] = vector<string>();
  }
  
  while(cin >> str){
    listwords[str[0]].push_back(str);
    list.push_back(str);
  }
  
  sort(list.begin(), list.end(), compare);//sort from short to long
  for (int i = 0; i < 26; i++)
  {
    sort(listwords[i+'a'].begin(),listwords[i+'a'].end(), compare);
  }
  
  
  for( int i = list.size()-1; i >= 0; i--)
  {
    search( list[i], 0, list[i].length(), count);
  }
  cout << "number of strings can be constructed by other strings : " << count <<endl;
  
  return 0;
}
