#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int h,w,n;
const int N=2e5+5;
int fact[N], invfact[N];
vector<pair<int,int>>pos;
const int mod=1e9+7;
bool cmp(pair<int,int>&p1, pair<int,int>&p2)
{
    if(p1.second!=p2.second)return p1.second<p2.second;
    else return p1.first<p2.first;
}
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

int modinv(int k)
{
	return binpow(k, mod-2, mod);
}

void precompute()
{
	fact[0]=fact[1]=1;
	for(int i=2;i<N;i++)
	{
		fact[i]=fact[i-1]*i;
		fact[i]%=mod;
	}
	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;i--)
	{
		invfact[i]=invfact[i+1]*(i+1);
		invfact[i]%=mod;
	}
}
int nCr(int x, int y)
{
	if(y>x || x<=0 || y<0)return 0;
	int num=fact[x];
	num*=invfact[y];
	num%=mod;
	num*=invfact[x-y];
	num%=mod;
	return num;
}

signed main()
{
    speed;
    precompute();
    cin>>h>>w>>n;
    for(int i=1;i<=n;i++)
    {
        int x,y;cin>>x>>y;
        pos.push_back({x,y});
    }
    sort(all(pos),cmp);
    int ans=nCr(h+w-2,h-1);
    vector<int>up(n);
    for(int i=0;i<n;i++)
    {
        int r=pos[i].first-1;
        int c=pos[i].second-1;
        int tot=nCr(r+c,r);
        int rp=0;
        for(int j=0;j<i;j++)
        {
            if(pos[j].first<=pos[i].first)
            {
                int has=nCr(r+c+2-pos[j].first-pos[j].second,r+1-pos[j].first);
                has=(has*up[j])%mod;
                rp=(rp+has)%mod;
            }
        }
        up[i]=(tot-rp+mod)%mod;
        int p1=nCr(h-pos[i].first+w-pos[i].second,h-pos[i].first);
        ans=(ans-(up[i]*p1)%mod+mod)%mod;
    }
    cout<<ans<<endl;
    return 0;   
}


