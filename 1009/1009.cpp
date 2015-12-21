#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

int main()
{
  int width, i;
  int code, codeLength;
  int len;
  int *image;
  unsigned short image[1000000000];
  
  while(cin>>width && width != 0)
  {
    i = 0;
    // read in
    do{
      cin>>code >> codeLength;
      len = codeLength;
      if (codeLength > 2 * width)
      while(len--)
        width[i++] = code;
      
      
    } while(code != 0 || codeLength != 0);
    
    
    
    
  }
  
  
  

  return 0;
}