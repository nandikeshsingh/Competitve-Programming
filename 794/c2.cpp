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
        vector<int>vec(n);
        for(int i=0;i<n;i++)cin>>vec[i];
        if(n%2==1)
        {
            cout<<"NO"<<endl;
            continue;
        }
        sort(vec.begin(),vec.end());
        vector<int>ans;
        for(int i=0;i<n/2;i++)
        {
            ans.push_back(vec[i]);
            ans.push_back(vec[i+n/2]);
        }
        bool ok=1;
        int last=ans[n-1];
        int first=ans[0];
        ans.push_back(first);
        reverse(ans.begin(),ans.end());
        ans.push_back(last);
        reverse(ans.begin(),ans.end());
        for(int i=1;i<=n;i++)
        {
            if(ans[i]>ans[i-1] && ans[i]>ans[i+1])continue;
            if(ans[i]<ans[i-1] && ans[i]<ans[i+1])continue;
            ok=0;
        }
        if(ok)
        {
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
            cout<<endl;
        }
        else cout<<"NO"<<endl;
    }
    return 0;
}