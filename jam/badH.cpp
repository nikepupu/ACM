#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <map>
#include <fstream>
template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;

map <string, vector<string> > graph;
map <string, int> color;
queue <string> bfs;

int main()
{
  //ifstream in("test.txt");
  int T, M, status;
  string str1, str2;
  cin >> T;
  for (int ii = 1; ii <= T; ii++)
  {
    cin >> M;
    graph.clear();
    color.clear();
    for (int k = 0; k < M; k++)
    {
      cin >> str1 >> str2;
      if(graph.find(str1) == graph.end() )
      {
        graph[str1] = vector<string>();
        color[str1] = -1;
      }
      
      if (graph.find(str2) == graph.end() )
      {
        graph[str2] = vector<string>();
        color[str2] = -1;
      }
      
      graph[str1].push_back(str2);
      graph[str2].push_back(str1);
      
    }
    
    auto it = graph.begin();
    bfs.push(it->first);
    color[it->first]= 0;
    status = 1;
    while(!bfs.empty()  && status == 1)
    {
      string key = bfs.front();
      bfs.pop();
      
      if (color[key] == 0)
        for (int i = 0; i < graph[key].size(); i++)
        {
          if( color[graph[key][i]] == -1){
             bfs.push(graph[key][i]);
            color[graph[key][i]] = 1;
          }
          else if (color[graph[key][i]] == 0){
            status = 0;
            break;
          }//else
          
         
        }//for
      
      if (color[key] == 1)
        for (int i = 0; i < graph[key].size(); i++)
        {
          
          if( color[graph[key][i]] == -1){
            bfs.push(graph[key][i]);
            color[graph[key][i]] = 0;
          }
          else if (color[graph[key][i]] == 1){
            status = 0;
            break;
          }//else
        }//for
    }//while
  
     if (status == 1)
       cout << "Case #"<<ii<<": Yes"<<endl;
      else
       cout << "Case #"<<ii<<": No"<<endl;
  }

  return 0;
}