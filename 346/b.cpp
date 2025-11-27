#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int w,b;cin>>w>>b;
    string s="wbwbwwbwbwbw";
    int x=0,y=0;
    for(auto& u : s)
    {
        if(u=='w')x++;
        else y++;
    }
    s+=s;
    while(w>=x && b>=y)
    {
        w-=x;
        b-=y;
    }
    vector<int>a(s.length()+1,0);
    for(int i=1;i<s.length()+1;i++)
    {
        if(s[i-1]=='w')a[i]=a[i-1]+1;
        else a[i]=a[i-1];
    }
    bool ok=0;
    for(int i=1;i<s.length()+1;i++)
    {
        for(int j=1;j<=i;j++)
        {
            int cnt_w=a[i]-a[j-1];
            int cnt_b=i-j+1-cnt_w;
            if(cnt_w==w && cnt_b==b)ok=1;
        }
    }
    cout<<(ok?"Yes":"No")<<endl;
    return 0;
}


