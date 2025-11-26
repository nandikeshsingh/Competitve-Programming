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
        vector<int>s(n);
        for(int i=0;i<n;i++)cin>>s[i];
        multiset<int>ms;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==0)
            {
                if(sz(ms)>0)
                {
                    ans+=*prev(ms.end());
                    ms.erase(prev(ms.end()));
                }
            }
            else ms.insert(s[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}


