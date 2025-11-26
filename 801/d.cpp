#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
vector<vector<int>>gp;
vector<int>val;
vector<int>deg;
void dfs(int node,int par)
{
    int cnt=0;
    for(auto& u : gp[node])
    {
        if(u!=par)
        {
            dfs(u,node);
            val[node]+=val[u];
            if(val[u]==0)cnt++;
        }
    }
    val[node]+=max(0LL,cnt-1);
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n==1)
        {
            cout<<0<<endl;
            continue;
        }
        
        val.clear();
        gp.clear();
        deg.clear();
        gp.resize(n+1,vector<int>(0));
        val.resize(n+1,0);
        deg.resize(n+1,0);
        for(int i=1;i<n;i++)
        {
            int u,v;
            cin>>u>>v;
            gp[u].push_back(v);
            gp[v].push_back(u);
            deg[u]++;
            deg[v]++;
        }
        if(n==2)
        {
            cout<<1<<endl;
            continue;
        }
        int ans=1e18;
        int root=-1;
        int mx=-1;
        for(int i=1;i<=n;i++)
        {
            if(deg[i]>mx)
            {
                mx=deg[i];
                root=i;
            }
        }   
        if(mx<3)
        {
            cout<<1<<endl;
            continue;
        }
        dfs(root,-1);
        // for(int root=1;root<=n;root++)
        // {
        //     dfs(root,-1);
        //     ans=min(ans,1+val[root]);
        //     // cout<<"Printing val"<<endl;
        //     for(auto& u : val)
        //     {
        //         // cout<<u<<" ";
        //         u=0;
        //     }
        //     // cout<<endl;
        // }
        // cout<<"Printing ans"<<endl;
        cout<<val[root]<<endl;
    }
    return 0;
}

