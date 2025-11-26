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
        if(n%2==0)cout<<"NO"<<endl;
        else 
        {
            vector<pair<int,int>>ans;
            int mn=3;
            int mx=n+n-1+n+n;
            int rim=mx-mn+1;
            rim-=n;
            rim/=2;
            int st=mn+rim;
            int ed=st+n-1;
            int first=(n+1)/2;
            
            int up=st-1;
            int cur=st;
            for(int i=1;i<=first;i++)
            {
                ans.push_back({up,cur-up});
                cur++;
                up--;
            }
            int left=n-first;
            up=n+n;
            cur=st+first;
            for(int i=1;i<=left;i++)
            {
                ans.push_back({up,cur-up});
                up--;
                cur++;
            }
            cout<<"YES"<<endl;
            for(auto& u : ans)cout<<u.first<<" "<<u.second<<endl;
        }
    }
    return 0;
}


