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
  int n, p;
  cin >> n >> p;
  vector<string> type;
  
  double count = 0;
  for(int i = 0; i < n; i++)
  {
  	string temp; 
  	cin >> temp;
  	type.push_back(temp);
  }

  reverse(type.begin(), type.end());
  long long res = 0;

  for(int i = 0; i < n; i++)
  {
  	if (type[i] == "halfplus")
  	{
  		double old = count;
  		count += 0.5;
  		count *= 2;
  		double diff = count - old -0.5 ;
  		res += diff * p;
  		//cout << res << endl;
  	}

  	else {
  		double diff = count;
  		count *=2;
  		res += diff * p;
  		//cout << res << endl;
  	}
  }

  cout << res << endl;

  return 0;
}