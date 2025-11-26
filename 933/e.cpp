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
	int mn;
  
	//Default Values
	data() : mn(2e18) {};
  };
	int N;
	vector<data> st;
	vector<bool> cLazy;//stores if this values needs to be pushed down or not.
	vector<int> lazy;//stores the value that needs to be pushed down.
    vector<int> dp;
	void init(vector<int>&ddp)
	{
        dp=ddp;
		N = sz(dp);
		st.resize(4 * N + 5);
		cLazy.assign(4 * N + 5, false);
		lazy.assign(4 * N + 5, 0);
	}

	//Write reqd merge functions
	//also consider what if data l or r has default values then what to return;
	void merge(data &cur, data &l, data &r) 
	{
		cur.mn = min(l.mn, r.mn);
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
			st[node].mn = dp[L];//change the value as per the question.
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
        int n,m,k,d;
        cin>>n>>m>>k>>d;
        vector<vector<int>>a(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            cin>>a[i][j];
        }
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            vector<int>dp(m,2e18);
            segtree ss;
            dp[0]=1;
            ss.init(dp);
            ss.build(1,0,m-1);
            // ss.update(0,1);
            // cout<<"Printing ss"<<endl;
            // for(int i=1;i<=29;i++)cout<<ss.st[i].mn<<" ";
            // cout<<endl;
            for(int j=1;j<m;j++)
            {
                int ll=max(j-d-1,0LL);
                int best=ss.query(ll,j-1).mn;
                assert(best+a[i][j]+1<2e18);
                dp[j]=min(dp[j],best+a[i][j]+1);
                ss.update(j,dp[j]);
                // cout<<"j="<<j<<" dp="<<dp[j]<<endl;
            }
            ans.push_back(dp[m-1]);
        }
        // cout<<"Printing ans"<<endl;
        // for(int i=0;i<n;i++)cout<<ans[i]<<" ";
        // cout<<endl;
        int cur=0;
        for(int i=0;i<k;i++)cur+=ans[i];
        int l=0,r=k-1;
        int cur_sum=cur;
        while(r+1<n)
        {
            cur_sum-=ans[l];
            l++;r++;
            cur_sum+=ans[r];
            cur=min(cur,cur_sum);
        }
        cout<<cur<<endl;
    }
    return 0;
}


