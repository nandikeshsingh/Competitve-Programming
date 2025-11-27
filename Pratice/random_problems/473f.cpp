#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=1e9+7;
int n,q;
vector<int>a;
int l,x;
vector<array<int,3>>vec;
int basis[20];
int sz;
int binpow(int a, int b, int m)
{
	int ans=1;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%m;
		b>>=1;
		a=(a*a)%m;
	}
	return ans;
}

void insert(int x)
{
    for(int i=19;i>=0;i--)
    {
        if(x>>i)
        {
            if(!basis[i])
            {
                basis[i]=x;
                sz++;
                return;
            }
            x^=basis[i];
        }
    }
}
int reduce(int x)
{
    for(int i=19;i>=0;i--)
    {
        if(x>>i)
        {
            if(basis[i])x^=basis[i];
            else return 0;
        }
    }
    return x==0;
}
signed main()
{
    speed;
    cin>>n>>q;
    a.resize(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int cur=0;
    while(q--)
    {
        cin>>l>>x;
        vec.push_back({l,x,cur++});
    }
    q=vec.size();
    sort(all(vec));
    cur=0;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        insert(a[i]);
        while(vec[cur][0]==i+1)
        {
            if(reduce(vec[cur][1]))
            {
                ans.push_back(binpow(2,vec[cur][0]-sz,mod));
            }
            else ans.push_back(0);
            cur++;
        }
        if(cur>=q)break;
    }
    vector<int>has(q);
    for(int i=0;i<q;i++)has[vec[i][2]]=ans[i];
    for(auto& u : has)cout<<u<<endl;
    return 0;
}


