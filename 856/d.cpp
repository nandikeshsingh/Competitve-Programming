#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    int ss=sqrt(n);
    for (int i = 2; i <= ss; i++)
    {
        if (n % i == 0)
            return false;
    }

    return true;
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
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>a(n+n);
    for(int i=0;i<n;i++)cin>>a[i];
    map<int,int>np;
    set<int>p;
    int l=0,r=0;
    for(int i=0;i<n;i++)
    {
        if(isPrime(a[i]))
        {
            if(p.count(a[i])==0)p.insert(a[i]);
            else np[a[i]]++,r++;
        }
        else np[a[i]]++,r++;
    }   
    l=sz(p);
    int ans=0;
    if(r>l || (l-r)%2)cout<<0<<endl;
    else 
    {
        int t=(l-r)/2;
    }
    return 0;
}


