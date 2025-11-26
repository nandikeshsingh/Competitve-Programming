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
        int n,x;
        cin>>n>>x;
        x++;
        vector<int>a(n+1,0);
        for(int i=1;i<=n;i++)cin>>a[i];
        vector<int>p(n+1,0LL);
        for(int i=1;i<=n;i++)p[i]=p[i-1]^a[i];
        int ans=-1;
        // for(int bit=30;bit>=0;bit--)
        for(int cur=x-1;cur>=0;cur--)
        {
            // if((x>>bit)&1)
            {
                // int cur=((x^(1<<bit))|((1<<bit)-1));
                if((p[n]&cur)==p[n])
                {
                    int cnt=0;
                    for(int i=1;i<=n;i++)
                    {
                        if((p[i]&cur)==p[i])
                        cnt++;
                    }
                    ans=max(ans,cnt);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


