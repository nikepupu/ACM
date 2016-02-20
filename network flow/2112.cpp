#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>


using namespace std;

int K,C,M;
int cap[250][250];
int cost[250][250];
int rGraph[250][250];
bool vis[250];
int parent[250];
const int inf = (1 << 26);


int bfs()
{
  queue<int> q;
  memset(vis, 0, sizeof(vis));
  memset(parent, 0, sizeof(parent));
  q.push(0);
  vis[0] = true;
  
  while(!q.empty() )
  {
    int u = q.front(); q.pop();
    for(int i = 0; i <= K+C+1; i++)
      if ( !vis[i] && rGraph[u][i] > 0 )
      {
        q.push(i);
        parent[i] = u;
        vis[i] = true;
      }
  }
  
  return vis[K+C+1];
  
}


int main()
{
  int total = 0;
  cin >> K>> C >> M;
  memset(cap, 0, sizeof(cap));
  
  for (int i = 1; i <= K; i++ )
    cap[0][i] = M;
  
  for(int i = 1; i <= K; i++)
    for (int j = K +1; j <= K+C; j++)
      cap[i][j] = 1;
  
  for(int i = K+1; i <= K+C; i++)
    cap[i][K+C+1] = 1;
  
  memset(cost, 0, sizeof(cost));
  
  for(int i = 1; i <= K+C; i++)
    for(int j = 1; j <= K+C; j++)
    {
      cin >> cost[i][j];
      if(i != j && cost[i][j] == 0 )
        cost[i][j] = inf;
    }
    
  for(int k = 1; k <= K+C; k++)
    for(int i = 1; i <= K+C; i++)
      for(int j = 1; j <= K+C; j++)
          cost[i][j] = min (cost[i][j], cost[i][k] + cost[k][j] );
    
    int low = 0, high = 200*(K+C);
    int ans, mid;
    
    while(low <= high) // loop
  {
    mid = (low + high)/2;
    total = 0;
    memcpy(rGraph, cap, sizeof(rGraph));
    
    
    for(int i = 1; i <= K+C; i++)
      for(int j = 1; j <= K+C; j++)
      {
        if (cost[i][j] > mid){
          rGraph[i][j] = 0;
        }
      }
  
    while(bfs())
    {
      int maxFlow = inf;
      for (int v = K+C+1; v != 0; v = parent[v] )
        maxFlow = min(maxFlow, rGraph[parent[v]][v]);
    
      for(int v = K+C+1; v!= 0; v=parent[v])
      {
        rGraph[parent[v]][v] -= maxFlow;
        rGraph[v][parent[v]] += maxFlow;
      }
      total += maxFlow;
   
    }
    
    if(total == C)
    {
      ans = mid;
      high = mid-1;
    }
    else
      low = mid + 1;
    

  }
    cout << ans << endl;
  
  


  return 0;
}