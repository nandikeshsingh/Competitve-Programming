#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;

    return 0;
}
#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    vector<int>a(9),b(8);
    int x=0,y=0;
    for(int i=0;i<9;i++)
    {
        cin>>a[i];
        x+=a[i];
    }
    for(int i=0;i<8;i++)
    {
        cin>>b[i];
        y+=b[i];
    }
    int need=x-y+1;
    if(need<0)need=0;
    cout<<need<<endl;
    return 0;
}




