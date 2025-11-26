#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i]>>b[i];
        int g=a[0]*b[0];
        int l=b[0];
        int ans=1;
        for(int i=1;i<n;i++)
        {
            g=__gcd(g,a[i]*b[i]);
            l=lcm(l,b[i]);
            if(g%l)
            {
                ans++;
                g=a[i]*b[i];
                l=b[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


