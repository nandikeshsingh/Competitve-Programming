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
        for(int i=0;i<n;i++)
        cin>>vec[i];
        while(vec.size()>1)
        {
            vector<int>b;
            // int cur=0;
            // while(vec[cur]==0)cur++;
            // if(cur==0)cur++;
            int cnt=0;
            for(int i=1;i<(int)vec.size();i++)
            {
                if(vec[i]!=vec[i-1])
                b.push_back(vec[i]-vec[i-1]);
                else cnt++;
            }
            if(cnt)
            {
                b.push_back(0);
            }
            sort(all(b));
            vec.clear();
            vec=b;
            b.clear();
        }
        cout<<vec[0]<<endl;
    }
    return 0;
}

