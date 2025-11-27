#include<bits/stdc++.h>
#define int unsigned long long
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
int binpow(int a, int b, int m)
{
    assert(a>=0 && b>=0);
	int ans=1LL;
	while(b)
	{
        // cout<<"b="<<b<<endl;
		if(b&1LL)
			ans=(ans*a)%m;
		b>>=1LL;
		a=(a*a)%m;
	}
	return ans;
}
const int mod=998244353;
signed main()
{
    speed;
    int n;cin>>n;
    int d=0;
    int nn=n;
    while(nn)
    {
        d++;
        nn/=10;
    }
    // cout<<"done 1"<<endl;
    int tot=(d-1)*n;
    // cout<<"tot="<<tot<<" d="<<d<<" n="<<n<<endl;
    int ans=0;
    int cur=n%mod;
    // cout<<"here"<<endl;
    cur=(cur*(binpow(10,tot,mod)))%mod;
    cur=(cur*binpow(10,n,mod))%mod;
    // cout<<"done 2"<<endl;
    int up=binpow(10,tot,mod);
    up=(up*binpow(10,n,mod))%mod;
    // cout<<"done 3"<<endl;
    up=(up-1LL+mod)%mod;
    int down=binpow(10,tot,mod);
    down=(down*binpow(10,n+d,mod))%mod;
    // cout<<"done 4"<<endl;
    int right=binpow(10,tot,mod);
    right=(right*binpow(10,n,mod))%mod;
    // cout<<"done 5"<<endl;
    if(down>=right)
    down=(down-right+mod)%mod;
    else 
    {
        down+=mod;
        down-=right;
        down%=mod;
    }
    down=(binpow(down,mod-2,mod));
    // cout<<"done 6"<<endl;
    up=(up*down)%mod;
    ans=(up*cur)%mod;
    cout<<ans<<endl;
    return 0;
}


