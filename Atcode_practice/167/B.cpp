#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=998244353;
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
signed main()
{
    speed;
    int a,b,bb;
    cin>>a>>b;
    bb=b;
    b%=mod;
    map<int,int>mp;
    while(a%2==0)
    {
        mp[2]++;
        a/=2;
    }
    for(int i=3;i<=sqrt(a);i+=2)
    {
        while(a%i==0)
        {
            mp[i]++;
            a/=i;
        }
    }
    if(a>2)mp[a]++;
    bool ok=1;
    for(auto& u : mp)
    {
        if(u.second%2)
        {
            ok=0;
            break;
        }
    }
    int cnt=1;
    for(auto& u : mp)
    {
        int tot=0;
        u.second%=mod;
        tot=(tot+((u.second*b)%mod))%mod;
        tot=(tot+1)%mod;
        cnt=(cnt*tot)%mod;
    }
    if(!ok)
    {
        cnt=(cnt*b)%mod;
        cnt=(cnt*modinv(2))%mod;
    }
    else 
    {
        cnt=(cnt-1+mod)%mod;
        cnt=(cnt*b)%mod;
        cnt=(cnt*modinv(2))%mod;
        if(bb%2)bb--;
        bb%=mod;
        bb=(bb*modinv(2))%mod;
        cnt+=bb;
        cnt%=mod;
    }
    cout<<cnt<<endl;
    return 0;
}


