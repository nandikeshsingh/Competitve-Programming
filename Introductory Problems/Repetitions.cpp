#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    string s;
    cin>>s;
    int ans=1;
    int cur=1;
    for(int i=1;i<s.length();i++)
    {
        if(s[i]==s[i-1])cur++;
        else cur=1;
        ans=max(ans,cur);
    }
    cout<<ans<<endl;
    return 0;
}

