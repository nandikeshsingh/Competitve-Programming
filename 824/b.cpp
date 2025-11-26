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
        int ok=(2*a[0])-1;
        int ans=0;
        for(int i=n-1;i>0;i--)
        {
            if(a[i]>ok)
            {
                int cnt=a[i]/ok;
                if(a[i]%ok)
                ans+=cnt;
                else ans+=(cnt-1);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


