#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <vector>


using namespace std;

int matrix[500][500];
int n,m;

char test[500];
bool DFS(int pos, char c)
{
  if (pos)
  {
    test[pos-1] = c;
  }
  

  for(int i = 0; i < pos-1;i++)
  {
    
    if(matrix[pos-1][i])
    {
      if(abs(test[i]-c) == 2)
      {
        return false;
      }
    }
    else{
      
      if(c == 'b')
        return false;
      if(abs(test[i]-c)!=2 )
        return false;
     
    }
    
  }
  
  
  if(pos == n)
  {
    test[pos] = '\0';
    return true;
  }
  
  
  if (DFS(pos+1, 'a'))
    return true;
  else if(DFS(pos+1,'b'))
    return true;
  else if(DFS(pos+1, 'c'))
    return true;
  
  return false;
  
}


int main()
{
  
  int v1, v2;
  memset(matrix,0,sizeof(matrix));
  cin >> n >> m;
  string res;
  for (int i = 1 ; i <= m; i++)
  {
    cin >> v1 >> v2;
    matrix[v1-1][v2-1]=1;
    matrix[v2-1][v1-1]=1;
    
  }

  if(DFS(0,'a'))
    cout <<"Yes"<<endl<<test<<endl;
  else
    cout <<"No"<<endl;
  return 0;
}