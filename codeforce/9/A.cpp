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
int p = 0;
int dp[200][200][200];
void search(int a1, int a2, int cnt)
{
	
	if (a1  <=0 || a2 <=  0 || (a1 == 1 && a2 == 1) )
	{
		p = max(p, cnt);
		return;
	}

	if(dp[a1][a2][cnt] == 1)
		return;
	else
		dp[a1][a2][cnt] = 1;

	search(a1-2, a2+1, cnt+1);
	search(a1+1, a2-2, cnt+1);
}

int main()
{
  int a1,a2;
  cin >> a1 >> a2;
  memset(dp, 0, sizeof(dp));
  search(a1, a2, 0);
  cout << p << endl;

  return 0;
}