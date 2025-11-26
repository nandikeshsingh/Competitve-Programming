
#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
        vector<int>arr(n);
        for(int i=0;i<n;i++)cin>>arr[i];
        int ans=0;
        int now=arr[0];
        for(int i=1;i<n;i++)
        {
            ans+=abs(arr[i]-arr[i-1]);
            if(arr[i-1]>arr[i])
            {
                now-=(arr[i-1]-arr[i]);
            }
        }
        cout<<ans+abs(now)<<endl;
    }
    return 0;
}

