#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
signed main()
{
    speed;
    int n,m;
    string s;
    cin>>n>>m>>s;
    int w_m=m,d_m=0,w_l=0,d_l=0;
    int cnt=0;
    for(auto& u : s)
    {
        if(u=='0')
        {
            w_m=m;
            d_m=0;
            w_l=cnt;
            d_l=0;
        }
        else if(u=='1')
        {
            if(w_m>0)
            {
                w_m--;
                d_l++;
            }else if(w_l>0)
            {
                w_l--;
                d_l++;
            }
            else 
            {
                cnt++;
                d_l++;
            }
        }else 
        {
            if(w_l>0)
            {
                w_l--;
                d_l++;
            }else 
            {
                cnt++;
                d_l++;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;
}


