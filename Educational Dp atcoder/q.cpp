#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>st;
void update(int node,int l,int r,int idx,int val)
{
    if(l==r)st[node]=val;
    else 
    {
        int mid=(l+r)>>1;
        if(idx<=mid)update(node<<1,l,mid,idx,val);
        else update(node<<1|1,mid+1,r,idx,val);
        st[node]=max(st[node<<1],st[node<<1|1]);
    }
}
int query(int node,int l,int r,int s,int ed)
{
    if(s>r || ed<l)return 0;
    else if(s<=l && r<=ed)return st[node];
    else 
    {
        int mid=(l+r)>>1;
        int p1=query(node<<1,l,mid,s,ed);
        int p2=query(node<<1|1,mid+1,r,s,ed);
        return max(p1,p2);
    }
}
signed main()
{
    speed;
    int n;
    cin>>n;
    int sz=1;
    while(sz<=n)sz*=2;
    st.resize(2*sz);
    vector<int>h(n),a(n);
    for(int i=0;i<n;i++)cin>>h[i];
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>dp(n);
    for(int i=0;i<n;i++)
    {
        dp[i]=a[i]+query(1,0,n,0,h[i]-1);
        update(1,0,n,h[i],dp[i]);
    }
    cout<<*max_element(all(dp))<<endl;
    return 0;
}
