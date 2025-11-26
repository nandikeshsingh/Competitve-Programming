#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int p;
    cin>>p;
    if(p==0)
    {
        cout<<0<<" "<<0<<endl;
        return 0;
    }
    vector<int>w(640);
    for(int i=1;i<=640;i++)
    {
        w[i]=(i*(i-1))/2;
    }
    int val=0;
    int ans=0;
    vector<int>vec;
    // for(int i=1;i<=p;i++)
    int cnt=0;
    {
        int cur=p;
        for(int j=640;j>=1;j--)
        {
            if(w[j]>cur)continue;
            else 
            {
                int d=cur/w[j];
                cur-=(d*w[j]);
                ans+=(d*j);
                cnt+=d;
                for(int i=0;i<d;i++)vec.push_back(j);
            }
            if(cur==0)break;
        }
    }
    sort(all(vec));
    int sum=0;
    for(int i=0;i<sz(vec);i++)
    {
        val+=vec[i]*sum;
        sum+=vec[i];
    }
    if(cnt==1)val=0;
    cout<<ans<<" "<<val<<endl;
    return 0;
}