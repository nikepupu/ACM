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
long long num = 0;
string a;
int main()
{
   cin >> a;
   long long length = a.length();
   long long odd = 0, even = 0;
   for(long long i = 1; i < length; i++)
   {
   	

   		if (a[i-1] % 2 == 0 &&( a[i] == '4' || a[i] == '8'||a[i] == '0' ))
   		{
   			num += i+1;
   			//cout << num << endl;
   		}
   		else if (a[i] == '0' || a[i] == '4' || a[i] == '8')
   			num++;
   		else if ( a[i-1] % 2 && (a[i] == '2'||a[i] =='6') )
   		{	
   			num += i;
   			//cout << "2:"<< num << endl;
   		}


   }
   		if (a[0] == '0' || a[0] == '4' || a[0] == '8')
   			num++;
 	
  

cout << num<<endl;
  return 0;
}