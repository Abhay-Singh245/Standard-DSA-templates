# include<bits/stdc++.h>
# define ll long long
# define lld long  double
#define M 1000000007
#define all(arr) arr.begin(),arr.end()
#define CODE_BY_ABHAY_SINGH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
void pv(vector<ll>v){ for(ll i=0;i<(ll)v.size();i++) cout<<v[i]<<" ";cout<<endl;}
void parr(ll n,ll v[]){ for(ll i=0;i<n;i++) cout<<v[i]<<" ";cout<<endl;}
void pyn(bool f) {cout<<(f?"YES":"NO")<<endl;} 
///const int N=1e5;
const ll mod=998244353;
ll N=500010;
ll MN=-1e10;


  // ONCE A NOOB ALWAYS A NOOB

  ll bin_exp(ll a, ll b, ll md)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a) % md;
        a = (a * a) % md;
        b = b >> 1;
    }
    return res;
}
ll modinverse(ll a, ll b) { return bin_exp(a, b - 2, b); }

ll mod_add(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a + b) % m) + m) % m;
}
ll mod_mul(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a * b) % m) + m) % m;
}
ll mod_sub(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (((a - b) % m) + m) % m;
}
ll mod_div(ll a, ll b, ll m)
{
    a = a % m;
    b = b % m;
    return (mod_mul(a, modinverse(b, m), m) + m) % m;
}

  struct Hashing
{
    string s;
    int n;
    int primes;
    vector<ll> hashPrimes = {1000000009, 100000007};
    const ll base = 31;
    vector<vector<ll>> H;
    vector<vector<ll>> PB;
    vector<vector<ll>> inversePB;
    Hashing(string a)
    {
        primes = 2;
        H.resize(primes);
        PB.resize(primes);
        inversePB.resize(primes);
        s = a;
        n = s.length();
        for (int i = 0; i < 2; i++)
        {
            PB[i].resize(n + 1);
            inversePB[i].resize(n + 1);
            PB[i][0] = 1;
            for (int j = 1; j <= n; j++)
            {
                PB[i][j] = (base * PB[i][j - 1]) % hashPrimes[i];
            }
            inversePB[i][n] = modinverse(PB[i][n], hashPrimes[i]);
            for (int j = n - 1; j >= 0; j--)
            {
                inversePB[i][j] = mod_mul(inversePB[i][j + 1], base, hashPrimes[i]);
            }
        }
        for (int i = 0; i < 2; i++)
        {
            H[i].resize(n);
            for (int j = 0; j < n; j++)
            {
                H[i][j] = ((s[j] - 'a' + 1LL) * PB[i][j]) % hashPrimes[i];
                H[i][j] = (H[i][j] + (j > 0 ? H[i][j - 1] : 0LL)) % hashPrimes[i];
            }
        }
    }
    vector<ll> substringHash(int l, int r)
    {
        vector<ll> hash(primes);
        for (int i = 0; i < primes; i++)
        {
            ll val1 = H[i][r];
            ll val2 = l > 0 ? H[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, hashPrimes[i]), inversePB[i][l], hashPrimes[i]);
        }
        return hash;
    }
};




     void solve(){ 
               
           
           
     } 

 
int main(){

   CODE_BY_ABHAY_SINGH 
       ll T;
       T=1;
    cin>>T;
    while(T--){
       solve();    
     }  
 return 0;
}