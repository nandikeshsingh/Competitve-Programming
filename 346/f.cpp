#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;cin>>n;
    string s,t;cin>>s>>t;
    vector<int>cnt(26,0);
    for(auto& u : s)
    {
        cnt[u-'a']++;
    }
    int len=s.length();
    vector<vector<int>>vec(26,vector<int>(len+1,0));
    // cout<<"done1"<<endl;
    for(int i=1;i<=len;i++)
    {
        // cout<<"i="<<i<<endl;
        for(int j=0;j<26;j++)
        {
            // cout<<"j="<<j<<endl;
            if(j==(s[i-1]-'a'))
            vec[(s[i-1]-'a')][i]=vec[s[i-1]-'a'][i-1]+1;
            else vec[j][i]=vec[j][i-1];
        }
    }
    cout<<"Printing vec"<<endl;
    for(int i=0;i<26;i++)
    {
        for(int j=0;j<=len;j++)
        {
            cout<<vec[i][j]<<" ";

        }
        cout<<endl;
    }
    // cout<<"done2"<<endl;
    int lo=0,hi=1e18;
    while(lo<hi)
    {
        int k=(lo+hi+1)>>1;
        int d=0;
        int last=0;
        cout<<"lo="<<lo<<" hi="<<hi<<" k="<<k<<" d="<<d<<endl;
        for(auto& u : t)
        {
            cout<<"last="<<last<<endl;
            int need=k;
            int bcnt=vec[u-'a'][len]-vec[u-'a'][last];
            cout<<"bcnt="<<bcnt<<endl;
            if(bcnt<need)
            {
                need-=bcnt;
                d++;
                int dd=(need/cnt[u-'a']);
                need-=dd*cnt[u-'a'];
                if(need==0)need+=dd*cnt[u-'a'];
                else d+=dd;
                int rim=need%cnt[u-'a'];
                last=lower_bound(all(vec[u-'a']),rim)-vec[u-'a'].begin();
            }
            else 
            {
                last=lower_bound(all(vec[u-'a']),vec[u-'a'][last]+need)-vec[u].begin();
            }
        }
        cout<<"lo="<<lo<<" hi="<<hi<<" k="<<k<<" d="<<d<<endl;
        if(d>n)hi=k-1;
        else lo=k;
    }
    cout<<lo<<endl;
    return 0;
}


