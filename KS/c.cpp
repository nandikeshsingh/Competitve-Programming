#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int>& p1,pair<int,int>& p2)
{
    if(p1.first==p2.first)return p1.second>p2.second;
    else return p1.first>p2.first;
}
int main()
{
    int tt;
    cin>>tt;
    for(int t=1;t<=tt;t++)
    {
        int n,l;//handle for n=1 seperately;
        cin>>n>>l;
        vector<pair<int,pair<int,int>>>vec;
        for(int i=0;i<n;i++)
        {
            int p,dir;
            cin>>p>>dir;
            vec.push_back({p,{dir,i+1}});
        }
        if(n==1)
        {
            cout<<"Case #"<<t<<": ";
            cout<<1<<endl;
            continue;
        }
        sort(vec.begin(),vec.end());
        vector<int>ant_time(n+1);
        vector<int>pre(n+1,0);
        for(int i=0;i<n;i++)
        {
            if(vec[i].second.first==1)pre[i+1]=pre[i]+1;
            else pre[i+1]=pre[i];
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                int right_one_cnt=pre[n]-pre[i+1];
                int right_zero_cnt=n-i-1-right_one_cnt;
                if(vec[i].second.first==0)ant_time[vec[i].second.second]=vec[i].first;
                else 
                {
                    if(right_zero_cnt>=1)ant_time[vec[i].second.second]=vec[i].first+vec[i+1].first-vec[i].first;
                    else ant_time[vec[i].second.second]=n-vec[i].first;
                }
            }
            else if(i==n-1)
            {
                int left_one_cnt=pre[n-1]-pre[0];
                if(vec[i].second.first==1)ant_time[vec[i].second.second]=n-vec[i].first;
                else 
                {
                    if(left_one_cnt>=1)ant_time[vec[i].second.second]=n-vec[i].first+vec[i].first-vec[i-1].first;
                    else ant_time[vec[i].second.second]=vec[i].first;
                }
            }
            else 
            {
                    int left_one_cnt=pre[i]-pre[0];
                    int right_one_cnt=pre[n]-pre[i+1];
                    int right_zero_cnt=n-i-1-right_one_cnt;
                if(vec[i].second.first==0)//0 is left
                {
                    if(left_one_cnt==right_zero_cnt)ant_time[vec[i].second.second]=vec[i].first+left_one_cnt*(vec[i].first-vec[i-1].first)+right_zero_cnt*(vec[i+1].first-vec[i].first);
                    else if(left_one_cnt>right_zero_cnt)ant_time[vec[i].second.second]=n-vec[i].first+(right_zero_cnt+1)*(vec[i].first-vec[i-1].first)+right_zero_cnt*(vec[i+1].first-vec[i].first);
                    else ant_time[vec[i].second.second]=vec[i].first+left_one_cnt*(vec[i].first-vec[i-1].first)+left_one_cnt*(vec[i+1].first-vec[i].first);
                }
                else 
                {
                    if(left_one_cnt==right_zero_cnt)ant_time[vec[i].second.second]=n-vec[i].first+left_one_cnt*(vec[i].first-vec[i-1].first)+right_zero_cnt*(vec[i+1].first-vec[i].first);   
                    else if(left_one_cnt>right_zero_cnt)ant_time[vec[i].second.second]=n-vec[i].first+(right_zero_cnt)*(vec[i].first-vec[i-1].first)+right_zero_cnt*(vec[i+1].first-vec[i].first);      
                    else ant_time[vec[i].second.second]=vec[i].first+left_one_cnt*(vec[i].first-vec[i-1].first)+(left_one_cnt+1)*(vec[i+1].first-vec[i].first);           
                }
            }
        }
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++)
        {
            v.push_back({ant_time[i+1],i+1});
        }
        sort(v.begin(),v.end(),cmp);

        cout<<"Case #"<<t<<": ";
        for(int i=0;i<n;i++)cout<<v[i].second<<" ";
        cout<<endl;
    }
    return 0;
}
