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
int n;
int range1[367]={0};
int range2[367]={0};
int guest = 0;
/*bool search(int num, int index)
{
	guest = max(guest, num);
	for(int i = index; i < M.size()/2)
		for(int j = 0; j <F.size()/2; j++){
			if (used[j]) continue;

		}
}*/

int main()
{
  int temp1, temp2;
  char c;
  cin >> n;
  cin.get();
  for(int p = 0; p < n; p++)
  {
	cin >> c;
  	if (c == 'M')
  	{
  		cin >> temp1;
  		cin >> temp2;
  		for(int i = temp1; i <= temp2; i++)
  			range1[i]++;
  	
  	}
  	else 
  	{
  		cin >> temp1;
  		cin >> temp2;
  		for(int i = temp1; i <= temp2; i++)
  			range2[i]++;
  	
  	}


  	cin.get();
	}
	
	
	for (int i = 0; i <= 366; i++)
			if(range1[i] > guest && range2[i] > guest)
				guest = min(range1[i], range2[i]);
	
	cout << guest*2 << endl;

	
  return 0;
}