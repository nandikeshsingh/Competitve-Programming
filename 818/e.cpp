#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
const int mod=1e9+7;
vector<int> phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
        phi[i] = i - 1;

    for (int i = 2; i <= n; i++)
        for (int j = 2 * i; j <= n; j += i)
              phi[j] -= phi[i];
    return phi;
}
int lcm(int a,int b)
{
    return ((a*b)/__gcd(a,b))%mod;
}
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>phi=phi_1_to_n(n);
    int ans=0;
    for(int c=1;c<=n-2;c++)
    {
        int cur=n-c;
        for(int d=1;d*d<=cur;d++)
        {
            if(cur%d==0)
            {
                int f=d;
                int s=cur/d;
                if(cur/f>=2)
                {
                    ans+=((lcm(c,f)*phi[(n-c)/f])%mod);
                    ans%=mod;
                }
                if(f!=s)
                {
                    if(cur/s>=2)
                    {
                        ans+=((lcm(c,s)*phi[(n-c)/s])%mod);
                        ans%=mod;
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}   
