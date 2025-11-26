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
        string s,t;
        cin>>s>>t;
        string x,y;
        x+=s[0];
        y+=t[0];
        // int x=0,y=0;
        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])x+=s[i];
            if(t[i]!=t[i-1])y+=t[i];
        }
        if(x!=y)cout<<-1<<endl;
        else 
        {
            int ans=0;
            vector<int>a,b;
            for(int i=1;i<n;i++)
            {
                if(s[i]!=s[i-1])
                {
                    a.push_back(i);
                }
                if(t[i]!=t[i-1])
                {
                    b.push_back(i);
                }
            }
            for(int i=0;i<a.size();i++)ans+=abs(a[i]-b[i]);
            cout<<ans<<endl;
        }
      
    }
    return 0;
}

