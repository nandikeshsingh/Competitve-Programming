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
        int x=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            x|=a[i];
        }
        int y=1e18;
        for(int i=0;i<n;i++)
        {
            int cur=a[i];
            for(int j=0;j<n;j++)
            {
                if(j==i)continue;
                cur=min(cur,cur&a[j]);
            }
            y=min(cur,y);
        }
        cout<<x-y<<endl;
    }
    return 0;
}


