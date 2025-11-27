#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int INF=1e18;
vector<int>vis1,vis2;
//nice concept 
void dfs(vector<vector<int>>&gp,int node)
{
    vis1[node]=1;
    for(auto& u : gp[node])
    {
        if(!vis1[u])dfs(gp,u);
    }
}
void dfs1(vector<vector<int>>&rgp,int node)
{
    vis2[node]=1;
    for(auto& u : rgp[node])
    {
        if(!vis2[u])dfs1(rgp,u);
    }
}
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    vis1.resize(n+1);
    vis2.resize(n+1);
    vector<pair<int,pair<int,int>>>edges;
    vector<vector<int>>gp(n+1,vector<int>(0));
    vector<vector<int>>rgp(n+1,vector<int>(0));
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        gp[a].push_back(b);
        rgp[b].push_back(a);
        edges.push_back({a,{b,-c}});
    }
    dfs(gp,1);
    dfs1(rgp,n);
    // sort(all(edges));
    vector<int> d (n+1, INF);
    d[1] = 0;
    int last=d[n];
    for (int i=1;i<=n;i++)
    {
        bool any = false;
        for (int j=0; j<m; ++j)
            if (d[edges[j].first] < INF)
                if (d[edges[j].second.first] > d[edges[j].first] + edges[j].second.second && vis1[edges[j].second.first] && vis2[edges[j].second.first])
                {
                    d[edges[j].second.first] = d[edges[j].first] + edges[j].second.second;
                    any = true;
                }
        // // if(i==n)
        // {
            // cout<<"i= "<<i<<" any="<<any<<" last="<<last<<" d[n]="<<d[n]<<endl;
        // }
        if(i==n && any)
        {
            cout<<-1<<endl;
            exit(0);
        }
        // last=d[n];
        if (!any) break;
    }
    cout<<-d[n]<<endl;
    // cout<<(d[n]>=1e12?-1:d[n])<<endl;
    return 0;
}
