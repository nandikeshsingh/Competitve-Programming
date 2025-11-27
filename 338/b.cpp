#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    string s;
    cin>>s;
    vector<int>cnt(26,0);
    for(auto& u : s)cnt[u-'a']++;
    int pos=-1,mx=-1;
    for(int i=0;i<26;i++)
    {
        if(cnt[i]>mx)
        {
            mx=cnt[i];
            pos=i;
        }
    }
    char ans='a'+pos;
    cout<<ans<<endl;
    return 0;
}


