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
long long n, dist, sum[100001]={0};
char a[100001];
char s[100001];

bool search(long long len, long long val )
{
	if (len == n && val == dist){
		//cout << len <<endl;
		return 1;
	}

	if (len > n || val > dist) 
		return 0;

	for(int i = 'a'; i <= 'z'; i++)
	{
		a[len] = i;
		if (search(len+1, val + abs(i-s[len])) )
			return 1;

	}
	return 0;

}

int main()
{
  cin >> n >> dist;
  scanf("%s", s);
  long long  i = 0, val = 0;
  
   //cout << val << endl;
   if (dist > 25 * n)
   {
 	cout << -1<<endl;
   	return 0;
   }
   i = 0;
   
   while(dist >= 0)
   {
      if (abs('a' - s[i]) > abs('z' - s[i]) )
      {
      	a[i] = 'a';
      	dist -= abs('a' - s[i]);
 		}
      else {

      	a[i] = 'z';
      	dist -= abs('z' - s[i]);
  
      }

      i++;
   }
  
   i--;
    if (abs('a' - s[i]) > abs('z' - s[i]) )
      {
      	dist += abs('a' - s[i]);
 		}
      else {

      	dist += abs('z' - s[i]);
      }
   //cout << n << endl;
   
   if (search(i,0)){
   	a[n] = '\0';
   	printf("%s\n", a);
   }
   else cout << -1 << endl;

   
  


  return 0;
}