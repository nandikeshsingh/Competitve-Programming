#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,q;
vector<int>x,t;
void build(int node,int l,int r)
{
    if(l==r)
    {
        t[node]=x[l];
    }
    else 
    {
        int mid=(l+r)>>1;
        build(node<<1,l,mid);
        build(node<<1|1,mid+1,r);
        t[node]=min(t[node<<1],t[node<<1|1]);
    }
}
void update(int node,int l,int r,int idx,int val)
{
    if(l==r)
    {
        x[l]=val;
        t[node]=val;
    }
    else 
    {
        int mid=(l+r)>>1;
        if(idx<=mid)
        update(node<<1,l,mid,idx,val);
        else
        update(node<<1|1,mid+1,r,idx,val);
        t[node]=min(t[node<<1],t[node<<1|1]);        
    }
}
int query(int node,int l,int r,int st,int ed)
{
    if(l>ed || r<st)return 1e18;
    else if(l>=st && ed>=r)return t[node];
    else 
    {
        int mid=(l+r)>>1;
        int p1=query(node<<1,l,mid,st,ed);
        int p2=query(node<<1|1,mid+1,r,st,ed);
        return min(p1,p2);
    }
}
signed main()
{
    speed;
    cin>>n>>q;
    x.resize(n);
    t.resize(4*n);
    for(int i=0;i<n;i++)cin>>x[i];
    build(1,0,n-1);
    while(q--)
    {
        int t;cin>>t;
        if(t==1)
        {
            int k,u;
            cin>>k>>u;
            k--;
            update(1,0,n-1,k,u);
        }
        else 
        {
            int a,b;
            cin>>a>>b;
            --a;--b;
            cout<<query(1,0,n-1,a,b)<<endl;
        }
    }
    return 0;
}


