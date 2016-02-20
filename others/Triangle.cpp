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
	int a[3];
	int b[3];

	for(int i = 0; i < 3; i++)
		cin >> a[i];
	for(int i = 0; i < 3; i++)
		cin >> b[i];

	sort(a,a+3);
	sort(b,b+3);

    
	if (abs(a[0]-b[0]) +abs(a[1]-b[1]) + abs(a[2]-b[2])  != 0)
	{
      cout <<"NO"<<endl;
      return 0;
	}

   else if (a[0] + a[1] < a[2] ||b[0] + b[1] < b[2] )
   	{
      cout <<"NO"<<endl;
      return 0;
	}

	else if((pow(a[0],2) + pow(a[1],2) != pow(a[2],2)) ||(pow(b[0],2) + pow(b[1],2) != pow(b[2],2)) )
	{
      cout <<"NO"<<endl;
      return 0;
	}

    cout << "YES" << endl;




  

  return 0;
}