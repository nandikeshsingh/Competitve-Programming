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
        int x=0,y=0;
        for(auto& u : s)
        {
            if(u=='1')y++;
            else x++;
        }
        int cx=0,cy=0;
        int cur=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='1')
            {
                cx=max(cx,cur);
                cur=0;
            }
            else cur++;
        }
        cx=max(cx,cur);
        cur=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                cy=max(cy,cur);
                cur=0;
            }
            else cur++;
        }
        cy=max(cy,cur);
        cout<<max({x*y,cx*cx,cy*cy})<<endl;
    }
    return 0;
}


