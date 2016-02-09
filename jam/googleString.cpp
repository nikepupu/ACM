#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>


template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;


int main()
{

  int T;
  long long K, count = 0, n = 0,mid,temp;


  cin >> T;
  for (int i = 1; i <= T; i++ )
  {
    cout << "Case #"<<i << ": ";
    cin >> K;
   
    count = 0;
    while (  K > 1)
    {
      if(pow(2, (int)log2(K) ) == K ){
        //cout << "K" << K;
        break;
        
      }
      n = log2(K-1);
      mid = pow(2,n);
      K = 2*mid -K;
      
      count ++;
    }
    if (count % 2 ==0)
    cout << 0<< endl;
    else cout << 1 << endl;
  }
  
  return 0;
}