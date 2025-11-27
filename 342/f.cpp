#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
struct segtree
{
  struct data
  {
	//Use required attributes
	long double mn;
  
	//Default Values
	data() : mn(0.0) {};
  };
	int N;
	vector<data> st;
	vector<bool> cLazy;//stores if this values needs to be pushed down or not.
	vector<long double> lazy;//stores the value that needs to be pushed down.
    vector<long double> vec;
	void init(vector<long double>&vv)
	{
        int n=sz(vv);
        vec=vv;
		N = n;
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	//also consider what if data l or r has default values then what to return;
	void merge(data &cur, data &l, data &r) 
	{
		cur.mn = l.mn + r.mn;
	}
	
	//Handle lazy propagation appriopriately and carefully
	//might need to do cLazy[node*2] = 1-cLazy[node] if updates cancels(like flip operation);
	void propagate(int node, int L, int R)
	{
		if(L != R)//push the changes 
		{
			cLazy[node*2] = 1;
			cLazy[node*2 + 1] = 1;
			lazy[node*2] = lazy[node];
			lazy[node*2 + 1] = lazy[node]; 
		}
		st[node].mn = lazy[node];//then change the current node
		cLazy[node] = 0;
    	lazy[node] = 0;
	}

	void build(int node, int L, int R)
	{
		if(L==R)
		{
			st[node].mn = vec[L];//change the value as per the question.
			return;
		}
		int M=(L + R)/2;
		build(node*2, L, M);
		build(node*2 + 1, M + 1, R);
		merge(st[node], st[node*2], st[node*2+1]);
	}

	data Query(int node, int L, int R, int i, int j)
	{
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
		merge(cur, left, right);
		return cur;
	}

	data pQuery(int node, int L, int R, int pos)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
			return st[node];
		int M = (L + R)/2;
		if(pos <= M)
			return pQuery(node*2, L, M, pos);
		else
			return pQuery(node*2 + 1, M + 1, R, pos);
	}	

	void Update(int node, int L, int R, int i, int j, int val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(j<L || i>R)
			return;
		if(i<=L && R<=j)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		Update(node*2, L, M, i, j, val);
		Update(node*2 + 1, M + 1, R, i, j, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	void pUpdate(int node, int L, int R, int pos, long double val)
	{
		if(cLazy[node])
			propagate(node, L, R);
		if(L == R)
		{
			cLazy[node] = 1;
			lazy[node] = val;
			propagate(node, L, R);
			return;
		}
		int M = (L + R)/2;
		if(pos <= M)
			pUpdate(node*2, L, M, pos, val);
		else
			pUpdate(node*2 + 1, M + 1, R, pos, val);
		merge(st[node], st[node*2], st[node*2 + 1]);
	}

	data query(int pos)
	{
		return pQuery(1, 0, N-1, pos);
	}

	data query(int l, int r)
	{
		return Query(1, 0, N-1, l, r);
	}

	void update(int pos, long double val)
	{
		pUpdate(1, 0, N-1, pos, val);
	}

	void update(int l, int r, int val)
	{
		Update(1, 0, N-1, l, r, val);
	}
};
signed main()
{
    speed;
    int n,l,d;
    cin>>n>>l>>d;
    vector<long double>x(n+1,0.0),y(n+d+10,0.0);
    x[0]=1.0;
    y[0]=1.0;
     long double p=(long double)1/(long double)d;
    segtree sx,sy;
    sx.init(x);
    sx.update(0,1.0);
    sy.init(y);
    sy.update(0,1.0);
    long double sum_x=0.0;
    for(int i=1;i<=n;i++)
    {
        int ll=max(i-d,0LL);
        int rr=i-1;
        long double tot=sx.query(ll,rr).mn;
        tot*=p;
        x[i]=tot;
        sx.update(i,tot);
        sum_x+=x[i];
    }
    long double ans=0.0;
    long double y_fail=0.0;
    for(int i=1;i<=l-1+d;i++)
    {
        int ll=max(i-d,0LL);
        int rr=min(i-1,l-1);
        long double tot=sy.query(ll,rr).mn;
        tot*=p;
        y[i]=tot;
        sy.update(i,tot);
        if(i>n)
        {
            y_fail+=y[i];
        }
    }
    ans=max(ans,y_fail);
    for(int i=n;i>=l+1;i--)
    {
        ans=max(x[i]*(sy.query(l,i-1).mn+y_fail),ans);
    }
    assert(ans<=1.0);
    cout<<fixed<<setprecision(15)<<ans<<endl;
    return 0;
}

