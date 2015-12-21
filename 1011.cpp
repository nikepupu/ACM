#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

int sum ;
int numberOfCuts;
int cuts[1024];
int used[1024]= {0}; // 0 means untested, 1 means pending, 2 works, 3 means waiting/not working
int goal = 0;

bool DFS(int cur_length, int cnt, int cur_index)
{
  if(sum == cnt * goal)
    return true;
  
  for(int i = cur_index; i < numberOfCuts; i++ )
  {
    
    if(used[i]) continue;
    if (i && !used[i-1] && (cuts[i-1] == cuts[i]) ) continue;
    if(cur_length+cuts[i] > goal) continue;
    
    used[i] = 1;
    
    if (cur_length + cuts[i] == goal)
    {
      if(DFS(0, cnt+1,0) )
        return true;
      
      used[i] = 0;
    }
    
    if (cur_length + cuts[i] < goal)
    {
     
      if(DFS(cur_length + cuts[i], cnt, i+1))
        return true;
      
      else
      {
        used[i] = 0;
        if(cur_length == 0)
          return false;
      }
        
    }
    
  }
  
  return false;
}

void sort()
{
  int i, j, k;
  for(int i = 1; i < numberOfCuts; i++)
  {
    k = cuts[i];
    j = i-1;
    while(j >= 0 && cuts[j] < k )
    {
      cuts[j+1] = cuts[j];
      j--;
    }
    cuts[j+1] = k;
  }
}


int main()
{
  
  
  int start = clock();
  int i;
  
  cin >> numberOfCuts;
  
  while(numberOfCuts)
  {
    sum = 0;
    
    for(i = 0; i < numberOfCuts; i++)
    {
      cin >> cuts[i];
      sum += cuts[i];
    }
     sort();
    
    // find factors
    for(goal = cuts[0]; goal <= sum; goal++)
    {
      
      if(sum % goal == 0)
      {
        
        if( DFS(0, 0, 0) )
        {
          cout << goal << endl;
          break;
        }
      }
      
    }

    memset(used, 0, 4*numberOfCuts);
    cin >> numberOfCuts;

    
  }
  int end = clock();
  cout <<"time: "<< (end - start)/CLOCKS_PER_SEC << endl;
  return 0;
}

