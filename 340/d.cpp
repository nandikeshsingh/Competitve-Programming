#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int maxn=2e5+5;
int n;
vector<int>a,b,x;
vector<pair<int,int>>gp[maxn];
vector<int>dis;
void solve(int n)
{
    multiset<pair<int,int>>mst;
    mst.insert({dis[n],n});
    while(sz(mst))
    {
        pair<int,int>p=*mst.begin();
        mst.erase(mst.begin());
        int node=p.second;
        int cur=p.first;
        for(auto& u : gp[node])
        {
            if(dis[u.first]>cur+u.second)
            {
                dis[u.first]=cur+u.second;
                mst.insert({dis[u.first],u.first});
            }
        }
    }
}
signed main()
{
    speed;
    cin>>n;
    a.resize(n+1),b.resize(n+1),x.resize(n+1);
    dis.resize(n+1);
    for(int i=1;i<=n;i++)dis[i]=1e18;
    dis[1]=0LL;
    for(int i=1;i<n;i++)cin>>a[i]>>b[i]>>x[i];
    for(int i=1;i<n;i++)
    {
        gp[i].push_back({i+1,a[i]});
        gp[i].push_back({x[i],b[i]});
    }
    solve(1);
    cout<<dis[n]<<endl;
    return 0;
}


