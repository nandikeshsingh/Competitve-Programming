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
        int n,h;
        cin>>n>>h;
        vector<int>a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        sort(all(a));
        int ans=0;
        vector<vector<int>>vec;
        vector<int>temp={2,2,3};
        vec.push_back(temp);
        temp={2,3,2};
        vec.push_back(temp);
        temp={3,2,2};
        vec.push_back(temp);
        for(auto& u : vec)
        {
            int j=0;
            int cur=0;
            int ch=h;
            for(int i=0;i<n;)
            {
                if(a[i]<ch)
                {
                    ch+=(a[i]/2);
                    cur++;
                    i++;
                }
                else if(j>=3)break;
                else 
                {
                    ch*=u[j];
                    j++;
                }
            }
            ans=max(ans,cur);
        }
        cout<<ans<<endl;
    }
    return 0;
}


