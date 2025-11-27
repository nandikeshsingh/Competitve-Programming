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
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int>l(n),r(n);
    l[0]=1;
    for(int i=1;i<n;i++)
    {
        l[i]=min(a[i],l[i-1]+1);
    }
    r[n-1]=1;
    for(int i=n-2;i>=0;i--)r[i]=min(a[i],r[i+1]+1);
    int ans=0;
    for(int i=0;i<n;i++)ans=max(ans,min(r[i],l[i]));
    cout<<ans<<endl;
    return 0;
}


