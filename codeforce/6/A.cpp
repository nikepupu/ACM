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

char cake[100][100];

int main()
{
  int n;
  cin >> n;
  cin.get();
  for(int i = 0; i < n; i++){
  	for(int j = 0; j < n; j++)
  		cin >> cake[i][j];
  	cin.get();
  }

int num = 0;
for(int i = 0; i < n; i++){
  	for(int j = 0; j < n; j++)
  	 if (cake[i][j] == 'C')
  	 {
  	 	for(int k = i+1; k < n; k++)
  	 		if(cake[k][j] == 'C') num++;
  	 	for(int k = j+1; k < n; k++)
  	 		if(cake[i][k] == 'C') num++;

  	 }
  }  

cout << num << endl;
  return 0;
}