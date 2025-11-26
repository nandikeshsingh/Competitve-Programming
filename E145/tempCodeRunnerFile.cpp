#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        map<char,int>mp;
        for(auto& u : s)mp[u]++;
        if(sz(mp)==1)cout<<-1<<endl;
        else if(sz(mp)==2)cout<<6<<endl;
        else cout<<4<<endl;
    }
    return 0;
}


