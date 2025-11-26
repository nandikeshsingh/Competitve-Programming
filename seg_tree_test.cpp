#include <bits/stdc++.h>
using namespace std;
int n;
vector<int>vec;
vector<int>st;
void build(int node,int l,int r)
{
	if(l==r)
	{
		st[node]=vec[l];
        return;
	}
	int mid=(l+r)>>1;
	build(node<<1,l,mid);
	build(node<<1|1,mid+1,r);
	st[node]=min(st[node<<1],st[node<<1|1]);
}
int query(int node,int s,int e,int l,int r)
{
	if(l>e || r<s)return 1e6;
	else if(l<=s&&e<=r)return st[node];
	else 
	{
		int mid=(s+e)>>1;
		int p1=query(node<<1,s,mid,l,r);
		int p2=query(node<<1|1,mid+1,e,l,r);
		return min(p1,p2);
	}
}
int main() {
	cin>>n;
	vec.resize(n,0);
	st.resize(4*n+5,0);
    // cout<<"ok"<<endl;
	for(int i=0;i<n;i++)cin>>vec[i];
	build(1,0,n-1);
    // cout<<"ok2"<<endl;
	int q=0;
	cin>>q;
	while(q--)
	{
		int l,r;
		cin>>l>>r;
        if(q!=0)
		cout<<query(1,0,n-1,l,r)<<endl;
        else cout<<query(1,0,n-1,l,r);
	}
	return 0;
}