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
        string s;
        cin>>s;
        int ans=n;
        while(s.back()=='W')
        {
            ans--;
            s.pop_back();
        }
        reverse(all(s));
        while(s.back()=='W')
        {
            ans--;
            s.pop_back();
        }
        cout<<ans<<endl;
    }
    return 0;
}


