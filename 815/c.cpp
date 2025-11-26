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
        int n,m;
        cin>>n>>m;
        vector<vector<int>>vec(n,vector<int>(m));
        int tot=0;
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>s;

            for(int j=0;j<m;j++)
            {
                vec[i][j]=(s[j]-'0');
                tot+=(vec[i][j]==1);
            }
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            int cnt=0;
            for(int j=1;j<m;j++)
            {
                cnt=(vec[i][j]+vec[i-1][j-1]+vec[i][j-1]+vec[i-1][j]);
                if(cnt==0)ans=max(ans,tot);
                else if(cnt==1)ans=max(ans,tot-cnt+1);
                else if(cnt==3)ans=max(ans,tot-cnt+2);
                else if(cnt==4)ans=max(ans,tot-cnt+2);
                else
                {
                    ans=max(ans,tot-cnt+2);
                }
            }
            // mxx=max(mxx,cnt);
        }
        // cout<<"Printing ans"<<endl;
        cout<<ans<<endl;
    }
    return 0;
}


