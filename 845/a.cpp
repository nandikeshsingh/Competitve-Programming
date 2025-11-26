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
        int ans=0;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if((a[i]%2)==(a[i-1]%2))cnt++;
            else 
            {
                ans+=(cnt-1);
                cnt=1;
            }
        }
        ans+=cnt-1;
        cout<<ans<<endl;
    }
    return 0;
}


