#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int N,K;

int used[55];
int value[55];

bool DFS(int cur, int index, int count)
{
  if (cur == K)
    return true;
  
  for(int i = index; i < N; i++)
  {
    if (used[i]) continue;
    
    if (cur + value[i] - count > K) continue;
    
    if (cur + value[i] - count <= K)
    {
      used[i] = 1;
      if(DFS(cur + value[i] - count, i+1, count + 1 ) )
        return true;
      
      used[i] = 0;
      
    }
    
  }
  
  return false;
}

int main()
{
  cin>>N>>K;
  memset(used, 0, 55*4);
  char* AB = new char[N];
  
  for(int i = 0; i < N; i++)
    value[i] = N - i - 1;
  
  if( DFS(0, 0, 0))
  {
    for (int i = 0; i < N; i++)
    {
      if(used[i])
        AB[i] = 'A';
      else
        AB[i] = 'B';
    }
    
    cout << AB <<endl;
  }
  
  else
  {
    cout <<" "<<endl;
    
  }
    
 
  return 0;
}
