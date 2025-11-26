#include<bits/stdc++.h>
#define int long long
using namespace std;
bool cmp(pair<int,int>&p1,pair<int,int>&p2)
{
    if(p1.first!=p2.first)return p1.first<p2.first;
    else return p1.second<p2.second;
}
bool cmp1(pair<int,int>&p1,pair<int,int>&p2)
{
    if(p1.first!=p2.first)return p1.first<p2.first;
    else return p1.second>p2.second;
}
signed main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;
        char arr[n][m];
        // vector<pair<int,int>>x,y;
        pair<int,int>p1{-1,-1},p2{-1,-1},p3{-1,-1},p4{-1,-1};
        int a=1e9,b=-1e9,c=-1e9,d=1e9;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>arr[i][j];
                if(arr[i][j]=='B')
                {
                    if(i+j>c)
                    {
                        c=i+j;
                        p3={i+1,j+1};
                    }
                    if(i+j<a)
                    {
                        a=i+j;
                        p1={i+1,j+1};
                    }
                    if(i-j>b)
                    {
                        b=i-j;
                        p2={i+1,j+1};
                    }
                    if(i-j<d)
                    {
                        d=i-j;
                        p4={i+1,j+1};
                    }
                    // x.push_back({i+1,j+1});
                    // y.push_back({j+1,i+1});
                }
            }
        }
        // sort(x.begin(),x.end(),cmp);
        // sort(y.begin(),y.end(),cmp1);
        
        
        // int szx=x.size();
        // int szy=y.size();
        vector<pair<int,int>>v;
        v.push_back(p1);
        v.push_back(p2);
        v.push_back(p3);
        v.push_back(p4);
        // v.push_back({x[0].first,x[0].second});
        // v.push_back({x[szx-1].first,x[szx-1].second});
        // v.push_back({y[0].second,y[0].first});
        // v.push_back({y[szy-1].second,y[szy-1].first});
        
        // cout<<"Printing v"<<endl;
        // for(auto& u : v)cout<<u.first<<" "<<u.second<<endl;
        pair<int,int>ans;
        int mn=10000000;
        for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
        {
            int mx=0;
            for(auto& u : v)
            {
                if(mx<abs(u.first-i)+abs(u.second-j))
                {
                    mx=abs(u.first-i)+abs(u.second-j);
                }
            }
            if(mx<mn)
            {
                mn=mx;
                ans={i,j};
            }
        }
        // cout<<"Printing ans"<<endl;
        cout<<ans.first<<" "<<ans.second<<endl;
        // int x1=(x[0].first+x[szx-1].first+y[0].second)/3;
        // int y1=(x[0].second+x[szx-1].second+y[0].first)/3;
        // int x2=(x[szx-1].first+y[0].second+y[szy-1].second)/3;
        // int y2=(x[szx-1].second+y[0].first+y[szy-1].first)/3;
        // // cout<<"Printing"<<endl;
        // cout<<(x1+x2)/2<<" "<<(y1+y2)/2<<endl;
        // int xx,yy;
        // xx=(x[0]+x[szx-1])/2;
        // yy=(y[0]+y[szy-1])/2;
        // // if(szx%2)xx=x[szx/2];
        // // else xx=(x[szx/2]+x[szx/2-1])/2;
        // // if(szy%2)yy=y[szy/2];
        // // else yy=(y[szy/2]+y[szy/2-1])/2;
        // // cout<<"Printing ans"<<endl;
        // cout<<xx<<" "<<yy<<endl;
    }
    return 0;
}


