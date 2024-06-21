# include<bits/stdc++.h>
# define ll long long
#define M 1000000007
#define all(arr) arr.begin(),arr.end()
#define CODE_BY_ABHAY_SINGH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
const ll N= 1e6+1;
void pv(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;}
void pyn(bool f) {cout<<(f?"YES":"NO")<<endl;} 
/*-----------------------------------------------------------------------------------------------------------------*/
   
     // ONCE A NOOB ALWAYS A NOOB 
          map<ll,set<ll>>prime;
  int spf[N];
     //-->
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<N; i++)
        spf[i] = i;
    for (int i=4; i<N; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<N; i++)
    {

        if (spf[i] == i)
        {
            for (int j=i*i; j<N; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
 // -->
    set<ll> getFactorization(ll x)
{
      set<ll> ret;
    while (x != 1)
    {  
      ll k=spf[x];
        ret.insert(k);
        x = x / spf[x];
    }
    return ret;
}      
// --> 
    void get(){
       for(ll i=2;i<N;i++){
       set<ll>p = getFactorization(i);
        prime[i]=p;
       }
       }
           bool is_prime[N];
  // -->
    void sieve_of_eratosthenes( )
{
   

    is_prime[0] = is_prime[1] = false;
    for (int p = 2; p * p <= N; p++) {
        if (is_prime[p]) {
            for (int i = p * p; i <= N; i += p) {
                is_prime[i] = false;
            }
        }
    }
}

     void solve(){
          ll n;
          cin>>n;
          ll arr[n];
          multiset<ll>mst;
          map<ll,multiset<ll>>mp;
          for(ll i=0;i<n;i++){
              cin>>arr[i];
              mst.insert(arr[i]);
              for(auto it:prime[arr[i]]){
                  mp[it].insert(arr[i]);
              }
          }  
          ll q;
          cin>>q;
          while(q--){
               ll x;
               cin>>x;
             ll ans=1e9;
              for(auto it:prime[x]){
        
                if(!mp[it].empty())  {
                   ll k=*mp[it].begin();
                    ans=min(ans,k);
                }
                    }
                    if(ans==1e9){
                        cout<<*mst.begin()<<" ";
                        mst.erase(mst.begin());
                        continue;
                    }
                cout<<ans<<" ";
                for(auto it:prime[x]){
                 if(!mp[it].empty()) {  
                     if(mp[it].find(ans)!=mp[it].end()){
                         mp[it].erase(mp[it].find(ans));
                     }
                    }
                }
                mst.erase(mst.find(ans));
          }    
        //   for(auto it:prime[n]){
        //     cout<<it<<" ";
        //   }
           cout<<endl;
     }
     
      
int main(){
   CODE_BY_ABHAY_SINGH
   sieve();
   get();
    ll t;
    cin>>t;
     //t=1;
    while(t--){ 
    solve(); 
   }  
 return 0;
}

  
