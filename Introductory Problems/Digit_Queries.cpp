#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
using namespace std;
signed main()
{
    speed;
    int q;
    cin>>q;
    while(q--)
    {
        int k;cin>>k;
        if(k<=9)cout<<k<<endl;
        else
        {
            int cur=90;
            int len=2;
            int tot=9;
            while(tot+len*cur<k)
            {
                tot+=len*cur;
                cur*=10;
                len++;
            }
            k-=tot;
            int num=pow(10,len-1);
            // num--;
            int div=k/len;
            int rim=k%len;
            // assert(div>=1);
            num+=(div);
            k-=(div*len);
            if(k==0)cout<<(num-1)%10<<endl;
            else 
            {
                // num++;
                int cn=0;
                while(num)
                {
                    cn*=10;
                    cn+=(num%10);
                    num/=10;
                }
                while(k>1)
                {
                    cn/=10;
                    k--;
                }
                cout<<cn%10<<endl;
            }
        }
    }
    return 0;
}
