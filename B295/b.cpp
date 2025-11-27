#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int r,c;
    cin>>r>>c;
    char arr[r][c];
    vector<pair<int,pair<int,int>>>vec;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cin>>arr[i][j];
            if(arr[i][j]!='.' && arr[i][j]!='#')vec.push_back({i,{j,arr[i][j]}});
        }
    }
    for(auto& u : vec)
    {
        int i=u.first;
        int j=u.second.first;
        int val=u.second.second-'0';
        for(int l=0;l<r;l++)
        {
            for(int m=0;m<c;m++)
            {
                int dis=abs(i-l)+abs(m-j);
                if(dis<=val)arr[l][m]='.';
            }
        }
    }

    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}


