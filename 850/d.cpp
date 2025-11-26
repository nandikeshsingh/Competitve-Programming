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
        int m;
        cin>>m;
        vector<string>vec;
        for(int i=0;i<m;i++)
        {
            string s;
            cin>>s;
            vec.push_back(s);
        }
        vector<vector<int>>has(3,vector<int>(m+1,0));
        for(int i=0;i<m;i++)
        {
            for(auto& u : vec[i])
            {
                if(u=='w')has[0][i+1]++;
                else if(u=='i')has[1][i+1]++;
                else has[2][i+1]++;
            }
        }
        map<int,vector<pair<int,int>>>ex;
        map<int,multiset<int>>need;
        for(int i=0;i<3;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(has[i][j]>1)ex[i].push_back({j,has[i][j]-1});
                else if(has[i][j]==0)need[i].insert(j);
            }
        }
        vector<pair<pair<int,char>,pair<int,char>>>ans;
        map<int,multiset<int>>extra;
        for(auto& u : ex)
        {
            for(auto& p : u.second)
            {
                for(int i=0;i<p.second;i++)
                extra[u.first].insert(p.first);
            }
        }   
  
        while(sz(extra[0]))
        {
            int rm=*(extra[0].begin());
            extra[0].erase(extra[0].begin());
            int nd=*(need[0].begin());
            need[0].erase((need[0].begin()));
            if(extra[1].count(nd))
            {
                ans.push_back({{rm,'w'},{nd,'i'}});
                extra[1].erase(extra[1].find(nd));
                if(need[1].count(rm)==0)extra[1].insert(rm);
                else need[1].erase(need[1].find(rm));
            }
            else 
            {
                ans.push_back({{rm,'w'},{nd,'n'}});
                extra[2].erase(extra[2].find(nd));
                if(need[2].count(rm)==0)extra[2].insert(rm);
                else need[2].erase(need[2].find(rm));                
            }

        }
        while(sz(extra[1]))
        {
            int rm=*(extra[1].begin());
            extra[1].erase((extra[1].begin()));
            int nd=*(need[1].begin());
            need[1].erase((need[1].begin()));      
            if(extra[2].count(nd))
            {
                ans.push_back({{rm,'i'},{nd,'n'}});
                extra[2].erase(extra[2].find(nd));
                if(need[2].count(rm)==0)extra[2].insert(rm);
                else need[2].erase(need[2].find(rm));               
            } 
  
        }    
        cout<<sz(ans)<<endl;
        for(auto& u : ans)
        {
            cout<<u.first.first<<" "<<u.first.second<<" "<<u.second.first<<" "<<u.second.second<<endl;
        }
    }
    return 0;
}


