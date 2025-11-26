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
        vector<int>b(n-1),a(n,0);
        int mn=1e18;
        int mx=-1e18;
        for(int i=0;i<n-1;i++)
        {
            cin>>b[i];
            mn=min(mn,b[i]);
            mx=max(mx,b[i]);
        }
        if(mn==mx)
        {
            for(auto& u : b)cout<<u<<" ";
            cout<<b[0]<<endl;
        }
        else 
        {
            for(int i=1;i<n-1;i++)
            {
                if(b[i]>b[i-1])
                {
                    a[i+1]=b[i];
                    a[i]=b[i-1];
                }
                else if(b[i]<b[i-1])
                {
                    a[i-1]=b[i-1];
                    a[i]=b[i];
                }
                else a[i]=b[i];
            }
            for(auto& u : a)cout<<u<<" ";
            cout<<endl;
        }

    }
    return 0;
}


