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

vector<int> bag;
int cnt[5000]={0}, sum[10000]={0};
double ans = 0.0;
int main()
{
  int n, a;
  int count = 0;
  cin >> n;
  for(int i= 0; i < n; i++)
  {
    cin >> a;
    bag.push_back(a);
  }

  sort(bag.begin(), bag.end());
  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
      if (i == j)
      { count++;
        continue;
      }
      cnt[abs(bag[i]-bag[j])]++;
    }
  memcpy(sum, cnt, sizeof(cnt));
  for(int i = 4998; i >= 0; i-- )
    sum[i] += sum[i+1];
  
  
  for(int j = 0; j < 5000; j++)
    for(int i = 0; i < 5000; i++)
      ans += (double)cnt[i] * cnt[j] * sum[i+j+1];
    
  
  double temp = n*n-count;

  ans = ans /temp/temp /temp;

  
  cout << fixed << setprecision(10) << ans << endl;
  
  

  return 0;
}