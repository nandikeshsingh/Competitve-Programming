#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        vector<pair<int,pair<int,int>>>vec;
        vector<int>deg(n+1);
        int mn=1e18;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin>>u>>v;
            deg[u]++;
            deg[v]++;
            vec.push_back({a[u]+a[v],{u,v}});
        }
        for(int i=1;i<=n;i++)
        {
            if(deg[i]%2)mn=min(mn,a[i]);
        }
        if(m%2==0)
        {
            cout<<0<<endl;
            continue;
        }
        else 
        {
            sort(all(vec));
            int x=vec[0].second.first;
            int y=vec[0].second.second;
            if(deg[x]%2)mn=min(mn,a[x]);
            if(deg[y]%2)mn=min(mn,a[y]);
            if((deg[x]%2==0)&&(deg[y]%2==0))mn=min(mn,a[x]+a[y]);
            cout<<mn<<endl;
        }
       
    }
    return 0;
}