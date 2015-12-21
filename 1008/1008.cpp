#include <iostream>
#include <cstring>
#include <cstdlib>

char Tz2[20][10] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};

char Haab2[19][10] = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
using namespace std;

class Haab
{
public:
  int day;
  int month;
  int year;
  int days;
  
  Haab()
  {
    char str[256];
    char *m;
    cin.getline(str,256);
    day = atoi(strtok(str, "."));
    m = strtok(NULL , " ");
    year = atoi(strtok(NULL,""));
    month = findMonth(m);
    //cout << day << endl << month <<endl << year << endl << endl;
    days = day + 20 * month + year * 365;
    convert();
  }
  
  int findMonth(char *m)
  {
    for(int i = 0; i < 19; i++)
    {
      if (strcmp(m, Haab2[i]) == 0)
        return i;
    }
  }
  
  void convert()
  {
    int y = days/260;
    int d, m;
 
    d = days %13 + 1 ;
    m = days%20 ;
    cout << d << " " << Tz2[m] <<" " << y<<endl;
    
  }
  
  
};

int main()
{
  int n;
  int i = 0;

  cin >> n;
  cin.get();
  Haab **habbList = new Haab*[n];
  cout << n << endl;
  while(n--)
  {
    habbList[i++] = new Haab();
    
  }
  
  
  
  

  return 0;
}