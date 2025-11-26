#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<int>vec(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(s[i]=='W')vec[i+1]=vec[i]+1;
            else vec[i+1]=vec[i];
        }
        int cur=vec[k]-vec[0];
        int ans=cur;
        for(int i=0;i+k<=n;i++)
        {
            ans=min(ans,vec[i+k]-vec[i]);
        }
        cout<<ans<<endl;

    }
    return 0;
}

