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
struct location{
  string name;
  int x;
  int y;
};

int n;
void search(location *a, int x0, int y0, int xf, int yf, int count)
{
  if(count == n)
  	exit(0);

  check(a, x0, y0);

  search(a, x0,  )

}

int main()
{
	int s;
	cin >> n >> s;
	location a = new location[n];
	for (int i = 0; i < n; i++)
      cin >> a[i].x >> a[i].y >> a[i].name;

    serach(a, 0, 0, S, 0, 0);

  return 0;
}