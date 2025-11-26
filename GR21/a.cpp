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
        int n,z;
        cin>>n>>z;
        vector<int>vec(n);
        int ans=0;      
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            ans=max(ans,vec[i]|z);
        }
        // ans|=z;
        cout<<ans<<endl;
      
    }
    return 0;
}

