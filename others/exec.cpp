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
	int n;
	cin >> n;
	int m = (1<<30);
	int *a = new int[n];
	for (int i = 0; i <n; i++)
		cin >> a[i];

	sort(a, a+n);
	int low = 0, high = n-1;

	while(low < high)
	{
      m = min(m, a[low] + a[high]);
      low++;
      high--;

	}
  
  cout << m << endl;
  return 0;
}