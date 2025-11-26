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
        int n,q;
        cin>>n>>q;
        vector<int>vec(n+1);
        int mx=-1;
        int pos=-1;
        for(int i=1;i<=n;i++)
        {
            cin>>vec[i];
            if(mx<vec[i])
            {
                mx=vec[i];
                pos=i;
            }
        }
        vector<pair<int,int>>cvec;
        for(int i=1;i<=n;i++)
        {
            cvec.push_back({vec[i],i});
        }
        reverse(all(cvec));
        vector<int>win;
        for(int i=1;i<=pos-1;i++)
        {
            pair<int,int>one=cvec.back();
            cvec.pop_back();
            pair<int,int>two=cvec.back();
            cvec.pop_back();
            if(one.first>two.first)cvec.push_back(one),win.push_back(one.second);
            else cvec.push_back(two),win.push_back(two.second);
        }
        vector<int>gp[n+1];
        for(int i=0;i<(int)win.size();i++)
        gp[win[i]].push_back(i);
        while(q--)
        {
            int i,k;
            cin>>i>>k;
            if(i==pos)
            {
                if(k>=pos-1)
                {
                    if(pos-1>=1)
                    cout<<k-pos+2<<endl;
                    else cout<<k-pos+1<<endl;
                }
                else if(k<pos-1)
                {
                    cout<<0<<endl;
                }
            }
            else 
            {
                if(k>pos-1)k=pos-1;
                //find the count of i in 0 to k-1 int win;
                // int cnt=0;
                // if((int)gp[i].size()==0)
                // {
                //     cout<<0<<endl;
                // }
                // else 
                {
                    int cnt=upper_bound(gp[i].begin(),gp[i].end(),k-1)-gp[i].begin();
                    cout<<cnt<<endl;
                }
                // for(int j=0;j<k;j++)cnt+=(win[j]==i);
                // cout<<cnt<<endl; 
            }
        }
    }
    return 0;
}


