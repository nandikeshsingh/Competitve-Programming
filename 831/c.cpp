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
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(all(a));
        int bestl=a[n-1]-a[0]+a[1]-a[0];
        int bestr=a[n-1]-a[0]+a[n-1]-a[n-2];
        int ansl=bestl;
        int ansr=bestr;
        for(int i=1;i<n-2;i++)
        {
            int now=a[n-1]-a[i]+a[i+1]-a[i];
            ansl=max(ansl,now);
            // int lost=a[i]-a[0];
            // lost*=2;
            // int gain=a[i+1]-a[i];
            // if(gain>lost)
            // {
            //     ansl=max(ansl,bestl-lost+gain);
            // }
        }
        for(int i=n-2;i>=2;i--)
        {
            int now=a[i]-a[0]+a[i]-a[i-1];
            ansr=max(ansr,now);
            // int lost=a[n-1]-a[i];
            // lost*=2;
            // int gain=a[i]-a[i-1];
            // if(gain>lost)
            // {
            //     ansr=max(ansr,bestr-lost+gain);
            // }
        }
        cout<<max(ansl,ansr)<<endl;
    }
    return 0;
}


