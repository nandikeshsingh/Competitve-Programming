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
signed main()
{
    speed;
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(n+1);
    int z=0;
    for(int i=1;i<=n;i++)cin>>a[i],z+=(a[i]==0);
    sort(all(a));
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        int zr=0,zl=0,less=0;
        for(int j=k;j<=n;j++)
        {
            if(a[j]==0)zr++;
            else if(a[j]<i)less++;
        }
        for(int j=1;j<k;j++)
        {
            if(a[j]==0)zl++;
        }
        if(a[k]>i)continue;
        cout<<"i="<<i<<" zl="<<zl<<" zr="<<zr<<" less="<<less<<endl;
        if(less<=zl)
        {
            zl-=less;
            zr+=less;
            int cur=i;
            cur=(cur*binpow(i,zl,mod))%mod;
            if(less)
            cur=(cur*binpow(m-i+1,zr-1,mod))%mod;
            ans=(ans+cur)%mod;
            cout<<"i="<<i<<" cur="<<cur<<endl;
        }
        
    }
    // if(a[k]==0)z--;
    int down=binpow(m,z,mod);
    ans=(ans*binpow(down,mod-2,mod))%mod;
    cout<<ans<<endl;
    return 0;
}


