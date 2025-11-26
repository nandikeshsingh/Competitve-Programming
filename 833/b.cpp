#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int get(string s)
{
    int ret=0;
    int n=(int)s.length();
    int mx=0;
    for(int i=0;i<n;i++)
    {
        map<char,int>mp;
        for(int j=i;j<n;j++)
        {
            mp[s[j]]++;
            mx=max(mx,mp[s[j]]);
            if(sz(mp)>=mx)ret++;
        }
        mx=0;
    }
    return ret;
}
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
        int ans=0;
        if(n<=100)
        {
            ans+=get(s);

        }
        else 
        {
            string str=s.substr(0,100);
            ans+=get(str);
            int prev=ans;
            int l=0,r=99;
            while(r+1<n)
            {
                // int cur=prev;
                map<char,int>mp;
                // int mx=0;
                // int last=0;
                // for(int j=0;j<100;j++)
                // {
                //     mp[str[j]]++;
                //     mx=max(mx,mp[str[j]]);
                //     if(sz(mp)>=mx)last++;
                // }
                // ans-=last;
                reverse(all(str));
                str.pop_back();
                reverse(all(str));
                r++;l++;
                str+=s[r];
                int mx=0;
                int val=0;
                mp.clear();
                for(int j=99;j>=0;j--)
                {
                    mp[str[j]]++;
                    mx=max(mx,mp[str[j]]);
                    if(sz(mp)>=mx)val++;
                }
                ans+=val;
                // ans+=cur;
                // prev=cur;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}


