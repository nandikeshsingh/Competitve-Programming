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
        int n;
        cin>>n;
        vector<int>vec;
        int cur=1;
        int sum=0;
        while(sum+cur<=n)
        {
            sum+=cur;
            vec.push_back(cur);
            cur<<=1;
        }
        if(sum<n)vec.push_back(n-sum);
        sort(all(vec));
        cout<<vec.size()-1<<endl;
        for(int i=1;i<vec.size();i++)
        {
            cout<<vec[i]-vec[i-1]<<" ";
        }
        cout<<endl;
    }
    return 0;
}