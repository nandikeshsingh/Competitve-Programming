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
        while(a.back()==0)a.pop_back();
        reverse(all(a));
        while(a.back()==0)a.pop_back();
        reverse(all(a));
        int ans=0;
        while(sz(a))
        {
            while(a.back()==1)
            a.pop_back();
            while(a.back()==0)
            {
                a.pop_back();
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


