#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>


using namespace std;



bool DFS(int cur_length, int cnt, int cur_index, int goal, int *cuts, bool *used, int numberOfCuts, int sum)
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
      if(DFS(0, cnt+1,0, goal, cuts, used, numberOfCuts, sum) )
        return true;
      
      used[i] = 0;
      
    }
    
    if (cur_length + cuts[i] < goal)
    {
     
      if(DFS(cur_length + cuts[i], cnt, i+1, goal, cuts, used, numberOfCuts, sum))
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
  return  a > b;
}


int main()
{
  
  int sum ;
  int numberOfCuts;
  int cuts[128];
  bool used[128];
  int goal;
  
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
    cout<< cuts[0]<<endl;
   
    for(goal = cuts[0]; goal <= sum; goal++)
    {
      
      if(sum % goal == 0)
      {
        memset(used, 0, sizeof(used));
        
        if( DFS(0, 0, 0, goal, cuts, used, numberOfCuts, sum) )
        {
          cout << goal << endl;
          break;
        }
      }
      
    }

   
  }
 
  return 0;
}

