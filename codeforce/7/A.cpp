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

int r,c , n, k;
int pos[20][20];
int res = 0;

int main()
{
	cin >> r >> c >> n >> k;
	memset(pos,0,sizeof(pos));
	for(int i = 0; i < n; i++)
	{
		int x, y;
		cin >> x >> y;
		pos[x-1][y-1]=1;
	}
	//cout << r << c << endl;

	for(int i = 0; i < r; i++)
		for(int j = 0; j < c; j++)
		{
			
			for(int p = i; p < r; p++)
				for(int q= j; q < c; q++)
				{
					int count = 0;
					for(int m = i; m <= p; m++ )
						for(int mm = j; mm <= q; mm++)
							if (pos[m][mm] == 1)
								count++;

					if (count >= k)
						res++;	
				}

				
		}
  
	cout << res << endl;
  return 0;
}