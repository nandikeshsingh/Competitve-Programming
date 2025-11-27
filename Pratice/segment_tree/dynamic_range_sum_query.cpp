#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,q;
vector<int>x,st;
void build(int node,int left,int right)
{
    if(left==right)
    {
        st[node]=x[left];
        return;
    }
    int mid=(left+right)>>1;
    build(node<<1,left,mid);
    build(node<<1|1,mid+1,right);
    st[node]=st[node<<1]+st[node<<1|1];
}
void update(int node,int left,int right,int k,int u)
{
    if(left==right)
    {
        x[k]=u;
        st[node]=u;
        return;
    }
    int mid=(left+right)>>1;
    if(k<=mid)update(node<<1,left,mid,k,u);
    else update(node<<1|1,mid+1,right,k,u);
    st[node]=st[node<<1]+st[node<<1|1];
}
int query(int node,int left,int right,int a,int b)
{
    if(a>right||b<left)return 0;
    else if(a<=left&&right<=b)return st[node];
    else 
    {
        int mid=(left+right)>>1;
        int left_ans=query(node<<1,left,mid,a,b);
        int right_ans=query(node<<1|1,mid+1,right,a,b);
        return left_ans+right_ans;
    }
}
signed main()
{
    cin>>n>>q;
    x.resize(n);
    st.resize(4*n);
    for(int i=0;i<n;i++)cin>>x[i];
    build(1,0,n-1);
    while(q--)
    {
        int t;cin>>t;
        if(t==1)
        {
            int k,u;cin>>k>>u;
            k--;
            update(1,0,n-1,k,u);
        }
        else 
        {
            int a,b;
            cin>>a>>b;
            a--;b--;
            cout<<query(1,0,n-1,a,b)<<endl;
        }
    }
}