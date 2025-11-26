#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>vec;
vector<int>tree;
int n;
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=l;
    }
    else 
    {
        int mid=(l+r)>>1;
        build(node<<1,l,mid);
        build(node<<1|1,mid+1,r);
        if(vec[tree[node<<1]]<vec[tree[node<<1|1]])tree[node]=tree[node<<1];
        else tree[node]=tree[node<<1|1];
    }
}
int query(int node,int l,int r,int st,int ed)
{
    if(st>r || ed<l)return -1;
    else if(st<=l && r<=ed)return tree[node];
    else 
    {
        int mid=(l+r)>>1;
        int p1=query(node<<1,l,mid,st,ed);
        int p2=query(node<<1|1,mid+1,r,st,ed);
        if(p1==-1 &&p2!=-1)return p2;
        else if(p2==-1 && p1!=-1)return p1;
        else 
        {
            if(vec[p1]<vec[p2])return p1;
            else return p2;
        }
    }
}
int find(int l,int r,int h)
{
    if(r<l)return 0;
    int idx=query(1,0,n-1,l,r);
    // cout<<"l="<<l<<" r="<<r<<" idx="<<idx<<endl;
    return vec[idx]-h+find(l,idx-1,vec[idx])+find(idx+1,r,vec[idx]);
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vec.resize(n);
        tree.resize(4*n);
        int mx=-1e18;
        for(int i=0;i<n;i++)cin>>vec[i],mx=max(mx,vec[i]);
        build(1,0,n-1);
        int val=find(0,n-1,0);
        if(val<=mx)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}