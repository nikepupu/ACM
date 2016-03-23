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
int milk[2001][2001][2];//player, favor, type
int res[2001];
int T, N, M;
bool search(int cur, int goal)
{
	if (cur == goal)
		return true;

	for(int i = 0; i < N; i++)
	{
		if (milk[cur][i][0]&& (res[i] == 0 || res[i] == 1) )
		{
			int status = res[i];
			res[i] = 1;
			if (search(cur+1, goal))
				return true;

		
			res[i] = status;
		}
		 if (milk[cur][i][1]&& (res[i] == 0 || res[i] == 2) )
	 	{
	 		int status = res[i];
	 		res[i] = 2;
			if (search(cur+1, goal))
				return true;

			res[i] = status;
	 	}

	}
	return false;
	
}

int main()
{
	
	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #"<<t<<": ";
		cin>> N >> M;
		memset(milk, 0, sizeof(milk));
		memset(res, 0, sizeof(res));
		for(int i = 0; i < M; i++)
		{
			int num;
			cin >> num;
			for(int j = 0; j < num; j++)
			{
				int temp1, temp2;
				cin >> temp1 >> temp2;
				milk[i][temp1-1][temp2]=1;
			}

		}

		if (search(0, M))
		{
			int i;
			for( i = 0; i < N; i++)
			{
				if (res[i] < 2)
				cout << 0 <<" ";
				else cout << 1 << " ";

			}

			cout << endl;
		}
		else cout << "IMPOSSIBLE\n";



	}
  

  return 0;
}