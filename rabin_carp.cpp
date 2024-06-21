
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

  // ONCE A NOOB ALWAYS A NOOB

    vector<ll> rabin_karp(string& s, string& t) {

    const ll p = 31; 
    const ll m = 1e9 + 9;
    ll S = s.size(), T = t.size();
    ll mx=max(S,T);

    vector<ll> p_pow(mx); 
    p_pow[0] = 1; 
    
    for (ll i = 1; i < mx; i++) 
        p_pow[i] = (p_pow[i-1] * p) % m;

    vector<ll> h(T + 1, 0);

    for (ll i = 0; i < T; i++){
        h[i+1] = (h[i] + (t[i] -'a' + 1) * p_pow[i]) % m; 
    }

    ll h_s = 0; 

    for (ll i = 0; i < S; i++) {
        h_s = (h_s + (s[i] - 'a' + 1) * p_pow[i]) % m; 
    }

    vector<ll> ret;
    for (ll i = 0; i + S - 1 < T; i++) {
       ll cur_h = (h[i+S] + m - h[i]) % m;
        if (cur_h == h_s * p_pow[i] % m)
            ret.push_back(i);
    }
    return ret;
}
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