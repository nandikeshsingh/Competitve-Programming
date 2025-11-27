#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
vector<int>a;
vector<int>sv;
struct SegTree
{
    struct data
    {
        int mx;
        int sum;
        data() : mx(-1e9),sum(0) {};
    };

	int N;
	vector<data> st;

	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
	}

	void merge(data &cur, data &l, data &r) 
	{
		cur.mx = max(l.mx, r.mx);
        cur.sum=l.sum+r.sum;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mx = a[L];
            st[node].sum=a[L];
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

    void update(int node,int L,int R,int i,int j)
    {
        if(j<L || i>R)return;
        if(st[node].mx<=2)return;
		if(L==R)
		{
            if(a[L]<=2)return;
			st[node].mx = sv[a[L]];
            st[node].sum=sv[a[L]];
            a[L]=sv[a[L]];
			return;
		}
		int M=(L + R)/2;
		update(node*2, L, M,i,j);
		update(node*2 + 1, M + 1, R,i,j);
		merge(st[node], st[node*2], st[node*2+1]);        
    }
	data query(int node, int L, int R, int i, int j)
	{
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		data left=query(node*2, L, M, i, j);
		data right=query(node*2 + 1, M + 1, R, i, j);
		data cur;
		merge(cur, left, right);
		return cur;
	}
};
SegTree T;

void calc()
{
    sv.resize(1e6+5,0);
    for(int i=1;i<1e6+5;i++)
    {
        for(int j=i;j<1e6+5;j+=i)
        {
            sv[j]++;
        }
    }
}
signed main()
{
    speed;
    int n,m;
    cin>>n>>m;
    T.init(n);
    a.resize(n+1);
    calc();
    for(int i=1;i<=n;i++)cin>>a[i];
    T.build(1,1,n);
    while(m--)
    {
        int t,l,r;
        cin>>t>>l>>r;
        if(t==1)
            T.update(1,1,n,l,r);
        else 
            cout<<T.query(1,1,n,l,r).sum<<endl;
    }
    return 0;
}
