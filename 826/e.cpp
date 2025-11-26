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
        vector<int>b(n+1);
        for(int i=1;i<=n;i++)cin>>b[i];
        vector<int>ok(n+1);
        ok[0]=1;
        for(int i=1;i<=n;i++)
        {
            if(i-b[i]-1>=0)
            ok[i]|=ok[i-b[i]-1];
            if(i+b[i]<=n)
            ok[i+b[i]]|=ok[i-1];
        }
        if(ok[n])cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
