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
        int n,m;
        cin>>n>>m;
        int ans=m*m;
        ans+=(m*(m+1))/2;
        ans-=(m*m);
        ans+=((n*(n+1))/2-1)*m;
        ans+=(m*(n-1));
        ans-=(m*(n-1));
        cout<<ans<<endl;
      
    }
    return 0;
}

