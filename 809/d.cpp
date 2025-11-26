#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int mn=a[0]/k;
        int ans=1e18;
        for(int v=mn;v<=a[0];v++)
        {
            // cout<<"v="<<v<<endl;
            int lo=1e18,hi=-1;
            int cur=0;
            for(int i=0;i<n;i++)
            {
                if(v!=0)
                cur=min(a[i]/v,k);
                else cur=k;
                // cout<<"i="<<i<<" cur="<<cur<<endl;
                // if(cur>=v)
                lo=min(lo,a[i]/cur);
                hi=max(hi,a[i]/cur);
            }
            // cout<<"lo="<<lo<<" hi="<<hi<<endl;
            // cout<<"hi="<<hi<<" v="<<v<<endl;
            ans=min(ans,hi-lo);
        }
        cout<<ans<<endl;
    }
    return 0;
}



