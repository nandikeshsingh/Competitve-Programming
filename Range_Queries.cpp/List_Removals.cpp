#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n;
vector<int>x,p,t;
void build(int node,int l,int r)
{
    if(l==r)
    {
        t[node]=(x[l]>=1?1:0);
    }
    else 
    {
        int mid=(l+r)>>1;
        build(node<<1,l,mid);
        build(node<<1|1,mid+1,r);
        t[node]=t[node<<1]+t[node<<1|1];
    }
}
int query(int node,int l,int r,int st,int ed)
{
    if(l>ed || r<st)return 0;
    else if(st<=l && r<=ed)return t[node];
    else 
    {
        int mid=(l+r)>>1;
        return query(node<<1,l,mid,st,ed)+query(node<<1|1,mid+1,r,st,ed);
    }
}
void update(int node,int l,int r,int idx)
{
    if(l==r)
    {
        x[idx]=0;
        t[node]=0;
    }
    else 
    {
        int mid=(l+r)>>1;
        if(mid>=idx)update(node<<1,l,mid,idx);
        else update(node<<1|1,mid+1,r,idx);
        t[node]=t[node<<1]+t[node<<1|1];
    }
}
signed main()
{
    speed;
    cin>>n;
    x.resize(n);
    for(int i=0;i<n;i++)cin>>x[i];
    p.resize(n);
    for(int i=0;i<n;i++)cin>>p[i];
    t.resize(4*n);
    build(1,0,n-1);
    vector<int>ans;
    for(auto & u : p)
    {
       int lo=0,hi=n-1;
       while(lo<hi)
       {
            int mid=(lo+hi)>>1;
            int cnt=query(1,0,n-1,lo,mid);
            // cout<<"lo="<<lo<<" hi="<<hi<<" mid="<<mid<<endl;
            // cout<<"cnt="<<cnt<<endl;
            if(cnt>=u)hi=mid;
            else lo=mid+1,u-=cnt;
       }
    //    cout<<"lo="<<lo<<endl;
    //    cout<<"x[lo]="<<x[lo]<<endl;

       ans.push_back(x[lo]);
       update(1,0,n-1,lo);
    }
    for(auto u : ans)cout<<u<<" ";
    cout<<endl;
    return 0;
}