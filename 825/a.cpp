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
        vector<int>a(n),b(n);
        int cntb=0,cnta=0;
        for(int i=0;i<n;i++)cin>>a[i],cnta+=(a[i]==0);
        for(int i=0;i<n;i++)cin>>b[i],cntb+=(b[i]==0);
        int ans=abs(cnta-cntb);
        int tot=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])tot++;
        }
        if(tot==ans)cout<<ans<<endl;
        else cout<<ans+1<<endl;

    }
    return 0;
}


