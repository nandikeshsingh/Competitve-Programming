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
    int d=0;
    int curr=1;
    while(1)
    {
        d++;
        curr*=5;
        if(curr>=n)break;
    }
    int ans=0;
    for(int i=d;i>=1;i--)
    {
        int rem=pow(5,i-1);
        int cur=pow(5,i);
        int cnt=2;
        while(cur-rem>=n)
        cur-=rem,cnt+=2;
        ans*=10;
        ans+=(10-cnt);
        n-=((10-cnt)/2)*rem;
    }
    cout<<ans<<endl;
    return 0;
}


