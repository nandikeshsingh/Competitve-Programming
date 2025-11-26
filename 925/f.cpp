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
        vector<vector<int>>vec;
        for(int i=0;i<k;i++)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                int x;cin>>x;
                temp.push_back(x);
            }
                vec.push_back(temp);
        }
 
        int p=vec[0][0];
        for(auto& u : vec)
        {
            reverse(all(u));
            u.pop_back();
            reverse(all(u));
        }
   
        vector<int>pos(n+1,0);
        int cur=1;
        for(int j=0;j<sz(vec[0]);j++)
        {
            pos[vec[0][j]]=cur;
            cur+=2;
        }
        int lo=0,hi=n+n-2;
        cerr<<"lo="<<lo<<" hi="<<hi<<endl;
        bool ok=1;
        for(int i=1;i<k;i++)
        {
            for(int j=1;j<sz(vec[i]);j++)
            {
                // cout<<"i="<<i<<" j="<<j<<endl;
                if(vec[i][j]!=p && vec[i][j-1]!=p)
                {
                    if(pos[vec[i][j]]<pos[vec[i][j-1]])
                    {
                        ok=0;
                        break;
                    }
                }
                else if(vec[i][j]==p)
                {
                        lo=max(lo,pos[vec[i][j-1]]+1);
                    
                }
                else if(vec[i][j-1]==p)
                {
                     hi=min(hi,pos[vec[i][j]]-1);
                }
                if(hi<lo)
                {
                    ok=0;
                    break;
                }
            }
            if(!ok)break;
        }
        if(!ok)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}


