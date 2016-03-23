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
vector<int> res;

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

  void check(char &end,string ss, int start, int &len, tree *cur_tree)
  {
    if (cur_tree->l[ss[start]-'a'] == 0){
      return;
    }
    end = ss[start];
    len += 1;
    
     check( end, ss, start+1, len, cur_tree->child[ss[start]-'a']);


  }

};

int main()
{


  cin >> s >> t;
  rs =s;
  reverse(rs.begin(), rs.end());

  for(int i = 0; i < s.length(); i++){
    letters[s[i]]=1;
  }

  for(int i = 0; i < t.length(); i++)
    if( letters[t[i]] == 0)
    {
      cout << -1 << endl;
      return 0;
    }

    tree * root = new tree();
    for(int i = 0; i < s.length(); i++)
      for(int j = i+1; j <= s.length(); j++){
        root->insert(s, root, i, j);
        root->insert(rs, root, i, j);

      }



      int len;
      char c;
      int count = 0;
      for(int i = 0; i < t.length(); i++)
      {
        int status = 1;
        len = 0;
        root->check(c, t, i, len, root);

        for(int j = 0; j < s.length(); j++)
        {
          if(s.substr(j, len) == t.substr(i,len) )
          {
           // cout << "hi :j:" << j << endl;
            res.push_back(j+1);
            //cout << j+1 <<" "<<j+len<<endl;
            res.push_back(j+len);
            count++;
            status = 0;
            break;
          }

        }

          for(int j = 0; j < rs.length()&& status; j++)
        {
          if(rs.substr(j, len) == t.substr(i,len) )
          {
           //cout <<"hello"; 
            res.push_back(s.length()-j);
            res.push_back(s.length()-j-len+1);
            
            //cout << s.length()-j-len+1 <<" "<<s.length()-j<<endl;
            count++;
            break;
          }
        }
        i += len-1;

       
      }

      cout << count<<endl;
      for(int i = 0; i < res.size(); )
      {
        cout << res[i]<<" "<<res[i+1]<<endl;
        i+=2;
      }



  return 0;
}