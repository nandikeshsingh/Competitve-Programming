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
        vector<int>a(n+1),pre(n+1);
        int tot=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            tot+=(a[i]==2);
            pre[i]=pre[i-1]+(a[i]==2);
        }
        int ans=-1;
        for(int i=1;i<n;i++)
        {
            if(pre[i]==tot-pre[i])
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
