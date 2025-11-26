#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
// #define for(i,n)   for(int i=0;i<(n);++i)
// #define rep(i,a,b)   for(int i=(a);i<=(b);++i)
// #define per(i,b,a)   for(int i=(b);i>=(a);--i)
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
#define pb push_back
#define F first
#define S second
using namespace std;
const int N=2e6+1;
signed main()
{
    speed;
        vector<vector<int>> divisors(N+1);

    for (int i = 1; i <= N; i++) {
    for (int j = i; j <= N; j += i) {
        divisors[j].push_back(i);
    }
}
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        int ans=0;
        for(int g=1;g<=m;g++)
        {
            int b=g;
            while(b<=m)
            {
                for(auto& k : divisors[g])
                {
                    int p=g/k;
                    int a=p*g;
                    if(__gcd(a,b)==g && (b*g)%(a+b)==0)
                    {
                        ans++;
                    }
                }
                b+=g;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


