#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
        vector<int>b;
        multiset<int>a;
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            while(x%2==0)x/=2;
            a.insert(x);
        }
        for(int i=0;i<n;i++)
        {
            int x;cin>>x;
            while(x%2==0)x/=2;
            b.push_back(x);
        }
        // sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        // cout<<"Prinitng a"<<endl;
        // for(auto & u : a)cout<<u<<" ";
        // cout<<endl;
        // cout<<"Printing b"<<endl;
        // for(auto& u : b)cout<<u<<" ";
        // cout<<endl;
        bool ok=1;
        for(int i=0;i<n;i++)
        {
            if(a.find(b[i])!=a.end())
            {
                auto itr = a.find(b[i]);
                if(itr!=a.end()){
                    a.erase(itr);
                }
                continue;
            }
            else 
            {
                int cur=b[i];
                while(cur>0)
                {
                    cur/=2;
                    if(a.find(cur)!=a.end())
                    {
                        auto itr = a.find(cur);
                        if(itr!=a.end()){
                            a.erase(itr);
                        }
                        break;
                    }
                }
                if(cur==0)
                {
                    ok=0;
                    break;
                }
            }
        }
        //       cout<<"Prinitng a after"<<endl;
        // for(auto & u : a)cout<<u<<" ";
        // cout<<endl;
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
      
    }
    return 0;
}
