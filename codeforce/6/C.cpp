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
string s;
int cur;
long long dp[2001][2001];
long long n, m,rest, minB=(1LL<<56),b;
long long mod = 1e9 +7, ans = 0;
int main()
{

  cin >> n >> m;
  cin >> s;
  dp[0][0] = 1;
  for (int i = 1; i <= n-m; i++)
  {
  	dp[i][0] = dp[i-1][1];
  	for(int j = 0; j <= i; j++)
  	{
  		dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1];
  		dp[i][j] %= mod;
  	}
  }

  for(int i = 0; i < s.length(); i++)
  {
  	if(s[i] == '(') b++;
  	else b--;
  	minB = min(minB, b);
   }

   for(int i = 0; i <= n-m; i++)
   {
   	for(int j = 0; j <= i; j++ )
   	{
   		if(j >= -minB)
   		{
   			if (j+b >= 0 && j+b <= n-m-i)
   			ans += dp[i][j] * dp[n-m-i][j+b];
   			ans %= mod;
   		}
   	}
   }

  cout << ans << endl;

  return 0;
}