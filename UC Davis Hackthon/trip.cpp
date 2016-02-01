#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>


using namespace std;

const int inf = 1 << 10;

int main()
{
  int n, m, i, j;
  int a,b,c,cur;
  
  cin >> n >> m;
  
  vector<vector<int> > adj(n);
  
  vector<int> dist(n);
  vector<bool> vis(n);
  
  for(i = 0; i < n; ++i) {
    adj[i] = vector<int>(n);
    for(j = 0; j < n; ++j) {
      adj[i][j] = inf;
    }
  }
  
  for (i = 0; i < n; i++)
    dist[i] = inf;
  
  
  dist[0] = 0;
  
  while(m--)
  {
    cin >> a >> b >> c;
    if (adj[a-1][b-1] > c)
    adj[a-1][b-1] = c;
  }
  
  for (i = 0; i < n; i++)
  {
    cur = -1;
    for (j = 0; j < n; j++)
    {
      if( vis[j] ) continue;
      if (cur == -1 || dist[j] < dist[cur])
        cur = j;
    }
    
    vis[cur] = 1;
    
    for (j = 0; j < n; j++)
    {
      int path = dist[cur] + adj[cur][j];
      if (path < dist[j])
        dist[j] = path;
    
    }
    
  }
  
  if (dist[n-1] < inf)
    cout << dist[n-1];
  else
    cout << -1;
    
  

  return 0;
}