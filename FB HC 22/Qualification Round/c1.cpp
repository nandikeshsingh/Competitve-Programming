#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    freopen("input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n;cin>>n;
        string s;cin>>s;
        vector<string>ans;
        string str;
        str=s;
        if(str[0]=='.')str[0]='-';
        else str[0]='.';
        for(int i=(int)s.length();i<200;i++)str+='.';
        for(int i=1;i<n;i++)
        {
            str[100+i]='-';
            ans.push_back(str);
            str[100+i]='.';
        }
        cout<<"Case #"<<c<<": "<<endl;
        for(auto& u : ans)cout<<u<<endl;
    }
    return 0;
}


