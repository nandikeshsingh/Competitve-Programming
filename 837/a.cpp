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
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        sort(all(vec));
        int mn=vec[0];
        int mx=vec[n-1];
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            if(vec[i]==mn)x++;
            if(vec[i]==mx)y++;
        }
        if(mn!=mx)
        cout<<2*x*y<<endl;
        else cout<<n*(n-1)<<endl;
    }
    return 0;
}


