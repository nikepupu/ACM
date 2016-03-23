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

int res;
void search( int cnt, vector<int> cake, int status, int start)
{
	int sum = 0;
	int len = cake.size();
	for(int i = 0; i < len; i++)
		sum += cake[i];
	if (sum == 0)
	{
		res = min(res, cnt);
		return;
	}
	if (cnt + 1 >= res)
		return;
	if (status == 0){
	vector<int >  temp;
	for(int i = start; i < len; i++){
	for(int j = 1; j < cake[i]; j++)
	{
	  for(int k =1; k <= j; k++)
	  {
	  	temp.resize(len);
		for(int p = 0; p < len; p++)
			temp[p]= cake[p];
	  	temp[i] = temp[i] -k;
	  	temp.push_back(k);
	  	search(cnt+1, temp, 0,start+1);
	  }

	}

	}
}
	
	  for(int i = 0; i < len; i++)
	  	if(cake[i] > 0)
	  		cake[i]--;

	  	search(cnt+1, cake, 1, start);
}

int main()
{
  int T;
  vector<int> cake;
  cin >> T;
  
  for(int k = 1; k <= T; k++)
  {
    cout << "Case #"<<k<<": ";
    
    int n;
    cin >> n;
    cake.clear();
    int m = -1;
    for(int i = 0; i < n; i++){
    	int temp; 
    	cin >> temp;
    	m = max(m, temp);
    	cake.push_back(temp);
    }
    res = m;
    search(0, cake, 0, 0);

    cout << res << endl;
    
    
  }

  return 0;
}