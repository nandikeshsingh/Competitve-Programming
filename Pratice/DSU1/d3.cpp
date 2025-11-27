#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>vec(n);
        multiset<int>mst;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            mst.insert(vec[i]);
        }
        vector<int>ans;
        int cur_mex=-1;
        for(int i=0;i<=n;i++)
        {
            if(mst.find(i)==mst.end())
            {
                cur_mex=i;break;
            }
        }
        // cout<<"cur_mex="<<cur_mex<<endl;
        if(cur_mex!=n)
        {
            do{
                ans.push_back(cur_mex);
                mst.erase(mst.find(vec[cur_mex]));
                vec[cur_mex]=cur_mex;
                mst.insert(cur_mex);
                for(int i=0;i<=n;i++)
                {
                    if(mst.find(i)==mst.end())
                    {
                        cur_mex=i;break;
                    }
                }
            }while(cur_mex!=n);
        }
        vector<bool>vis(n,0);
        for(int i=0;i<n;i++)
        {
            if(vec[i]!=i && vis[i]==0)
            {
                int cur=i;
                do{
                    ans.push_back(cur);
                    vis[cur]=1;
                    cur=vec[cur];
                }while(cur!=i);
                ans.push_back(i);
            }
        }
        cout<<ans.size()<<endl;
        for(auto& u : ans)cout<<u+1<<" ";
        cout<<endl;
    }
    return 0;
}
