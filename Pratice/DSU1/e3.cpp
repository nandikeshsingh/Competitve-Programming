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
        string s1,s2;
        cin>>s1>>s2;
        int a=1e18,b=-1,c=1e18,d=-1;
        for(int i=0;i<n;i++)
        {
            if(s1[i]=='*')
            {
                a=min(a,i);
                b=max(b,i);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(s2[i]=='*')
            {
                c=min(c,i);
                d=max(d,i);
            }
        }
        if(b==-1)cout<<d-c<<endl;
        else if(d==-1)cout<<b-a<<endl;
        else
        {
            int ans=0;
            for(int i=0;i<max(b,d);i++)
            {
                if(s1[i]=='.' && s2[i]=='.')continue;
                else if(s1[i]=='*' && s2[i]=='.')ans++,s1[i+1]='*',s1[i]='.';
                else if(s1[i]=='.' && s2[i]=='*')ans++,s2[i+1]='*',s2[i]='.';
                else 
                {
                    if(d>b)ans+=2,s2[i+1]='*',s2[i]='.',s1[i]='.';
                    else ans+=2,s1[i+1]='*',s2[i]='.',s1[i]='.';
                }
            }
            if(s1[max(b,d)]=='*' && s2[max(b,d)]=='*')ans++;
            cout<<ans<<endl;
        }
    }
    return 0;
}