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
        int n;
        cin>>n;
        vector<int>vec(n),pos,neg;
        int mx=-1e9-10;
        int mn=1e9+10;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            if(vec[i]>=0)pos.push_back(vec[i]);
            else neg.push_back(vec[i]);
            mx=max(vec[i],mx);
            mn=min(vec[i],mn);
        }
        int val=mx-mn;
        vector<int>ans,pre; 
        pre.push_back(0);
        sort(all(pos));
        sort(all(neg));
        reverse(all(neg));
        bool ok=1;
        int low=0;
        while(sz(pos))
        {
            if(pre.back()+pos.back()-low<val)
            {
                ans.push_back(pos.back());
                pos.pop_back();
            }
            else 
            {
                if(sz(neg)==0)
                {
                    ok=0;
                    break;
                }
                else 
                {
                    ans.push_back(neg.back());
                    neg.pop_back();
                }
            }
            pre.push_back(pre.back()+ans.back());
            low=min(low,pre.back());
        }
        while(sz(neg))
        {
            ans.push_back(neg.back());
            neg.pop_back();
        }
        if(!ok)cout<<"No"<<endl;
        else 
        {
            cout<<"Yes"<<endl;
            for(auto& u : ans)cout<<u<<" ";
            cout<<endl;
        }
    }
    return 0;
}


