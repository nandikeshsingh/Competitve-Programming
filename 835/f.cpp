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
        int n,c,d;
        cin>>n>>c>>d;
        vector<int>a(n);
        int mx=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            mx=max(mx,a[i]);
        }
        sort(all(a));
        reverse(all(a));
        for(int i=1;i<n;i++)a[i]+=a[i-1];
        if(d*mx<c)
        {
            cout<<"Impossible"<<endl;
        }
        else 
        {
            int lo=0,hi=1e18;
            while(lo<hi)
            {
                // cout<<"lo="<<lo<<" hi="<<hi<<endl;
                int mid=(lo+hi+1)/2;
                int tot=0;
                if(mid>n-1)tot=a[n-1];
                else tot=a[mid];
                int div=d/(mid+1);
                int rim=d%(mid+1);
                int coins=div*tot;
                if(rim>n)coins+=a[n-1];
                else if(rim>0)coins+=a[rim-1];
                if(coins>=c)lo=mid;
                else hi=mid-1;
            }
            if(lo==1e18)
            cout<<"Infinity"<<endl;
            else cout<<lo<<endl;
        }
    }
    return 0;
}


