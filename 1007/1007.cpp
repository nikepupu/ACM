#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int DNAsize, DNAnum;

class DNA {
public:
  int unsortness;
  char sequence[55];
  
  DNA()
  {
    cin.getline(sequence, 55);
    unsortness = calculateUnsortness();
  }

  
 int calculateUnsortness()
 {
   int i, j;
   int count = 0;
   for(i = 0; i < DNAsize; i++)
   {
     for(j = i + 1; j < DNAsize; j++)
       if(sequence[i] > sequence[j])
         count++;
     
   }
   return count;
 }
  

};

int compare(DNA *a, DNA* b)
{
  return a->unsortness < b->unsortness;
}
int main()
{
  int i;

  cin>> DNAsize >> DNAnum;
  cin.get();
  DNA *DNAbook[100];
  for (i = 0; i < DNAnum; i++)
  {
    DNAbook[i] = new DNA();
  }
 
  stable_sort(DNAbook, DNAbook+DNAnum, compare);
  
  for (i = 0; i < DNAnum; i++)
    cout << DNAbook[i]->sequence<<endl;
  
  return 0;
}