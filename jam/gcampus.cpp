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
#include <exception>

using namespace std;

const long long inf = (1LL << 56);
long long cost[100][100];
long long dist[100];
int visit[100];
long T, N, M;

long long dijkstra (int source, int final)
{
  for (int i = 0; i < N; i ++)
    dist[i] = inf;
  
  memset(visit, 0, sizeof(visit));
  dist[source] = 0;
  
  for (int j = 0 ; j < N; j++)
  {
    int min = -1;
    for (int i = 0; i < N; i++)
    {
      if (visit[i]) continue;
      if (min == -1  || dist[min] > dist[i])
        min = i;
      
    }
    for (int i = 0; i < N; i++)
    {
      long long path =dist[min] + cost[min][i];
      if (path < dist[i] )
        dist[i] = path;
      
    }
    visit[min] = 1;
    
  
  }
  return dist[final];
}

class road{
public:
  int origin;
  int des;
  long long dis;
  road(int a, int b, long long c)
  {
    origin = a;
    des = b;
    dis = c;
  }
  
  
};

int main()
{
  
  long long a ,b ,c;
  
  cin >> T;
  for (int t = 1 ; t <= T; t++)
  {
    set<int> ine;
    vector<road> roads;
    
    cout << "Case #"<<t<<":\n";
    cin >> N >> M;
    
    ine.clear();
    roads.clear();
    
    for (int i = 0; i < 100; i++)
      for (int j = 0; j < 100; j++)
      {
        if (i == j){
          cost[i][j] = 0;
        }
        else cost[i][j] = inf;
      }
    int kk = M;
    while(kk--)
    {
      cin >> a >> b >> c;
      road temp(a,b,c);
      roads.push_back(temp);
      if (c < cost[a][b])
      {
        cost[a][b] = c;
        cost[b][a] = c;
      }
    }
    
    for (int k = 0; k < M; k++)
    {
    
      long long temp =  dijkstra(roads[k].origin, roads[k].des);
      if (temp < roads[k].dis) ine.insert(k);
    }
    
    for (auto it = ine.begin(); it != ine.end(); it++)
      cout << *it << endl;
  }
  
  return 0;
}