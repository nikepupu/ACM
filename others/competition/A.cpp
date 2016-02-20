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
#include <sstream>

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;
string str;
multimap<int, string> table;
map <string, string>;
vector<int> n;
string cur;

int main()
{
	stringstream is;
	string name;
	string prefix;
  while(getline(cin, str))
  {
    if (str[1]=='.')
    {
    	//int it = str.find(" ");
    	int i = 2;
    	while(str[i]!= ' ') {
    		i++;
    	}
    	is.str("");
    	i++;
    	for(; i < str.length(); i++)
    		is << str[i];

    	name = is.str();
    	
    	//cout << name << endl;

    }
    else {
    	int found = 0, last = 0;
    	for(int i = 0; i <= str.length(); i++)
    	{
    		if ( i == str.length()  || str[i] == ' ' )
    		{
    			found = i;
    			num = stoi(str.substr(last, found-last));
    			if (table[num]=="")
    			 table[num] = name;
    			else table[num] += ("."+name);
    			last = found+1;
    			n.push_back(num);
    		}
    	}

    	
    }


  }

  sort(n.begin(), n.end());
  for(int i = 0; i < n.size(); i++)
  {
  	cout << n[i]<<" : ";
  	cout << table[n[i]]<<endl;
  }


  return 0;
}