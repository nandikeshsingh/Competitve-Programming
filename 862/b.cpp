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
        char c=s[n-1];
        int last=n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i]<c)
            {
                c=s[i];
                last=i;
            }
        }
        string ans;
        ans+=c;
        for(int i=0;i<last;i++)
        {
            ans+=s[i];
        }
        for(int i=last+1;i<n;i++)
        {
            ans+=s[i];
        }
        cout<<ans<<endl;
    }
    return 0;
}


