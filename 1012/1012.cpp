#include <iostream>
#include <list>

using namespace std;

int k;
list<int> circle;
int n;
int num;

void constructList()
{
  for (int i = 1; i <= n; i++)
    circle.push_back(i);
}

bool search(int m)
{
  constructList();
  num = 0;
  list<int>::iterator it = circle.begin();
  
  int i = 1;
  while(1)
  {
    
    if(i % m == 0)
    {
      if ( (*it) <= k)
      {
        circle.clear();
        return false;
      }
      
      num++;
      if (num >= k)
        return true;
      
      it = circle.erase(it);
      
      if (it == circle.end() )
        it = circle.begin();
      
      i++;
    }
    
    else
    {
      it++;
      if (it == circle.end() )
        it = circle.begin();
      i++;
      
    }
  }

}


int sol[13] = {2, 7, 5, 30, 169, 441, 1872, 7632, 1740, 93313, 459901, 1358657, 2504881};

int main()
{
  while(cin>> k &&  k != 0)
  {
    //n = 2*k;
    
    
    /* actual code
    for (int i = k+1; ; i++)
    {
      if (i % (k + 1) == 0 || i %(k + 1) == 1)
      if (search(i))
      {
        cout << i <<endl;
        break;
      }
      
    
    }*/
  
    cout << sol[k-1] << endl;
  }
  
  return 0;


}