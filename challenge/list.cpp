#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;
int letters[200]={0};
string s, rs, t;
vector<stirng> list;

class tree{
  bool l[26];
  tree* child[26];
public:
  tree(){
    memset(l,0,sizeof(l));
    memset(child, 0, sizeof(child));

  }
  void insert(string a, tree *root, int start, int end)
  {
    if (start == end)
      return;
    root->l[a[start]-'a'] = 1;
    if (!root->child[a[start]-'a'])
      root->child[a[start]-'a'] = new tree();

    this->insert(a,root->child[a[start]-'a'], start+1, end);
  }

  int check(string ss, int start, int len, tree *cur_tree)
  {
    if (cur_tree->l[ss[start]-'a'] == 0)
    {
      return len;
    }
    
  return check(ss, start+1, len+1, cur_tree->child[ss[start]-'a']);
  }

};

int main()
{
    tree * root = new tree();
    while(cin >> s)
    {
      root->insert(s, root, i, j);
      list.push_back(s);
    }

    for(int i = 0; i < list.size();i++)
    {
      
        int len = 0;
        
        len = check(list[i], i, 0, root);
        if (len == 0)
          j--;
    }

    for()
       
  return 0;
}