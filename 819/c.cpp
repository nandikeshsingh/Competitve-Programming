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
        string s;
        cin>>s;
        int ans=1;
        for(int i=1;i<2*n;i++)
        {
            if(s[i]==')' && s[i-1]==')')ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
