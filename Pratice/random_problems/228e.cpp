#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n;
    cin>>n;
    vector<int>vec;
    int l=0,r=0;
    for(int i=0;i<n;i++)
    {
        int s;cin>>s;
        vector<int>temp;
        for(int i=0;i<s;i++)
        {
            int x;cin>>x;temp.push_back(x);
        }
        if(s&1)
        {
            vec.push_back(temp[s/2]);
            for(int i=0;i<s;i++)
            {
                if(i<s/2)
                l+=temp[i];
                else if(i>s/2)r+=temp[i];
            }
        }
        else 
        {
            for(int i=0;i<s;i++)
            {
                if(i<s/2)
                l+=temp[i];
                else if(i>=s/2)r+=temp[i];
            }
        }
    } 
    sort(all(vec));
    reverse(all(vec));
    for(int i=0;i<sz(vec);i++)
    {
        if(i&1)r+=vec[i];
        else l+=vec[i];
    }  
    cout<<l<<" "<<r<<endl;
    return 0;
}


