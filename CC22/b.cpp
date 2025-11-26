#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
           int n;
           cin>>n;
           vector<int>vec(n);
           map<int,vector<int>>mp;
           for(int i=0;i<n;i++)cin>>vec[i],mp[vec[i]].push_back(i+1);
           bool ok=1;
           for(auto & u : mp)
           {
               if(u.second.size()==1)ok=0;
           }
           if(!ok)cout<<-1<<endl;
           else 
           {
               for(auto& u : mp)
               {
                   int sz=u.second.size();
                   int st=u.second[0];
                   for(int i=1;i<sz;i++)
                   {
                       u.second[i-1]=u.second[i];
                   }
                   u.second[sz-1]=st;
                   u.second.push_back(0);
               }
            vector<int>ans;
            for(int i=0;i<n;i++)
            {
                int sz=mp[vec[i]].size();
                int counter=mp[vec[i]][sz-1];
                ans.push_back(mp[vec[i]][counter]);
                mp[vec[i]][sz-1]++;
            }
            for(auto & u : ans)cout<<u<<" ";
            cout<<endl;
           }     
    }
    return 0;
}


