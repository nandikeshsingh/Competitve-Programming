#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int sum=0;
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i],sum+=vec[i];
        bool ok=0;
        for(int i=0;i<n;i++)
        {
            int tot=sum-vec[i];
            if(tot==(n-1)*vec[i])ok=1;
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}


