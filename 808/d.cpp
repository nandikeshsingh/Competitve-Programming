#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
        int cur=n;
        while(vec.size()>1)
        {
            vector<int>b;
            // int cur=0;
            // while(vec[cur]==0)cur++;
            // if(cur==0)cur++;
            for(int i=1;i<vec.size();i++)
            {
                if(vec[i]!=vec[i-1])
                b.push_back(vec[i]-vec[i-1]);
            }
            cur--;
            if(b.size()!=cur)
            {
                // reverse(b.begin(),b.end());
                b.push_back(0);
                // reverse(b.begin(),b.end());
            }
            sort(b.begin(),b.end()); 
            vec.clear();
            vec=b;
            b.clear();
        }
        cout<<vec[0]<<endl;
    }
    return 0;
}