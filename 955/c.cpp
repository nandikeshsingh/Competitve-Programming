#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define fo(i,n)   for(int i=0;i<(n);++i)
#define rep(i,a,b)   for(int i=(a);i<=(b);++i)
#define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
using ii = pair<int,int>;
using vii = vector<ii>;
using vi = vector<int>;
struct segtree
{
  struct data
  {
	//Use required attributes
	int mn;
  
	//Default Values
	data() : mn(0) {};
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
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	//also consider what if data l or r has default values then what to return;
	void merge(data &cur, data &l, data &r) 
	{
		cur.mn = max(l.mn, r.mn);
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
			st[node].mn = 0;//change the value as per the question.
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

	void pUpdate(int node, int L, int R, int pos, int val)
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

	void update(int pos, int val)
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
    int t;
    cin>>t;
    while(t--)
    {
        int n,l,r;
        cin>>n>>l>>r;
        vi a(n+1,0);
        rep(i,1,n)cin>>a[i];
        int ans=0;
        int cur=0;
        int ll=0;
        int rr=0;
        while(rr+1<=n)
        {
            if(cur<=r && cur>=l)
            {
                ll=rr+1;
                rr++;
                ans++;
                if(rr<=n)
                cur=a[rr];
            }
            else if(cur<l)
            {
                cur+=a[rr+1];
                rr++;
            }
            else if(cur>r)
            {
                cur-=a[ll];
                ll++;
            }
        }
        if(cur<=r && cur>=l)ans++;
        cout<<ans<<endl;
    }
    return 0;
}


