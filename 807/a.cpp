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
        int n,x;
        cin>>n>>x;
        vector<int>vec(n+n);
        for(int i=0;i<2*n;i++)cin>>vec[i];
        sort(vec.begin(),vec.end());
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            if(vec[i+n]-vec[i]<x)ok=0;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
      
    }
    return 0;
}

