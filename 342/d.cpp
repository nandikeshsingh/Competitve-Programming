
#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
int prime[200010];
int k[200010];
void Sieve()
{
    for (int i = 1; i < 200010; i++)
        k[i] = i;
    for (int i = 2; i < 200010; i++) {
        if (prime[i] == 0)
            for (int j = i; j < 200010; j += i) {
                prime[j] = 1;
                while (k[j] % (i * i) == 0)
                    k[j] /= (i * i);
            }
    }
}
int go(vector<int>&arr, int n)
{
    map<int, int>mp;
    int ret=0;
    for(int i=0;i<n;i++)
    {
        if(i==0)mp[k[arr[i]]]++;
        else 
        {
            if(arr[i]!=0)
            {
                ret+=(mp[k[arr[i]]]+mp[k[0]]);
                mp[k[arr[i]]]++;
            }
            else 
            {
                ret+=i;
                mp[k[0]]++;
            }
            
        }
    }
    return ret;
}
signed main()
{
    speed;
    Sieve();
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<go(a,n)<<endl;
    return 0;
}


