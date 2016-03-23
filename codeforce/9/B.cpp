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

int num[1002];

int main()
{
  int n;
  int count = 0;
  memset(num, 0, sizeof(num));

  cin >> n;
  int m = 0;
  for(int i = 0; i  < n; i++)
  {
  	int temp;
  	cin >> temp;
  	m = max(m, temp);
  	num[temp]++;
  }

 
  	int gx = 0;
	for(int i = 0; i < 1001; i++){
		if (num[i] != 0)
		count++;

		if (num[i] > 1)
		{
			int temp = num[i] - 1;
			if (gx >= temp)
			{
				gx -= temp;
				count += temp;
			}
			else
			{
				count += gx;
				gx = temp - gx;
			}
		}
			
	}
	

	cout << count-1<<endl;


  return 0;
}