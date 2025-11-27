#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    string s;
    cin>>s;
    vector<int>vec(26,0);
    for(auto& u : s)vec[u-'a']++;
    char ch;
    for(int i=0;i<26;i++)
    {
        if(vec[i]==1)
        {
            ch=i+'a';
        }
    }
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==ch)
        {
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}


