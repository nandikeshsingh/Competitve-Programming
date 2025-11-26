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
        string s;
        cin>>s;
        string pi="3141592653589793238462643383279";
        int ans=0;
        int cur=0;
        for(int i=0;i<(int)s.length();i++)
        {
            if(s[i]==pi[i])
            {
                ans++;
            }
            else break;
        }
        cout<<ans<<endl;
    }
    return 0;
}


