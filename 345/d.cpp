#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,h,w;
    cin>>n>>h>>w;
    vector<pair<int,int>>tiles;
    for(int i=0;i<n;i++)
    {
        int a,b;cin>>a>>b;
        if(min(a,b)>h||min(a,b)>w)continue;
        else tiles.push_back({a,b});
    }
    bool ok=0;
    for(int mask=0;mask<(1<<sz(tiles));mask++)
    {
        int tot=0;
        for(int j=0;j<sz(tiles);j++)
        {
            if(((1<<j)&mask))tot+=tiles[j].first*tiles[j].second;
        }
        if(tot==h*w)
        {
            ok=1;
            cout<<mask<<endl;
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}


