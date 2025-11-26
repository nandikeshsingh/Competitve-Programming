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
        int n,k;
        cin>>n>>k;
        string s,t;
        cin>>s>>t;
        int f=n-k-1;
        f=max(f,-1LL);
        int ss=k;
        ss=min(ss,n);
        bool ok=1;
        if(f<ss)
        {
            for(int i=f+1;i<ss;i++)
            {
                if(s[i]!=t[i])
                {
                    ok=0;
                    break;
                }
            }
        }
        if(!ok)cout<<"NO"<<endl;
        else
        {
            vector<int>a(26),b(26);
            for(int i=0;i<n;i++)
            {
                if(i>f && i<ss)continue;
                a[s[i]-'a']++;
            }
            for(int i=0;i<n;i++)
            {
                if(i>f && i<ss)continue;
                b[t[i]-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                if(a[i]!=b[i])
                {
                    ok=0;
                    break;
                }
            }
            if(ok)cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
    }
    return 0;
}


