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
        vector<int>a(n,0);
        set<int>s;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(s.count(a[i]))ans++;
            else s.insert(a[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}


