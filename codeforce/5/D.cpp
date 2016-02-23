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
const long long mod = 1000000000+7;
long long dp[2010][2010][2];// cur i, module,
string a, b;
int m,len,d;

long long solve(string n)
{

	memset(dp, 0, sizeof(dp) );
	dp[0][0][1] = 1;

	for(int i = 0; i < len; i++)
		for(int j = 0; j < m; j++)
			for(int k =0; k <2; k++)
				for(int p = 0; p <= (k? int(n[i]-'0'): 9); p++)
				{	
					if((i %2 == 1) && p != d) continue;
					if((i % 2 == 0) && p == d) continue;
					//if(!i && !p) continue;
					int ni = i+1;
					int nj = (10*j + p)%m;
					int nk = (k && (p == int(n[i]-'0') ));
					dp[ni][nj][nk] += dp[i][j][k];
					dp[ni][nj][nk] %=mod;
				}
			
	

	 
	return dp[len][0][1] + dp[len][0][0];
}

int good(string s)
{
	int a = 0;
	for(int i = 0; i < len; i++)
	{
		if(i %2 == 0 && (s[i]-'0' == d) ) return 0;
		if(i %2 == 1 && (s[i]-'0' != d) ) return 0;

		a = (a * 10 + s[i]-'0')%m;
		a %= m;
	}
	
	if (a == 0)
		return 1;

	else return 0;
}


int main()
{
	cin >> m >> d;
	cin >> a >> b;
	len = a.length();

	long long temp = (solve(b)-solve(a)+good(a))%mod;
	while(temp <0)
	{
		temp += mod;
	}
	cout << temp << endl;

  return 0;
}