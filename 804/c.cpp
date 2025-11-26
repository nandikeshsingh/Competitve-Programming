#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
const int mod=1e9+7;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>vec(n),pos(n);
        for(int i=0;i<n;i++)cin>>vec[i],pos[vec[i]]=i;
        int mn=pos[0];
        int mx=pos[0];
        int ans=1;
        for(int i=1;i<n;i++)
        {
            if(pos[i]<mn)mn=pos[i];
            else if(pos[i]>mx)mx=pos[i];
            else ans=(ans*(mx-mn-i+1))%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
