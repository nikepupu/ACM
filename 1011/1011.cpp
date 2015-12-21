#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>


using namespace std;

int sum ;
int numberOfCuts;
int cuts[128];
bool used[128];
int goal;

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
    
    else if (cur_length + cuts[i] < goal)
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



bool compare(int a, int b)
{
  return  a < b;
}


int main()
{
  
  int i;
  
  
  while( cin >> numberOfCuts && numberOfCuts)
  {
    sum = 0;
    
    for(i = 0; i < numberOfCuts; i++)
    {
      cin >> cuts[i];
      sum += cuts[i];
    }
    
    sort(cuts, cuts + numberOfCuts,  compare);

   
    for(goal = cuts[0]; goal <= sum; goal++)
    {
      
      if(sum % goal == 0)
      {
        memset(used, 0, sizeof(used));
        
        if( DFS(0, 0, 0) )
        {
          cout << goal << endl;
          break;
        }
      }
      
    }

   
  }
 
  return 0;
}

