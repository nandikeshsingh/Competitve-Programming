#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>tin,tout,depth,p;
vector<vector<int>>gp;
int t;
void dfs(int node,int par,int d)
{
    tin[node]=++t;
    p[node]=par;
    depth[node]=d;
    for(auto& u : gp[node])
    {
        if(u==par)continue;
        dfs(u,node,d+1);
    }
    tout[node]=++t;
}
bool is_ancestor(int x,int y)
{
    if(x==-1)return 1;
    return tin[x]<=tin[y] && tout[x]>=tout[y];
}
signed main()
{
    speed;
    int n,q;
    cin>>n>>q;
    p.resize(n+1);
    gp.resize(n+1,vector<int>(0));
    tin.resize(n+1);
    tout.resize(n+1);
    depth.resize(n+1);
    for(int i=2;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }
    dfs(1,-1,0);
    vector<vector<int>>anc(19,vector<int>(n+1));
    for(int i=0;i<=18;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==0)anc[i][j]=p[j];
            else 
            {
                if(anc[i-1][j]>=1)
                anc[i][j]=anc[i-1][anc[i-1][j]];
                else anc[i][j]=-1;
            }
        }
    }
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        int aa=a;
        if(is_ancestor(a,b))
        {
            cout<<-depth[a]+depth[b]<<endl;
            continue;
        }
        else if(is_ancestor(b,a))
        {
            cout<<depth[a]-depth[b]<<endl;
            continue;
        }
        for(int i=18;i>=0;i--)
        {
            if(!is_ancestor(anc[i][a],b))
            a=anc[i][a];
        }
        int lca=anc[0][a];
        cout<<depth[aa]+depth[b]-2*depth[lca]<<endl;
    }
    return 0;
}


