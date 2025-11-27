#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,q;
vector<vector<int>>gp;
vector<int>v,euler,first,last,bit;
void dfs(int node,int p)
{
    euler.push_back(node);
    first[node]=sz(euler)-1;
    for(auto& u : gp[node])
    {
        if(u==p)continue;
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
    int sum=0;
    while(idx)
    {
        sum+=bit[idx];
        idx-=(idx&(-idx));
    }
    return sum;
}
signed main()
{
    speed;
    cin>>n>>q;
    gp.resize(n+1,vector<int>(0));
    v.resize(n+1);
    first.resize(n+1);
    last.resize(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    for(int i=1;i<n;i++)
    {
        int a,b;
        cin>>a>>b;
        gp[a].push_back(b);
        gp[b].push_back(a);
    }
    euler.push_back(0);
    dfs(1,-1);
    bit.resize(2*n+1);
    for(int i=1;i<sz(euler);i++)update(i,v[euler[i]]);
    while(q--)
    {
        int t;
        cin>>t;
        if(t==1)
        {
            int s,x;
            cin>>s>>x;
            euler[first[s]]=x;
            euler[last[s]]=x;
            update(first[s],x-v[s]);
            update(last[s],x-v[s]);
            v[s]=x;
        }
        else 
        {
            int s;cin>>s;
            cout<<(query(last[s])-query(first[s]-1))/2<<endl;
        }
    }
    return 0;
}
