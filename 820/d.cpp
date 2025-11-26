#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
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
        vector<int>x(n),y(n),has(n);
        for(int i=0;i<n;i++)cin>>x[i];
        for(int i=0;i<n;i++)cin>>y[i];
        for(int i=0;i<n;i++)has[i]=y[i]-x[i];
        sort(all(has));
        int ans=0;
        int l=0,r=n-1;
        while(l<r)
        {
            if(has[l]+has[r]>=0)
            {
                ans++;
                l++;r--;
            }
            else if(has[l]+has[r]<0)
            {
                l++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


