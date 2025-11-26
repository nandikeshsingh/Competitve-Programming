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
        int n;
        cin>>n;
        vector<int>vec(n);
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            if(vec[i]>0)vec[i]=1;
        }
        int ans=0;
        vec.push_back(0);
        reverse(vec.begin(),vec.end());
        vec.push_back(0);
        reverse(vec.begin(),vec.end());
        for(int i=0;i<=n;i++)
        {
            if(vec[i]==0 && vec[i+1]==1)ans++;
        }
        if(ans>2)ans=2;
        cout<<ans<<endl;
      
    }
    return 0;
}

