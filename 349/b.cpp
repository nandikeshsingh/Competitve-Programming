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
    vector<int>cnt(26,0);
    for(auto& u : s)cnt[u-'a']++;
    map<int,int>mp;
    for(int i=0;i<26;i++)
    {
        if(cnt[i])
        mp[cnt[i]]++;
    }
    bool ok=1;
    for(auto& u : mp)
    {
        if(u.second>2 || u.second==1)ok=0;

    }
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}


