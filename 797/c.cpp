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
        vector<int>s(n),f(n);
        for(int i=0;i<n;i++)cin>>s[i];
        for(int i=0;i<n;i++)cin>>f[i];
        vector<int>d(n);
        for(int i=0;i<n;i++)
        {
            if(i==0)d[i]=f[i]-s[i];
            else 
            {
                if(s[i]>=f[i-1])d[i]=f[i]-s[i];
                else d[i]=f[i]-f[i-1];
            }
        }
        for(auto& u : d)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}

