#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,q;
vector<vector<int>>gp;
vector<int>val,euler,first,last,bit,cur,par;
void dfs(int node,int p)
{
    euler.push_back(node);
    first[node]=sz(euler)-1;    
    for(auto& u : gp[node])
    {
        if(u==p)continue;
        val[u]+=val[node];
        dfs(u,node);
    }
    euler.push_back(node);
    last[node]=sz(euler)-1;
}
void update(int idx,int val)
{
    while(idx<=sz(euler))
    {
        bit[idx]+=val;
        idx+=(idx&(-idx));
    }
}
int query(int idx)
{
    int ret=0;
    while(idx)
    {
        ret+=bit[idx];
        idx-=(idx&(-idx));
    }
    return ret;
}
signed main()
{
    speed;
    cin>>n>>q;
    gp.resize(n+1,vector<int>(0));
    val.resize(n+1);
    first.resize(n+1);
    last.resize(n+1);
    for(int i=1;i<=n;i++)cin>>val[i];
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }
    cur=val;
    euler.push_back(0);
    dfs(1,0);
    bit.resize(sz(euler)+1);
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int s,x;
            cin>>s>>x;
            update(first[s],x-cur[s]);
            update(last[s]+1,cur[s]-x);
            cur[s]=x;
        }
        else 
        {
            int s;
            cin>>s;
            cout<<query(first[s])+val[s]<<endl;
        }
    }
    return 0;
}