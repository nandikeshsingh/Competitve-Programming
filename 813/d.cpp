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
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            vec.push_back({a[i],i});
        }
        if(k==n)
        {
            // cout<<"Printin ans"<<endl;
            cout<<1000000000<<endl;
            continue;
        }
        int mmx=*max_element(all(a));
        sort(all(vec));
        int last=-1;
        for(int i=0;i<k;i++)
        {
            if(i==k-1)last=vec[i].first;
            vec[i].first=1000000000;
        }
        int mn=vec[k].first;
        for(int i=0;i<n;i++)
        {
            a[vec[i].second]=vec[i].first;
        }
        int amx=*max_element(all(a));
        // if(mn==1000000000)
        // {
        //     cout<<1000000000<<endl;
        //     continue;
        // }
        // cout<<"Printing a"<<endl;
        // for(auto& u : a)cout<<u<<" ";
        // cout<<endl;
        int mx=-1;
        for(int i=1;i<n;i++)
        {
            mx=max(mx,min(a[i],a[i-1]));
        }
        // cout<<"Printin ans"<<endl;
        assert(mx!=-1);
        if(k==1)
        cout<<max(min(mx,2*mn),min(mmx,2*last))<<endl;
        else cout<<min(max(min(mx,2*mn),2*last),1000000000LL)<<endl;
    }
    return 0;
}
