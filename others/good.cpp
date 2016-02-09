#include <iostream>
#include <vector>
using namespace std;

int good[] = {1, 2, 3, 3, 4, 10};
int bad[] = {1, 2, 2, 2, 3, 5, 10};



int main() {
  int T,a;
  cin >> T;
  int G,B;
  for (int i = 1; i <= T; i++)
  {
    cout << "Battle "<<i<<": ";
    G=0, B=0;
    cin >> a;
    G += a * good[0];
    cin >> a;
    G += a * good[1];
    cin >> a;
    G += a * good[2];
    cin >> a;
    G += a * good[3];
    cin >> a;
    G += a * good[4];
    cin >> a;
    G += a * good[5];
    
    cin >> a;
    B += a * bad[0];
    cin >> a;
    B += a * bad[1];
    cin >> a;
    B += a * bad[2];
    cin >> a;
    B += a * bad[3];
    cin >> a;
    B += a * bad[4];
    cin >> a;
    B += a * bad[5];
    cin >> a;
    B += a * bad[6];
    if (G < B)
      cout << "Evil eradicates all trace of Good\n";
    else if (G > B)
      cout <<"Good triumphs over Evil\n";
    else
      cout << "No victor on this battle field\n";
    
  }
  return 0;
}
