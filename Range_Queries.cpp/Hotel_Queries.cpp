#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,m;
vector<int>h,t;
void build(int node,int l,int r)
{
    if(l==r)t[node]=h[l];
    else 
    {
        int mid=(l+r)>>1;
        build(node<<1,l,mid);
        build(node<<1|1,mid+1,r);
        t[node]=max(t[node<<1],t[node<<1|1]);
    }
}
void update(int node,int l,int r,int idx,int v)
{
    if(l==r)t[node]+=v,h[l]+=v;
    else 
    {
        int mid=(l+r)>>1;
        if(idx<=mid)update(node<<1,l,mid,idx,v);
        else update(node<<1|1,mid+1,r,idx,v);
        t[node]=max(t[node<<1],t[node<<1|1]);
    }
}
int query(int node,int l,int r,int st,int ed)
{
    if(st>r || ed<l)return -1e18;
    else if(l>=st && r<=ed)return t[node];
    else 
    {
        int mid=(l+r)>>1;
        return max(query(node<<1,l,mid,st,ed),query(node<<1|1,mid+1,r,st,ed));
    }
}
signed main()
{
    speed;
    cin>>n>>m;
    h.resize(n);
    for(int i=0;i<n;i++)
    {
        cin>>h[i];
    }
    t.resize(4*n);
    build(1,0,n-1);
    vector<int>ans;
    for(int i=0;i<m;i++)
    {
        int r;cin>>r;
        int lo=0,hi=n;
        while(lo<hi)
        {
            int mid=(lo+hi)>>1;
            if(query(1,0,n-1,lo,mid)>=r)hi=mid;
            else lo=mid+1;
        }
        ans.push_back((lo!=n?lo:-1)+1);
        if(lo!=n)
        update(1,0,n-1,lo,-r);
    }
    for(auto& u : ans)cout<<u<<" ";
    cout<<endl;
    return 0;
}

