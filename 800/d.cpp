#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
vector<vector<int>>gp;
vector<int>l,r;
int ans;
void dfs(int node,int par)
{
    int mx=0;
    for(auto& u : gp[node])
    {
        
        if(u!=par)
        {
            dfs(u,node);
            mx+=l[u];
        }
        
    }
    if(mx<l[node])
    {
        ans++;
        l[node]=r[node];
        // l[node]=mx;
    }
    else if(mx>=l[node] && mx<=r[node])
    {
        l[node]=mx;
    }
    else l[node]=r[node];
    // else l[node]=mx;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        ans=0;
        int n;
        cin>>n;
        vector<int>p(n+1);
        for(int i=2;i<=n;i++)cin>>p[i];
        gp.clear();
        gp.resize(n+1,vector<int>(0));
        for(int i=2;i<=n;i++)
        {
            gp[i].push_back(p[i]);
            gp[p[i]].push_back(i);
        }
        l.clear();
        r.clear();
        l.resize(n+1);
        r.resize(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>l[i]>>r[i];
        }
        dfs(1,-1);
        // cout<<"Printing "<<endl;
        cout<<ans<<endl;

    }
    return 0;
}

