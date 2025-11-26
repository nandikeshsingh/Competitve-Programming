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
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++)cin>>a[i];
        int lo=1,hi=1e18;
        // vector<int>rim(n+1,0);
        // vector<int>na(n+1,0);
        while(lo<hi)
        {
            int mid=(lo+hi+1)>>1;
            
            vector<int>need_a(n+1,0);
            for(int i=1;i<=n;i++)
            {
                // rim[i]=0;
                // na[i]=0;
                need_a[i]+=mid/n;
                
            }
            int rim=mid-((mid/n)*n);
            int need=0;
            int cnt=0;
            for(int i=1;i<=n;i++)
            {
                if(a[i]<need_a[i])
                {
                    
                    need+=need_a[i]-a[i];

                }
                else if(a[i]>need_a[i])cnt++;
            }
            if(cnt>=rim)rim=0;
            else rim-=cnt;
            // cout<<"lo="<<lo<<" hi="<<hi<<" mid="<<mid<<endl;
            if(need+rim<=k)
            {
                lo=mid;
  
            }
            else hi=mid-1;
            // cout<<"lo="<<lo<<" hi="<<hi<<" mid="<<mid<<endl;
        }
   
        cout<<lo-n+1<<endl;
    }
    return 0;
}


