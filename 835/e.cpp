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
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        vector<int>left(n),right(n);
        int cur=0;
        for(int i=0;i<n;i++)
        {
            left[i]=cur;
            if(a[i]==1)cur++;
        }
        cur=0;
        for(int i=n-1;i>=0;i--)
        {
            right[i]=cur;
            if(a[i]==0)cur++;
        }
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)cnt+=right[i];
        }
        int mx=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0)
            mx=max(right[i]-left[i],mx);
            else 
            mx=max(mx,left[i]-right[i]);
        }
        cout<<cnt+mx<<endl;
    }
    return 0;
}


