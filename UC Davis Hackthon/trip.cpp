#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <vector>
#include <climits>

#define SIZE 1000
using namespace std;

struct City
{
  int adj[SIZE];
  int cost;
};



int main()
{
  int n, m, i;
  int a,b,c;
  cin >>n>> m;
  City *city = new City[n];
  
  for(i = 0; i < n; i++)
  {
    city[i].cost = INT_MAX;
    memset(city[i].adj, 0, SIZE*sizeof(int));
  }
  
  city[0].cost = 0;
  
  for(i = 0; i < m; i++)
  {
    cin >> a>>b>>c;
    city[a-1].adj[b-1] = c;
  }
  

  auto compareFunc = [](int a, int b) { return a < b; };
  priority_queue<City, vector<City>, decltype(compareFunc> list(city[0], city[n-1]);
  
  
  

  return 0;
}