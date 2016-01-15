#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int packet[6];

int min(int a, int b)
{
  if (a < b)
    return a;
  else
    return b;
}


int main()
{
  int i;
  int status, space;
  int num;
  while(1)
  {
    status = 0;
    num = 0;
    
    for(i = 0; i <= 5; i++)
    {
      cin >> packet[i];
      if(packet[i] > 0)
        status = 1;
    }
    
    if(status == 0)
      break;
    
    
      
      if (packet[5]) // 6 * 6
      {
        num += packet[5];
        packet[5] = 0;
      }
      
      
     while(packet[4]) // 5 * 5
      {
        num++;
        packet[0] -= min(packet[0], 11);
        packet[4]--;
      }
      
      while(packet[3]) // 4 * 4
      {
        space = 20;
        num++;
        
        if (packet[1])
        {
          int  a = min(packet[1],5);
          space -= a * 4;
      
        }
        
        packet[0] -= min(packet[0],space);
        
        packet[3]--;
      }
    
      while(packet[2])// 3 * 3
      {
        space = 36;
        int a = min(packet[2], 4);
        packet[2] -= a;
        space -= 9 * a;
        if (a == 1)
        {
          int  b = min(packet[1],5); // 2 * 2
          space -= 4 * b;
          packet[1] -= b;
          
          
          packet[0] -= min(packet[0],space);
        }
        
        else if (a == 2)
        {
          int  b = min(packet[1],3);
          space -= 4 * b;
          packet[1] -= b;
          packet[0] -= min(packet[0],space);
        }
        
        else if (a == 3)
        {
          if (packet[1])
          {
            packet[1] -= 1;
            space -= 4;
          }
          packet[0] -= min(packet[0],space);
        }
        
        
       
        num++;
      }
      
      
      while (packet[1]) // 2 * 2
      {
        space = 36;
        space -= 4 *( min(packet[1],9) );
        packet[1] -= min(packet[1], 9);
        packet[0] -= min(packet[0],space);
        num++;
      }
      
      if (packet[0])//1 * 1;
      {
        num += (packet[0]/36 + 1);
      }
    
      cout << num << endl;
    
  }// while(1)
  
  return 0;
}