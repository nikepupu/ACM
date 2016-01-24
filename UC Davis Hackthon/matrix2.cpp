#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int m, n;
const int inf = 1 << 10;


bool is_prime(int n)
{
  if (n < 2)
    return false;
  
  if (n < 4)
    return true;
  
  else if (n % 2 == 0 || n % 3 == 0)
    return false;
  
  int i = 5;
  
  while(i * i < n)
  {
    if (n %i == 0 || n % (i + 2) == 0)
      return false;
    
    i += 6;
  }
  
  return true;
}

int main()
{
  cin >> n >> m;
  int sum, cur1, cur2, count, temp;
  vector<vector<int> > matrix(n, vector<int>(m));
  vector<vector<int> > dist(n, vector<int>(m));
  
  for (int i = 0; i < n; i++ )
    for(int j = 0; j < m; j++)
      cin >> matrix[i][j];
  
  
  for (int i = 0; i < n; i++ )
    for(int j = 0; j < m; j++)
    {
      temp = matrix[i][j], count = 0;
      while(1)
      {
        if (is_prime(temp))
          break;
        temp++;
        count++;
        
      }
      dist[i][j] = count;
    }
  
  
  cur1 = inf;
  for (int i = 0; i < n; i++ )
  {
    sum = 0;
    
    for(int j = 0; j < m; j++)
    {
      sum += dist[i][j];
    }
    if (sum < cur1)
      cur1 = sum;
  }
  

  cur2 = inf;
  for (int j = 0; j < m; j++ )
  {
    sum = 0;
    for(int i = 0; i < n; i++)
    {
      sum += dist[i][j];
    }
    if (sum < cur2)
      cur2 = sum;
  }
  
  if (cur1 > cur2)
    cout << cur2;
  else
    cout << cur1;
  
  return 0;
}