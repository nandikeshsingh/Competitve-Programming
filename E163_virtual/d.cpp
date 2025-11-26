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
        int n=s.length();
        int ans=0;
        vector<int>cnt(2,0);
        for(int l=1;2*l<=n;l++)
        {
            cnt[1]=0;cnt[0]=0;
            int st=0;
            int tot=l;
            while(tot--)
            {
                if(s[st]==s[st+l]||s[st]=='?'||s[st+l]=='?')
                {
                    cnt[1]++;
                }
                else cnt[0]++;
                st++;
            }
            if(cnt[0]==0)ans=max(ans,2*l);
            int i=0,j=i+l-1;
            while(j+l+1<=n-1)
            {
                if(s[i]==s[i+l]||s[i]=='?'||s[i+l]=='?')
                {
                    cnt[1]--;
                }
                else cnt[0]--;
                i++;
                j++;
                if(s[j]==s[j+l]||s[j]=='?'||s[j+l]=='?')
                {
                    cnt[1]++;
                }
                else cnt[0]++;
                if(cnt[0]==0)ans=max(ans,2*l);
            }    
        }
        cout<<ans<<endl;
    }
    return 0;
}


