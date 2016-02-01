#include <iostream>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;


vector<string> final(3);

struct board{
  vector<string> matrix;
  string move;
  int x;
  int y;
};


bool terminal(board temp)
{
  
  if (final[0] == temp.matrix[0] && final[1] == temp.matrix[1] && final[2] == temp.matrix[2] )
    return true;
  
  return false;
  
}

int main()
{
  board b, temp, temp2;
  char c;
  b.matrix.reserve(3);
  final[0] = "123";
  final[1] = "456";
  final[2] = "78x";
  
  for (int i = 0; i < 3; i++ )
  {
    for(int j = 0; j < 3; j++)
    {
      cin >> b.matrix[i][j];
      if(b.matrix[i][j] == 'x')
      {
        b.x = i;
        b.y = j;
      }
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
   
    if(temp.x != 0) // left
    {
      temp2 = temp;
      cout << "temp2:" << temp.matrix[1][1];
      char a = temp2.matrix[temp.x][temp.y];
      temp2.matrix[temp.x][temp.y] = temp2.matrix[temp.x][temp.y-1];
      temp2.matrix[temp.x][temp.y-1] = a;
      temp2.move += 'l';
      temp2.x -= 1;
      bfs.push(temp2);
      
    }
    
    if(temp.x != 2) // right
    {
      memcpy(&temp2, &temp,sizeof(board));
      char a = temp2.matrix[temp.x][temp.y];
      temp2.matrix[temp.x][temp.y] = temp2.matrix[temp.x][temp.y+1];
      temp2.matrix[temp.x][temp.y+1] = a;
       temp2.move += 'r';
      temp2.x += 1;
      bfs.push(temp2);
    }
    
    if(temp.y != 0) // up
    {
       memcpy(&temp2, &temp,sizeof(board));
      char a = temp2.matrix[temp.x][temp.y];
      temp2.matrix[temp.x][temp.y] = temp2.matrix[temp.x-1][temp.y];
      temp2.matrix[temp.x-1][temp.y] = a;
       temp2.move += 'u';
      temp2.y -= 1;
      bfs.push(temp2);
    }
    
    if(temp.y != 2) // down
    {
      memcpy(&temp2, &temp,sizeof(board));
      char a = temp2.matrix[temp.x][temp.y];
      temp2.matrix[temp.x][temp.y] = temp2.matrix[temp.x+1][temp.y];
      temp2.matrix[temp.x+1][temp.y] = a;
      temp2.move += 'd';
      temp2.y += 1;
      bfs.push(temp2);
    }
        
    
  }
  
  cout << temp.move;
  
  return 0;
}