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
long long order[200001];
long long n,k,a,b,q;
long long ai, di, d, maxd=0;
long long query[200001]={0};
void check(long long day)
{
	long long count = 0;
	
	for(long long i = 0; i < day; i++)
	{
		count += min(order[i], b);
	}

	for(long long i = day+k; i <= maxd; i++)
	{
		count += min(order[i],a);
	}
	cout << count << endl;
}

int main()
{
	cin >> n >> k >> a >> b >> q;
	for(long long i = 0; i < q; i++)
	{
		int temp;
		cin >> temp;
		if (temp == 1)
		{
			cin >> di >> ai;
			order[di]+=ai;
			maxd = max(maxd, di);
		}
		else
		{
			cin >> d;
			check(d);
		}
	}
  

  return 0;
}