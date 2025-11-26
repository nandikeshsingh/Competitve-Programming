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
        int n,k;
        cin>>n>>k;
        vector<int>vec(n);
        map<int,vector<int>>pos;
        for(int i=0;i<n;i++)
        {
            cin>>vec[i];
            pos[vec[i]].push_back(i+1);
        }
        while(k--)
        {
            int a,b;
            cin>>a>>b;
            if(pos[a].size()==0 || pos[b].size()==0)cout<<"NO"<<endl;
            else 
            {
                if(pos[a][0]<pos[b][pos[b].size()-1])
                cout<<"YES"<<endl;
                else cout<<"NO"<<endl;
            }
        }

    }
    return 0;
}

