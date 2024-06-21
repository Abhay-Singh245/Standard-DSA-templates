# include<bits/stdc++.h>
# define ll long long
#define M 998244353
#define all(arr) arr.begin(),arr.end()
#define CODE_BY_ABHAY_SINGH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 using namespace std;
 void pv(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;}
 void parr(ll n,ll v[]){ for(ll i=0;i<n;i++) cout<<v[i]<<" ";cout<<endl;}
 void pyn(bool f) {cout<<(f?"YES":"NO")<<endl;} 
const int N=1e3;

   // ONCE A NOOB ALWAYS A NOOB

    struct sieve_t {
  sieve_t(int n, bool gen_primes = false, bool gen_sieve = false) {
    is_prime.assign(n + 1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
      for (int j = i * i; j <= n; j += i)
        is_prime[j] = false;
    }
    if (gen_primes) {
      for (int i = 2; i <= n; ++i) {
        if (is_prime[i])
          primes.push_back(i);
      }
    }
    if (gen_sieve) {
      sieve.assign(n + 1, -1);
      for (int i = 2; i <= n; ++i) {
        if (is_prime[i]) {
          sieve[i] = i;
          if ((ll)i * i <= n) {
            for (int j = i * i; j <= n; j += i) {
              if (sieve[j] == -1)
                sieve[j] = i;
            }
          }
        }
      }
    }
  }
  // requires gen_fact; works only upto sz;
  vector<int> fast_factorize(int k) {
    vector<int> res;
    while (k > 1) {
      ll p = sieve[k];
      res.push_back(p);
      k /= p;
    }
    return res;
  }
  // requies gen_primes; works upto sz*sz;
  vector<int> factorize(int k) {
    vector<int> res;
    for (int p : primes) {
      if (p * p > k)
        break;
      while (k % p == 0) {
        k /= p;
        res.push_back(p);
      }
    }
    if (k > 1)
      res.push_back(k);
    return res;
  }
  vector<bool> is_prime;
  vector<int> primes;
  vector<int> sieve;
};
 
sieve_t sv(1e6 + 20, true, true);
 
  
         void solve(){

            
         }




int main(){
   CODE_BY_ABHAY_SINGH
     ll T;
    //  T=1;
     cin>>T;
    while(T--){
    solve();  
    
   }  
 return 0;
}

  
