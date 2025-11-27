#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<vector<int>>gp;
vector<int>sub;
void dfs(int node,int p)
{
    for(auto& u : gp[node])
    {
        if(u==p)continue;
        dfs(u,node);
        sub[node]+=sub[u];
    }
    sub[node]+=1;
}
signed main()
{
    speed;
    int n;
    cin>>n;
    gp.resize(n+1,vector<int>(0));
    vector<int>p(n+1);
    sub.resize(n+1);
    for(int i=2;i<=n;i++)
    {
        cin>>p[i];
        gp[i].push_back(p[i]);
        gp[p[i]].push_back(i);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++)cout<<sub[i]-1<<" ";
    cout<<endl;
    return 0;   
}


