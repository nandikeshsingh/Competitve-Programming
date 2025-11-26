#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int flip(int num)
{
   int numOfBits = (int)log2(num) + 1;
   return (((1 << numOfBits) - 1) ^ num);
}
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<string>s;
    for(int i=0;i<n;i++)
    {
        string str;
        cin>>str;
        s.push_back(str);
    }
    cout<<"done"<<endl;
    vector<set<int>>vec(25);
    for(int i=0;i<n;i++)
    {
        int cnt=0;
        vector<int>cur(26,0);
        for(auto& u : s[i])
        {
            if(cur[u-'a']==0)cnt++;
            cur[u-'a']++;
        }
        if(cnt>=25)continue;
        int mask=0;
        for(int i=0;i<26;i++)
        {
           if(cur[i]%2)mask|=(1<<i); 
        }
        if((int)s[i].length()%2)mask|=(1<<26);
        vec[cnt].insert(mask);
        cout<<"i="<<i<<"mask="<<mask<<endl;
    }
    cout<<"here"<<endl;
    int ans=0;
    for(int i=1;i<=24;i++)
    {
        for(auto& u : vec[i])
        {
            int val=flip(u);
            if(vec[25-i].count(val))ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}


