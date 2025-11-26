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
        bool ok=1;
        for(int i=0;i<n;i++)cin>>a[i];
        int g=0;
        for(int i=0;i<n;i++)
        {
            g=__gcd(g,a[i]);
        }
        if(g==1)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}


