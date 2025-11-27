#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,t;
    cin>>n>>t;
    vector<int>a(n);
    int mn=1e18;
    for(int i=0;i<n;i++)cin>>a[i],mn=min(mn,a[i]);
    int ans=0;
    while(t>=mn)
    {
        int cnt=0,cur=0;
        for(int i=0;i<n;i++)
        {
            if(cur+a[i]<=t)
            {
                cnt++;
                cur+=a[i];
            }
        }
        ans+=(t/cur)*cnt;
        t-=((t/cur)*cur);
    }
    cout<<ans<<endl;
    return 0;
}


