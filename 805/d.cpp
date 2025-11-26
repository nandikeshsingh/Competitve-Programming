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
        string s;
        cin>>s;
        int p;
        cin>>p;
        int tot=0;
        vector<int>vec(26,0);
        for(int i=0;i<s.length();i++)
        {
            tot+=(s[i]-'a'+1);
            vec[s[i]-'a']++;
        }
        if(tot>p)
        {
            for(int i=25;i>=0;i--)
            {
                if(vec[i]==0)continue;
                else 
                {
                    if(tot-(vec[i]*(i+1))>p)
                    {
                        tot-=vec[i]*(i+1);
                        vec[i]=0;

                    }
                    else 
                    {
                        int rim=tot-p;
                        int x=ceil((double)rim/double(i+1));
                        vec[i]-=x;
                        break;
                    }
                }
            }
        }
        string ans;
        for(int i=0;i<s.length();i++)
        {
            if(vec[s[i]-'a']>0)
            {
                vec[s[i]-'a']--;
                ans+=s[i];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

