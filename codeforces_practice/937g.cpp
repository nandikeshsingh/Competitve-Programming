#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
const int mod=1e9+7;
struct Hashs 
{
	vector<int> hashs;
	vector<int> pows;
	int P;
	int MOD;

	Hashs() {}

	Hashs(string &s, int P, int MOD) : P(P), MOD(MOD) 
	{
		int n = s.size();
		pows.resize(n + 1, 0);
		hashs.resize(n + 1, 0);
		pows[0] = 1;
		for(int i = n - 1; i >= 0; i--) 
		{
			hashs[i] = (1LL * hashs[i + 1] * P + s[i] - 'a' + 1) % MOD;
			pows[n - i] = (1LL * pows[n - i - 1] * P) % MOD;
		}
		pows[n] = (1LL * pows[n - 1] * P) % MOD;
	}

	int get_hash(int l, int r) 
	{
		int ans = hashs[l] + MOD - (1LL * hashs[r + 1] * pows[r - l + 1]) % MOD;
		ans %= MOD;
		return ans;
	}
};
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>hg,hw;
        for(int i=0;i<n;i++)
        {
            string x,y;
            cin>>x>>y;
            Hashs h(x,31,mod);
            int hx=h.get_hash(0,(int)x.length()-1);
            Hashs hh(y,31,mod);
            int hy=hh.get_hash(0,(int)y.length()-1);
            hg.push_back(hx);
            hw.push_back(hy);
        }
        int mx=1;
        for(int mask=1;mask<(1<<n);mask++)
        {
           set<int>stg,stw;
           vector<pair<int,int>>vec;
           for(int bit=0;bit<n;bit++)
           {
                if(((1<<bit)&mask)>0)
                {
                    vec.push_back({hg[bit],hw[bit]});
                }
           } 
           vector<bool>has(sz(vec),0);
           has[0]=1;
           stg.insert(vec[0].first);
           stw.insert(vec[0].second);
           bool ok=1;
           while(1)
           {
                bool match=0;
                for(int i=0;i<sz(vec);i++)
                {
                    if(has[i])continue;
                    if(stg.count(vec[i].first) || stw.count(vec[i].second))
                    {
                        stg.insert(vec[i].first);
                        stw.insert(vec[i].second);
                        has[i]=1;
                        match=1;
                    }
                }
                int cnt=0;
                for(int i=0;i<sz(vec);i++)if(has[i])cnt++;
                if(!match && cnt<sz(vec))
                {
                    ok=0;
                    break;
                }
                else if(!match && cnt==sz(vec))break;
           }
           if(ok)mx=max(mx,sz(vec));
        }
        cout<<n-mx<<endl;
    }
    return 0;
}



