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
        vector<int>a(n),b;
        for(int i=0;i<n;i++)cin>>a[i];
        b.push_back(a[0]);
        b.push_back(a[0]);
        for(int i=1;i<n;i++)
        {
            int last=b.back();
            if(last%a[i]==0)b.push_back(a[i]);
            else 
            {
                int g=__gcd(last,a[i]);
                int rim=a[i]/g;
                b.back()*=rim;
                b.push_back(a[i]);
            }
        }
        bool ok=1;
        for(int i=1;i<sz(b);i++)
        {
            if(__gcd(b[i],b[i-1])!=a[i-1])
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


