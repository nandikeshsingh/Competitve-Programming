#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;cin>>n;
    string s;cin>>s;
    map<char,vector<char>>mp;
    int q;cin>>q;
    while(q--)
    {
        char a,b;cin>>a>>b;
        if(mp.find(a)==mp.end())mp[a].push_back(b);
        for(auto& u : mp)
        {
            if(u.second.back()==a)
            mp[u.first].push_back(b);
        }
    }
    for(auto& u : s)
    {
        if(mp.find(u)!=mp.end())
        u=mp[u].back();
    }
    cout<<s<<endl;
    return 0;
}


