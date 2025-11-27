#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int n,q;
string s;
struct segtree
{
  struct data
  {
  	//Use required attributes
  	bool ok;
    char f;
    int len;
  	//Default Values
  	data() : ok(0),f('0'),len(0) {};
  };
	int N;
	vector<data> st;
	vector<bool> cLazy;//stores if this values needs to be pushed down or not.
	vector<int> lazy;//stores the value that needs to be pushed down.

	void init(int n)
	{
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		// lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	void merge(data &cur, data &l, data &r) 
	{
		if(l.ok && r.ok)
        {
            if(l.len%2)
            {
                if(l.f!=r.f)
                    cur.ok=1;
                else
                    cur.ok=0;
            }
            else 
            {
                if(l.f!=r.f)
                    cur.ok=0;
                else 
                    cur.ok=1;
            }
        }
        else cur.ok=0;
        cur.f=l.f;
        cur.len=l.len+r.len;
	}
	
	//Handle lazy propagation appriopriately
	void propagate(int node, int L, int R)
	{
		if(L != R)
		{
			cLazy[node*2] = 1-cLazy[node*2];
			cLazy[node*2 + 1] = 1-cLazy[node*2 + 1];
			// lazy[node*2] = lazy[node];
			// lazy[node*2 + 1] = lazy[node]; 
		}
		// st[node].mn = lazy[node];
        if(st[node].f=='0')
        st[node].f='1';
        else st[node].f='0';
		cLazy[node] = 0;
        // lazy[node] = 0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].ok=1;//change the value as per the question.
            st[node].f=s[L];
            st[node].len=1;
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data Query(int node, int L, int R, int i, int j)
	{
        // cout<<"node="<<node<<" L="<<L<<" R="<<R<<" i="<<i<<" j="<<j<<endl;
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return data();
		if(i<=L && R<=j)
			return st[node];
		int M = (L + R)/2;
		data left=Query(node*2, L, M, i, j);
		data right=Query(node*2 + 1, M + 1, R, i, j);
		data cur;
        if(left.len==0)cur=right,assert(right.len!=0);
        else if(right.len==0)cur=left,assert(left.len!=0);
        else merge(cur, left, right);
		return cur;
	}

	void Update(int node, int L, int R, int i, int j)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1-cLazy[node];
			// lazy[node] = val;
            if(cLazy[node])
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j);
		Update(node*2 + 1, M + 1, R, i, j);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	data query(int l, int r)
	{
		return Query(1, 0, N-1, l, r);
	}

	void update(int l, int r)
	{
		Update(1, 0, N-1, l, r);
	}
};
signed main()
{
    speed;
    cin>>n>>q;
    cin>>s;
    segtree ss;
    ss.init(n);
    ss.build(1,0,n-1);
    while(q--)
    {
        int t,l,r;cin>>t>>l>>r;
        l--,r--;
        if(t==1)
        {
            ss.update(l,r);
        }
        else 
        {
            cout<<(ss.query(l,r).ok?"Yes":"No")<<endl;
        }
    }
    return 0;
}
