#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])ans+=i;
        }
        cout<<ans<<endl;
    }
    return 0;
}

