#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,q;
    cin>>n>>q;
    vector<pair<int,int>>pos;
    for(int i=n;i>=1;i--)
    {
        pos.push_back({i,0});
    }
    while(q--)
    {
        int t;cin>>t;
        if(t==1)
        {
            char c;cin>>c;
            if(c=='R')pos.push_back({pos.back().first+1,pos.back().second});
            else if(c=='L')pos.push_back({pos.back().first-1,pos.back().second});
            else if(c=='U')pos.push_back({pos.back().first,pos.back().second+1});
            else if(c=='D')pos.push_back({pos.back().first,pos.back().second-1});
        }
        else 
        {
            int p;cin>>p;
            int l=pos[sz(pos)-p].first;
            int r=pos[sz(pos)-p].second;
            cout<<l<<" "<<r<<endl;
        }
    }
    return 0;
}


