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
#include <fstream>
template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;
int length;

struct cmp
{
  bool operator () (vector<string> &a, vector<string> &b)
  {
 
    for(int i = 1; i < length;)
    {

        if (a[i] > b[i])
        	return true;
        else if(a[i] == b[i])
        	i++;
        else return false;

    }
    return a[0] < b[0];
  }

};

int main()
{
  cmp compare;
  char str[256];
  char* ptr;
  unsigned long i;
  length=0;
  cin >> i;
  cin.get();
  vector<vector<string> > name;
  i = 0;
  while(cin.getline(str, 256) )
  { 
  	 name.push_back(vector<string>());
     ptr = strtok(str, " ");

     name[i].push_back(ptr);
     name[i][0].pop_back(); 
     ptr = strtok(NULL, " ");
     while(ptr)
     {
        name[i].push_back(ptr);    
        ptr = strtok(NULL, " ");
     }
     name[i].pop_back();
     auto it = name[i].begin();
     it++;
     reverse(it, name[i].end() );
     i++;

  }


   for ( i = 0; i < name.size(); i++)
   {
   		if (length < name[i].size())
   			length = name[i].size();
	}
   for(i = 0; i< name.size(); i++)
   	while(name[i].size() < length)
   		name[i].push_back("middle");
  	sort(name.begin(),name.end(), compare);
    for(i = 0; i < name.size();i ++){
    		cout<< name[i][0]<<endl;

   
    }
  return 0;
}