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
int query(int node,int left,int right,int a,int b)
{
    if(left>b||right<a)return 0;
    else if(a<=left&&right<=b)return st[node];
    else 
    {
        int mid=(left+right)>>1;
        int get_left=query(node<<1,left,mid,a,b);
        int get_right=query(node<<1|1,mid+1,right,a,b);
        return get_left+get_right;
    }
}
signed main()
{
    cin>>n>>q;
    x.resize(n);
    for(int i=0;i<n;i++)cin>>x[i];
    st.resize(4*n);
    build(1,0,n-1);
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        cout<<query(1,0,n-1,a,b)<<endl;
    }
}