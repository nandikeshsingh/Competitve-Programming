#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
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
        int a=0,b=0;
        int cur_a=1;
        int cur_b=5;
        int a_w=0,a_b=0;
        int b_w=0,b_b=0;
        bool t=1;
        while(1)
        {
            if(t)
            {
                if(a+b+cur_a<=n)
                {
                    a+=cur_a;
                    a_w+=(cur_a+1)/2;
                    a_b+=(cur_a/2);
                    cur_a+=8;
                    t=0;
                }
                else break;
            }
            else 
            {
                if(a+b+cur_b<=n)
                {
                    b+=cur_b;
                    b_w+=(cur_b/2);
                    b_b+=(cur_b+1)/2;
                    cur_b+=8;
                    t=1;
                }
                else break;

            }
        }
        int rim=n-a-b;
        
        if(rim)
        {
            if(t)
            {
                a+=rim;
                    a_w+=(rim+1)/2;
                    a_b+=(rim/2);
            }
            else 
            {
                b+=rim;
                    b_w+=(rim/2);
                    b_b+=(rim+1)/2;
            }
        }
        cout<<a_w<<" "<<a_b<<" "<<b_w<<" "<<b_b<<endl;
    }
    return 0;
}


