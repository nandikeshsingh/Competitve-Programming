#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>q(n),a(n),b(n);
    for(int i=0;i<n;i++)cin>>q[i];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    int lo=0,hi=1e7+5;
    while(hi>lo)
    {
      
        int mid=(lo+hi+1)/2;
        bool f=0;
        for(int i=0;i<=mid;i++)
        {
            bool ok=1;
            for(int j=0;j<n;j++)
            {
                if(i*a[j]+(mid-i)*b[j]>q[j])
                {
                    ok=0;
                    break;
                }
            }
            if(ok){
                f=1;
                break;
            }
        }
        if(f)lo=mid;
        else hi=mid-1;
    }
    cout<<lo<<endl;
    return 0;
}


