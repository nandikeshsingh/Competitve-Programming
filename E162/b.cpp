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
        int n,k;cin>>n>>k;
        vector<int>a(n),x(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>x[i];
        vector<int>vec(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(x[i]<0)vec[-x[i]]+=a[i];
            else vec[x[i]]+=a[i];
        }
        bool ok=1;
        int cur=0;
        for(int i=1;i<=n;i++)
        {
            if(vec[i])
            {
                cur+=vec[i];
                int t=i;
                int b=t*k;
                if(b<cur)
                {
                    ok=0;
                    break;
                }
            }
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}


