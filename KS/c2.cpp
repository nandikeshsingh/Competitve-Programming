#include<bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int,int>&p1, pair<int,int>&p2)
{
    if(p1.first==p2.first)return p1.second<p2.second;
    else return p1.first<p2.first;
}
signed main()
{
    int tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
        int n,L;
        cin>>n>>L;
        // cout<<"n= "<<n<<" L="<<L<<endl;
        vector<pair<int,pair<int,int>>>vec;
        for(int i=0;i<n;i++)
        {
            int p,dir;
            cin>>p>>dir;
            vec.push_back({p,{dir,i+1}});
        }
        sort(vec.begin(),vec.end());
        //                 cout<<"Printing vec : "<<endl;
        // for(auto& u : vec)cout<<u.first<<" "<<u.second.first<<" "<<u.second.second<<endl;
        vector<pair<int,int> >time;
        for(int i=0;i<n;i++)
        {
            if(vec[i].second.first==0)
            {
                time.push_back({vec[i].first,0});
            }
            else time.push_back({L-vec[i].first,1});
        }
        sort(time.begin(),time.end());
        //         cout<<"Printing time : "<<endl;
        // for(auto& u :time)cout<<u.first<<" "<<u.second<<endl;

        int l=0,r=n-1;
        int cnt=0;
        vector<pair<int,int>>ans;
        while(l<=r && cnt<n)
        {
            if(time[cnt].second==0)
            {
                ans.push_back({time[cnt++].first,vec[l++].second.second});
            }
            else 
            {
                ans.push_back({time[cnt++].first,vec[r--].second.second});
            }
        }

    //    cout<<"Printing ans : "<<endl;
    //    for(auto& u :ans)cout<<u.first<<" "<<u.second<<endl;
        sort(ans.begin(),ans.end(),cmp);
        
        cout<<"Case #"<<t<<": ";
        for(auto &u : ans)cout<<u.second<<" ";
        cout<<endl;
    }
    return 0;
}