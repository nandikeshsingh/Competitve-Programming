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
        vector<int>vec(n);
        for(int i=0;i<n;i++)vec[i]=i;
        int cur=n-1;
        while(cur>=0)
        {
            int s=sqrt(cur);
            int rim=-1;
            if(s*s==cur)rim=0;
            else rim=(s+1)*(s+1)-cur;
            int st=rim;
            int ed=cur;
            while(st<=ed)
            {
                swap(vec[st],vec[ed]);
                st++;ed--;
            }
            cur=rim-1;
        }
        for(auto& u : vec)cout<<u<<" ";
        cout<<endl;
    }
    return 0;
}