#include<bits/stdc++.h>
// #define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int maxn=2e5+5;
vector<int>gp[maxn];
vector<int>depth;
vector<int>par;
int n, l;
// vector<vector<int>> adj;

int timer;
vector<int> tin, tout;
vector<vector<int>> up;

// void dfs(int v, int p)
// {
//     tin[v] = ++timer;
//     up[v][0] = p;
//     for (int i = 1; i <= l; ++i)
//         up[v][i] = up[up[v][i-1]][i-1];

//     for (int u : adj[v]) {
//         if (u != p)
//             dfs(u, v);
//     }

//     tout[v] = ++timer;
// }
void dfs(int node,int p,int d)
{
    // cout<<"node="<<node<<" parent="<<p<<" depth="<<d<<endl;
    par[node]=p;
    depth[node]=d;
    tin[node]=++timer;
    up[node][0]=p;
    for(int i=1;i<=l;i++)
    up[node][i]=up[up[node][i-1]][i-1];
    for(auto& u :gp[node])
    {
        if(u!=p)
        dfs(u,node,d+1);
    }
    tout[node]=++timer;
} 
bool is_ancestor(int u, int v)
{
    if(u<=0 || v<=0)return 1;
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int LCA(int u, int v)
{
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = l; i >= 0; --i) {

        if (!is_ancestor(up[u][i], v))
        {
            // cout<<"inside u = "<<u<<endl;
            u = up[u][i];
        }
            
    }
    return up[u][0];
}

void preprocess(int root) {
    tin.resize(n+1,0);
    tout.resize(n+1,0);
    timer = 0;
    l = ceil(log2(n+1));
    up.assign(n+1, vector<int>(l + 1,0));
    dfs(root,0,0);
}
  
signed main()
{
    speed;
    // int n;
    cin>>n;
    depth.resize(n+1,0);
    par.resize(n+1,0);
    for(int i=1;i<n;i++)
    {
        int u,v;
        cin>>u>>v;
        gp[u].push_back(v);
        gp[v].push_back(u);
    }
    // cout<<"in"<<endl;
    preprocess(1);
    // cout<<"Printing up"<<endl;
    // for(int i=0;i<=n;i++)
    // {
    //     for(int j=0;j<=l;j++)
    //     cout<<up[i][j]<<" ";
    //     cout<<endl;
    // }
    // cout<<"Printing tin"<<endl;
    // for(int i=0;i<=n;i++)cout<<tin[i]<<" ";
    // cout<<endl;
    // cout<<"Printing tout"<<endl;
    // for(int i=0;i<=n;i++)cout<<tout[i]<<" ";
    // cout<<endl;
    // cout<<"out"<<endl;
    // dfs(1,0,0);
    // while(1)
    // {
    //     cout<<"Play with LCA"<<endl;
    //     int x,y;
    //     cin>>x>>y;
    //     cout<<LCA(x,y)<<endl;
    // }
    bool arr[n+1]={0};
    int q;cin>>q;
    while(q--)
    {
        int k;cin>>k;
        set<int>st;
        int mx=-1;
        int mn=2e9;
        int lca=-1;
        int left=-1;
        for(int i=0;i<k;i++)
        {
            int p;cin>>p;
            st.insert(p);
            if(depth[p]>mx)
            {
                mx=depth[p];
                left=p;
            }
            // if(depth[p]<mn)
            // {
            //     mn=depth[p];
            //     lca=p;
            // }
        }
        int node=left;
        int last=-1;
        while(node>0)
        {
            if(st.count(node))
            {
                last=node;
                st.erase(node);
            }
            node=par[node];
        }
        // if(st.count(lca))
        // {
        //     cout<<"NO"<<endl;
        //     continue;
        // }
        if((int)st.size()==0)
        {
            cout<<"YES"<<endl;
            continue;
        }

        mx=-1;
       int right=-1;
        for(auto& u : st)
        {
            if(depth[u]>mx)
            {
                mx=depth[u];
                right=u;
            }
        }
        int x=LCA(right,left);
        if(depth[x]>depth[last])
        {
            cout<<"NO"<<endl;
            continue;
        }
        else if(depth[x]==depth[last] && x!=last)
        {
            cout<<"NO"<<endl;
            continue;
        }
         node=right;
        while(node!=par[x] && node>0)
        {
            if(st.count(node))st.erase(node);
            node=par[node];
        }
        if((int)st.size()==0)
        {
            cout<<"YES"<<endl;
        }        
        else cout<<"NO"<<endl;
    }
    return 0;
}

