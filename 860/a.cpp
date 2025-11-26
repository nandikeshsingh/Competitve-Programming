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
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n;i++)cin>>b[i];
        bool ok=1;
        for(int i=0;i<n-1;i++)
        {
            if(a[i]<=a[n-1] && b[i]<=b[n-1])continue;
            else 
            {
                swap(a[i],b[i]);
                if(a[i]<=a[n-1] && b[i]<=b[n-1])continue;
                else
                {
                    ok=0;
                    break;
                }
            }
        }
        if(ok)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;
}


