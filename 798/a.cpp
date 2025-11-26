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
        int n,m,k;
        cin>>n>>m>>k;
        string a,b;
        cin>>a>>b;
        string c;
        int cnt_a=0,cnt_b=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int i=0,j=0;

        while(i<a.size() && j<b.size())
        {
            if((a[i]<=b[j] && cnt_a<k) || cnt_b==k)
            {
                c+=a[i];
                i++;
                cnt_a++;
                cnt_b=0;
            }
            else if((a[i]>b[j] && cnt_b<k) || cnt_a==k)
            {
                c+=b[j];
                j++;
                cnt_a=0;
                cnt_b++;
            }
        }
        cout<<c<<endl;
    }
    return 0;
}

