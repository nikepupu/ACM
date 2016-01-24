#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int m, n;

struct board{
  vector<vector<int> > matrix;
  int step;
};

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

bool terminal(board temp)
{
  
  int i, j;
  for (i = 0; i < n; i++ )
  {
    for(j = 0; j < m; j++)
    {
      if (!is_prime(temp.matrix[i][j]) )
        break;
    }
    
    if (j == m)
      return true;
  }
  
  
  for (j = 0; j < m; j++ )
  {
    for(i = 0; i < n; i++)
    {
      if (!is_prime(temp.matrix[i][j]) )
        break;
    }
    
    if (i == n)
      return true;
  }
  
  return false;
  
}

int main()
{
  cin >> n >> m;
  int a;
  vector<int> k;
  board b, temp;
  b.step = 0;
  
  for (int i = 0; i < n; i++ )
  {
    b.matrix.push_back(k);
    for(int j = 0; j < m; j++)
    {
     
     cin >> a;
     b.matrix[i].push_back(a);
    }
    
  }
  
  queue<board> bfs;
  bfs.push(b);
  
  while(1)
  {
    temp =  bfs.front();
    if (terminal(temp))
      break;
    
    bfs.pop();
    temp.step += 1;
    for (int i = 0; i < n; i++ )
    {
      for(int j = 0; j < m; j++)
      {
        temp.matrix[i][j] += 1;
        bfs.push(temp);
        temp.matrix[i][j] -= 1;
      }
      
    }
  }
  
  cout << temp.step;
  
  return 0;
}