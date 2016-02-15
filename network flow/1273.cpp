#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <queue>
using namespace std;

const long long inf = (1LL << 56);
int N;//edge
int M; // vertex
long long cap[250][250];
long long rGraph[250][250];
bool visited[250];
int parent[250];

long long total;

int bfs()
{
  queue<int> q;
  memset(visited, 0, sizeof(visited));
  memset(parent, 0, sizeof(parent));
  q.push(0);
  visited[0] = true;
  parent[0] = -1;
  
  while(!q.empty() )
  {
    int u = q.front(); q.pop();
    for(int i = 0; i < M; i++)
      if ( !visited[i] && rGraph[u][i] > 0 )
      {
        q.push(i);
        parent[i] = u;
        visited[i] = true;
      }
  }
  
  return visited[M-1];
  
}


int main()
{
  while(1)
  {
    total = 0;
    memset(cap, 0, sizeof(cap));
    long long maxFlow;
    cin >> N;
    if (cin.eof() )
      return 0;
  
    cin >> M;
    int a, b, c;

    for (int i = 0; i < N; i++)
    {
      cin >> a >> b >> c;
      cap[a-1][b-1] += c;
    }
    memcpy(rGraph, cap, sizeof(cap));
  
  
    while(bfs())
    {
    
      maxFlow = inf;
      for (int v = M-1; v != 0; v = v[parent])
        maxFlow = min(maxFlow, rGraph[parent[v]][v]);
    
      //cout << maxFlow << endl;
    
      for(int v = M-1; v != 0; v = parent[v] )
      {
        rGraph[parent[v]][v] -= maxFlow;
        rGraph[v][parent[v]] += maxFlow;
      }
      total+=maxFlow;
    
    }
  
    cout << total<<endl;
  }

}