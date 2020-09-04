#include <bits/stdc++.h>
using namespace std;

#define watch(x) cout << (#x) << " is " << (x) << endl
#define watchArray(v) for(auto i : v) cout << i << ' '; cout << endl;
#define all(x) (x).begin(),(x).end()

const long long int mod = 1e9-1;

typedef long long int lli;
typedef vector<vector<lli>> matrix;

int main(){
  string key,str;
  int n;
  char matriz[26][26];
  vector<char> alf;

  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);

  cin >> key;
  cin >> n;

  for(int i=0;i<26;i++){
    alf.push_back(char(i+'a'));
  }

  for(int i=0;i<26;i++){
    for(int j=0;j<26;j++){
      matriz[i][j] = ((int(alf[i]-'a')+int(alf[j]-'a'))%26) + 'a';
    }
  }

  cin.ignore();
 
  while (n--) {
    string s;
    vector<string> v, v_chave, ans;

    getline(cin, s);

    stringstream ss(s);
    string word;

    while (ss >> word) {
        v.push_back(word);
    }

    int ptr = 0;

    for (int i = 0; i < (int)v.size(); i++) {
      if (v[i][0] == 'a' || v[i][0] == 'e' || v[i][0] == 'i' || v[i][0] == 'o' || v[i][0] == 'u') {
        ans.push_back(v[i]);
        continue;
      }

      string tmp;

      for (int j = 0; j < (int)v[i].size(); j++) {
        tmp.push_back(matriz[key[ptr] - 'a'][v[i][j] - 'a']);
        ptr = (ptr + 1) % (int)key.size();
      }

      ans.push_back(tmp);
    }

    for (int i = 0; i < (int)ans.size(); i++) {
      cout << ans[i] << " \n"[i == (int)ans.size() - 1];
    }
  }

  return 0;
}