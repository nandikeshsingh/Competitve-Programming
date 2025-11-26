#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
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
        if(n==1)cout<<0<<endl;
        else if(n==2)cout<<abs(a[0]-a[1])<<endl;
        else{
            int f=1e18,s=-1e18,x=-1e18;
            for(int i=1;i<n;i++)s=max(s,a[i]),x=max(x,(-a[i]+a[i-1]));
            for(int i=0;i<n-1;i++)f=min(f,a[i]);
            cout<<max({a[n-1]-f,s-a[0],x})<<endl;
        }
    }
    return 0;
}


