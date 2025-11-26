#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
bool check(int a,int b,int x,int y)
{
    if(x>b || y<a)return 0;
    else return 1;
}
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        int mn=a[0]-x;
        int mx=a[0]+x;
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int cur_mn=a[i]-x;
            int cur_mx=a[i]+x;
            if(!check(mn,mx,cur_mn,cur_mx))
            {
                ans++;
                mn=cur_mn;
                mx=cur_mx;
            }
            else 
            {
                mn=max(mn,cur_mn);
                mx=min(mx,cur_mx);
            }
        }
        // cout<<"Printing"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}