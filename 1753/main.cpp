#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>

using namespace std;

int m = 1000;

void flip(int x, int y,vector< vector<char> > &a)
{
    
	if (a[x][y] == 'w')
		a[x][y] = 'b';
	else
	 a[x][y] = 'w';

	if (a[x-1][y] == 'w')
		a[x-1][y] = 'b';
	else 
		a[x-1][y] = 'w';

	if (a[x+1][y] == 'w')
		a[x+1][y] = 'b';
	else 
		a[x+1][y] = 'w';

	if (a[x][y-1] == 'w')
		a[x][y-1] = 'b';
	else 
		a[x][y-1] = 'w';

	if (a[x][y+1] == 'w')
		a[x][y+1] = 'b';
	else 
		a[x][y+1] = 'w';

}

void solve(vector< vector<char> > board, int cnt, char goal, int kk)
{

	int temp = cnt;
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 4; j++)
		{
			if (board[i][j] != goal)
			{	
				flip(i+1, j, board);
				cnt++;
			}
		}

	for(int i = 1; i <= 4; i++)
	  if (board[4][i] != goal)
	      return;

	  m = min(m, cnt);
	  //cout << m << endl;

}

void search (vector< vector<char> > board, int index, int count, char goal)
{
	vector < vector<char> > tempBoard;
	for(int i = 0; i <= 15; i++ )
	{
		tempBoard = board;
		int s[4];
		int temp = i;
		s[0] = temp%2;
		temp /= 2;
		s[1] = temp%2;
		temp /= 2;
		s[2] = temp%2;
		temp /= 2;
		s[3] = temp%2;

		int sum = 0;

		for(int j = 0; j < 4; j++)
			if (s[j] == 1)
			{
				flip(1, j+1, tempBoard);
				sum++;
			}
		solve(tempBoard, sum, goal, i);
	}
}

int main()
{
  vector< vector<char> > a(6);
  for(int i = 0; i < 6; i++)
  	a[i].resize(6);
  
  for(int i = 1; i <= 4; i++ )
  	for(int j = 1; j <= 4; j++)
  		cin >> a[i][j];

  	search(a, 1,0,'w');
  	search(a, 1,0,'b');

  	if (m == 1000)
  		cout <<"Impossible\n";
  	else
  		cout << m << endl;

  return 0;
}