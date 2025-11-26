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
        vector<int>od,ev;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            if(vec[i]%2)od.push_back(vec[i]);
            else ev.push_back(vec[i]);
        }
        int evs=ev.size();
        int ods=od.size();
        if(ods>=1)cout<<evs<<endl;
        else 
        {
            int ans=0;
            // int rim=evs-ods;
            for(auto& u : ev)
            {
                u=((u)&(-u));
                u=log2(u);
            }
            // cout<<"Printing ev"<<endl;
            // for(auto & u : ev)cout<<u<<" ";
            // cout<<endl;
            sort(ev.begin(),ev.end());
            ans+=(ev[0]+evs-1);
            cout<<ans<<endl;
        } 
    }
    return 0;
}


