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


using namespace std;

int N, M;
const long long inf = (1LL << 56);
long long cap[500][500];
long long rGraph[500][500];
bool visited[500];
int parent[500];

bool bfs()
{
  memset(visited, 0, sizeof(visited));
  memset(parent, 0, sizeof(parent));
  
  queue<int> q;
  q.push(0);
  visited[0]=1;
  parent[0]=-1;
  
  while(!q.empty())
  {
    int u = q.front(); q.pop();
    //cout << "u: " << u << endl;
    for(int i = 0; i <= M+M+1; i++)
      if( !visited[i] && rGraph[u][i] > 0)
      {
        q.push(i);
        parent[i]=u;
        visited[i]=true;
      }
  }
  
  return visited[N+M+1];

}

int main()
{
  while(1){
  int total = 0;
  string str;
  cin >> N;
    if(cin.eof())
      return 0;
  cin >> M;
  int temp;
  memset(cap, 0, sizeof(cap));
  
  for (int i = 1; i <= N; i++)
    cap[0][i] = 1;
  
  for (int i = 1; i <= N; i++)
  {
    int count;
    cin >> count;
    for (int j = 1; j <= count; j++)
    {
      cin >>temp;
      cap[i][temp+N] = 1;
    }
    
  }
  
  for(int i = N+1; i <= N+M; i++)
    cap[i][N+M+1] = 1;
    
  memcpy(rGraph, cap, sizeof(rGraph));
  
  while(bfs())
  {
   
    long long maxFlow = inf;
    for(int v = N+M+1; v != 0; v= parent[v])
      maxFlow = min(maxFlow, rGraph[parent[v]][v]);
      
    for(int v= N+M+1; v != 0; v = parent[v] )
    {
      rGraph[parent[v]][v] -= maxFlow;
      rGraph[v][parent[v]] += maxFlow;
    }
    total += maxFlow;
  }
  cout << total<<endl;
  }
  
}