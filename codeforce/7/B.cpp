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
int a[2000001]={0};
int b[2000001]={0};
int nex[2000001]={0};
int main()
{
	int n;
	cin >> n;
	int zero=0;
	int last = 0;
	int status = 0;
	int first;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if (a[i] == 0)
			zero++;
		else
		{
			if (status)
			nex[last] = a[i];

			if (status == 0)
				first = a[i];

			last = a[i];
			status = 1;
		}
	}

	nex[last] = first;

	for(int i = 0; i < n; i++)
		cin >> b[i];

  	if (zero == 0)
  	{
  		cout << "NO"<<endl;
  		return 0;
  	}
  	status = 1;
  	for(int  i = 0 ; i < n && status; i++)
  	{
  		if (b[i] != 0)
  		{
  			if(b[i+1] == 0 ) continue;

  			if( b[i+1] != nex[b[i]] )
  			{
  				status = 0;
  				//cout << b[i+1] << "  "<< nex[b[i]]<<endl;
  			}
  		}
  	}

  	if (status)
  		cout << "YES\n";
  	else 
  		cout << "NO\n";

  return 0;
}