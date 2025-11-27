#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;cin>>n;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    vector<int>s(n),t(n);
    for(int i=1;i<n;i++)cin>>s[i]>>t[i];
    for(int i=1;i<n;i++)
    {
        if(s[i]<=a[i])
        {
            int d=a[i]/s[i];
            a[i+1]+=(d*t[i]);
        }
    }
    cout<<a[n]<<endl;
    return 0;
}


