#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>

using namespace std;

char dp[201][201][201];
void search(int p1, int p2,int p3)
{

  if(dp[p1][p2][p3])
    return ;
  
  dp[p1][p2][p3] = 1;
  if(p1 + p2 + p3 == 1)
    return;
  
  if(p1 && p2) search(p1-1,p2-1,p3+1);
  if(p1 && p3) search(p1-1,p2+1,p3-1);
  if(p2 && p3) search(p1+1,p2-1,p3-1);
  if(p1 >= 2) search(p1-1,p2,p3);
  if(p2 >= 2) search(p1,p2-1,p3);
  if(p3 >= 2) search(p1,p2,p3-1);
  
  return;
}

int main()
{
  int m;
  char c;
  int count[3]={0};
  cin >> m;
  while(m--)
  {
    cin >> c;
    
    if( c == 'B' )
      count[0]++;
    else if(c == 'G')
      count[1]++;
    else if (c == 'R')
      count[2]++;
  }
  
  memset(dp,0,sizeof(dp));
  search(count[0],count[1],count[2]);

  if (dp[1][0][0]) cout <<"B";
    if (dp[0][1][0]) cout <<"G";
    if (dp[0][0][1]) cout <<"R";
  cout << endl;
  
  return 0;
}