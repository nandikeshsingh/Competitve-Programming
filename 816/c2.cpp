#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
vector<int>a;
struct data{
    int tot=0;
    int pre=0;
    int suf=0;
    int fl=0;
};
vector<data>st;
void build(int node,int l,int r)
{
    if(l==r)
    {
        st[node].tot=1;
        st[node].pre=1;
        st[node].suf=1;
        st[node].fl=1;
    }
    else 
    {
        int mid=(l+r)>>1;
        build(node<<1,l,mid);
        build(node<<1|1,mid+1,r);
        if(a[mid]!=a[mid+1])
        {
            st[node].pre=st[node<<1].fl+(r-mid)*st[node<<1|1].pre;
            st[node].suf=st[node<<1|1].fl+(mid-l+1)*st[node<<1].suf;
            st[node].fl=st[node<<1].fl+st[node<<1|1].fl;
            st[node].tot=(st[node<<1].tot-st[node<<1].suf)+(st[node<<1|1].tot-st[node<<1|1].pre)+((r-mid)*st[node<<1].suf+st[node<<1|1].pre);
        }
        else 
        {
            st[node].pre=st[node<<1].fl+(r-mid)*st[node<<1|1].pre-(r-mid);
            st[node].suf=st[node<<1|1].fl+(mid-l+1)*st[node<<1].suf-(mid-l+1);
            st[node].fl=st[node<<1].fl+st[node<<1|1].fl-1;
            st[node].tot=(st[node<<1].tot-st[node<<1].suf)+(st[node<<1|1].tot-st[node<<1|1].pre)+((r-mid)*(mid-l+1)*st[node<<1].suf+st[node<<1|1].pre)-(r-mid)*(mid-l+1);
        }
    }
}
void update(int node,int l,int r,int idx,int val)
{
    if(l==r)
    {
        a[idx]=val;
    }
    else 
    {
        int mid=(l+r)>>1;
        if(idx<=mid)update(node<<1,l,mid,idx,val);
        else update(node<<1|1,mid+1,r,idx,val);
        if(a[mid]!=a[mid+1])
        {
            st[node].pre=st[node<<1].fl+(r-mid)*st[node<<1|1].pre;
            st[node].suf=st[node<<1|1].fl+(mid-l+1)*st[node<<1].suf;
            st[node].fl=st[node<<1].fl+st[node<<1|1].fl;
            st[node].tot=(st[node<<1].tot-st[node<<1].suf)+(st[node<<1|1].tot-st[node<<1|1].pre)+((r-mid)*st[node<<1].suf+st[node<<1|1].pre);
        }
        else 
        {
            st[node].pre=st[node<<1].fl+(r-mid)*st[node<<1|1].pre-(r-mid);
            st[node].suf=st[node<<1|1].fl+(mid-l+1)*st[node<<1].suf-(mid-l+1);
            st[node].fl=st[node<<1].fl+st[node<<1|1].fl-1;
            st[node].tot=(st[node<<1].tot-st[node<<1].suf)+(st[node<<1|1].tot-st[node<<1|1].pre)+((r-mid)*(mid-l+1)*st[node<<1].suf+st[node<<1|1].pre)-(r-mid)*(mid-l+1);
        }
    }
}
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    a.resize(n,0);
    st.resize(4*n+4);
    for(int i=0;i<n;i++)cin>>a[i];
    build(1,0,n-1);

    vector<int>dp(n,0);
    // dp[0]=0;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)
        {
            dp[i]=1;
            ans+=1;
            continue;
        }
        if(a[i]!=a[i-1])dp[i]+=(dp[i-1]+i);
        else dp[i]=dp[i-1]+1;
        ans+=dp[i];
    }
    cout<<"ans="<<ans<<endl;
    cout<<"from seg="<<st[1].tot<<endl;
    while(m--)
    {
        int id,x;
        cin>>id>>x;
        update(1,0,n-1,id,x);
        cout<<st[1].tot<<endl;
    }
    return 0;
}


