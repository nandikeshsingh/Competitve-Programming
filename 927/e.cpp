#include<bits/stdc++.h>
#define int long long
#define speed  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(v) v.begin(),v.end()
#define sz(v) (int)v.size()
using namespace std;
string findSum(string str1, string str2)
{
    if (str1.length() > str2.length())
        swap(str1, str2);
    string str = "";
    int n1 = str1.length(), n2 = str2.length();
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());
 
    int carry = 0;
    for (int i=0; i<n1; i++)
    {
        int sum = ((str1[i]-'0')+(str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    for (int i=n1; i<n2; i++)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }
    if (carry)
        str.push_back(carry+'0');
    reverse(str.begin(), str.end());
    return str;
}
string multiply(string num1, string num2) {
    vector<int> vec1(num1.size());
    for (int i = 0; i < num1.size(); i++) {
        vec1[i] = num1[num1.size() - i - 1] - '0';
    }
    vector<int> vec2(num2.size());
    for (int i = 0; i < num2.size(); i++) {
        vec2[i] = num2[num2.size() - i - 1] - '0';
    }
    vector<int> result(vec1.size() + vec2.size());
    for (int i = 0; i < vec2.size(); i++) {
        int carry = 0;
        for (int j = 0; j < vec1.size(); j++) {
            int product = vec1[j] * vec2[i] + carry + result[i + j];
            carry = product / 10;
            result[i + j] = product % 10;
        }
        result[i + vec1.size()] = carry;
    }
    while (result.size() > 1 && result.back() == 0) {
        result.pop_back();
    }
    string str(result.size(), '0');
    for (int i = 0; i < result.size(); i++) {
        str[result.size() - i - 1] = result[i] + '0';
    }
    return str;
}
struct BigInteger {
    string str;
 
    // Constructor to initialize
    // BigInteger with a string
    BigInteger(string s) { str = s; }
 
    // Overload + operator to add
    // two BigInteger objects
    BigInteger operator+(const BigInteger& b)
    {
        string a = str;
        string c = b.str;
        int alen = a.length(), clen = c.length();
        int n = max(alen, clen);
        if (alen > clen)
            c.insert(0, alen - clen, '0');
        else if (alen < clen)
            a.insert(0, clen - alen, '0');
        string res(n + 1, '0');
        int carry = 0;
        for (int i = n - 1; i >= 0; i--) {
            int digit = (a[i] - '0') + (c[i] - '0') + carry;
            carry = digit / 10;
            res[i + 1] = digit % 10 + '0';
        }
        if (carry == 1) {
            res[0] = '1';
            return BigInteger(res);
        }
        else {
            return BigInteger(res.substr(1));
        }
    }
 
    // Overload << operator to output
    // BigInteger object
    friend ostream& operator<<(ostream& out,
                               const BigInteger& b)
    {
        out << b.str;
        return out;
    }
};
signed main()
{
    speed;
    int t;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        string s;cin>>s;
        BigInteger ans("0");
        BigInteger cur("1");
        reverse(all(s));
        for(int i=0;i<n;i++)
        {
            string ss;
            ss+=s[i];
            BigInteger b=multiply(cur,ss);
            ans=ans+b;
            cur.append("0");
            cur=findSum(cur,"1");
        }
        cout<<ans<<endl;
    }
    return 0;
}


