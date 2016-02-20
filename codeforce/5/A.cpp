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
int num[] = {1,2,4,8,16,32,64,128,256};
int max2(int n)
{
	
    for(; n>=1; n--)
     {
     	for(int i = 8; i >= 0; i--)
     	{
     		if (n == num[i])
     			return n;
     		if (n > num[i])
     			break;
     	}
     }

return n;
}

int main()
{
	int n, b, p, x=0, y=0;
	cin >> n >> b >> p;
    
    y = p * n;
	while(n != 1)
	{

		int k = max2(n);
		n = n- k + k/2;
        x += k * b + k/2;
        //cout << x << endl;

	}
  
    cout << x <<" "<<y << endl;
  return 0;
}