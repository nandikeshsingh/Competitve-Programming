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
        int n,q;
        cin>>n>>q;
        vector<int>a(n+1),s(n+1),xr(n+1);
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            s[i]=s[i-1]+a[i];
            xr[i]=xr[i-1]^a[i];
        }
        int _;cin>>_>>_;
        int mx=-1e18;
        int L=-1,R=-1;
        for(int l=1;l<=n;l++)
        {
            int val=(s[n]-s[l-1])-(xr[n]^xr[l-1]);
            if(val>=mx)
            {
                mx=val;
                int lo=l,hi=n;
                while(lo<hi)
                {
                    int mid=(lo+hi)>>1;
                    int cur=(s[mid]-s[l-1])-(xr[mid]^xr[l-1]);
                    if(cur<val)lo=mid+1;
                    else hi=mid;
                }
                L=l;R=lo;
            }
        }
        cout<<L<<" "<<R<<endl;
    }
    return 0;
}


