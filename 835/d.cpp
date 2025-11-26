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
        vector<int>na;
        na.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            if(a[i]!=a[i-1])na.push_back(a[i]);
        }
        int len=sz(na);
        bool ok=1;
        na.push_back(1e18);
        reverse(all(na));
        na.push_back(1e18);
        reverse(all(na));
        for(int i=1;i<=len;i++)
        {
            if(na[i]>na[i-1] && na[i]>na[i+1])
            {
                ok=0;
                break;
            }
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


