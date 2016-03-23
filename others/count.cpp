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

string a;
string b;
long long dp[100][10][2];//长度， 数字，
long long res[10]; 

void check(string &s)
{
	for(int i = 0; i < s.length(); i++)
		res[(s[i] - '0')]++;
}

void solve(string &s, int type)
{
 memset(dp, 0, sizeof(dp));
 dp[0][0][1] = 1;
 //for(int i = 0; i  < s[0]-'0'; i++)
 	//dp[0][i][0]++;

 int len = s.length();

 for(int i = 0; i <len; i++)
 	for(int j = 0; j <10; j++)
 		for(int k = 0; k < 2; k++)
 			for(int p =0; p <= (k? s[i]-'0': 9); p++)
 			{	
 				
 				int ni = i+1;
 				int nj = p;
 				int nk = (k && (p == int(s[i] - '0')));
 				dp[ni][nj][nk] += dp[i][j][k];
 				
 			}

 	if (type == 1)
	for(int j = 0; j < 10; j++)
	{
		//cout << dp[0][j][0]<<" ";	
		res[j] += dp[len][j][0]+dp[len][j][1];
	}

	else{

		for(int j = 0; j < 10; j++)
		{
			for(int k = 0; k < 2; k++)
				res[j] -= dp[len][j][k];
		}
	}

  
}
int main()
{
	//memset(a,'0',sizeof(a));
	memset(res,0,sizeof(res));

	cin >> a >>b;
	


	solve(b,1);

	solve(a,2);
	check(a);
	
  	for(int i = 0; i < 10; i++)
  		cout << res[i] <<" ";
  	cout << endl;

  return 0;
}