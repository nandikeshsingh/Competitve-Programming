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
        int n,k;
        cin>>n>>k;
        vector<int>p(n+1);
        for(int i=1;i<=n;i++)cin>>p[i];
        int cnt=0;
        int now=1;
        for(int i=1;i<=n;i++)
        {
            if(p[i]==now)now++,cnt++;
        }
        int rim=n-cnt;
        cout<<ceil((double)rim/(double)k)<<endl;
    }
    return 0;
}


