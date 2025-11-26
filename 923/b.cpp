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
        vector<int>cnt(26,0);
        string ans;
        for(int i=0;i<n;i++)
        {
            char c;
            for(int j=0;j<26;j++)
            {
                if(cnt[j]==a[i])
                {
                    c=j+'a';
                    cnt[j]++;
                    break;
                }
            }
            ans+=c;

        }   
        cout<<ans<<endl;
    }
    return 0;
}


