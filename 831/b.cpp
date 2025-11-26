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
        int tot=0;
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            int a,b;
            cin>>a>>b;
            tot+=2*(a+b);
            if(a<b)swap(a,b);
            vec.push_back({a,b});
        }
        sort(all(vec));
        int lost=0;
        for(int i=0;i<n-1;i++)
        lost+=2*vec[i].first;
        cout<<tot-lost<<endl;
    }
    return 0;
}


