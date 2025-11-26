#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int M=1e6+10;
const int A=26;
struct Trie {
    int G = 0;
    int t[M][A] = {};
    int f[M] = {};
 
    void add(const string& s) {
        int x = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
 
            if (!t[x][c]) {
                t[x][c] = ++G;
            }
 
            x = t[x][c];
            f[x] += 1;
        }
    }
 
    int get(const string& s) {
        int x = 0;
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
 
            if (!t[x][c]) {
                break;
            }
 
            x = t[x][c];
            res += f[x];
        }
        return res;
    }
};
Trie T;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<string>vec;
    int tot=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        vec.push_back(s);
        T.add(s);
        tot+=(int)s.length();
    }
    for(auto& u : vec)
    {
        reverse(all(u));
        cnt+=T.get(u);
    }
    cout<<tot*2*n-cnt*2<<endl;
    return 0;
}


