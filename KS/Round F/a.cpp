#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
// #define int long long
signed main()
{
    int t;
    cin>>t;
    for(int c=1;c<=t;c++)
    {
        int n;
        cin>>n;
        vector<pair<int,int>>chr;
        vector<pair<string,int>>ada;
        for(int i=0;i<n;i++)
        {
            string c;
            cin>>c;
            int d,id;
            cin>>d>>id;
            ada.push_back({c,id});
            chr.push_back({d,id});
        }
        sort(all(ada),[&](pair<string,int>p1,pair<string,int>p2)
        {   
            if(p1.first!=p2.first)
            return p1.first<p2.first;
            else return p1.second<p2.second;
        });
        sort(all(chr),[&](pair<int,int>p1,pair<int,int>p2){
              if(p1.first!=p2.first)
            return p1.first<p2.first;
            else return p1.second<p2.second;          
        });
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(ada[i].second==chr[i].second)ans++;
        }
          cout<<"Case #"<<c<<": "<<ans<<endl;
    }
  
    return 0;
}