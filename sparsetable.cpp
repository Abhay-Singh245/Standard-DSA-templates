# include<bits/stdc++.h>
# define ll long long
#define M 1000000007
#define all(arr) arr.begin(),arr.end()
#define CODE_BY_ABHAY_SINGH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 using namespace std;
 void pv(vector<ll>v){ for(ll i=0;i<v.size();i++) cout<<v[i]<<" ";cout<<endl;}
 void parr(ll n,ll v[]){ for(ll i=0;i<n;i++) cout<<v[i]<<" ";cout<<endl;}
 void pyn(bool f) {cout<<(f?"YES":"NO")<<endl;} 
const int N=5e3+2;

   // ONCE A NOOB ALWAYS A NOOB

      class Sparse_Table{
           
           // Template Copyright->Abhay Singh
            public:
            ll n,LOG;
             vector <vector <ll>> nxt,table;

             Sparse_Table(ll n,ll LOG){

                    this->n=n;
                    this->LOG=LOG;
                    nxt.resize(n,vector<ll>(LOG+3,-1));
                    table.resize(n,vector<ll>(LOG+3,0));
             }

             void build(vector<ll>&arr){
                    
                    ll m=arr.size();

                    for(ll i=0;i<m;i++){
                         nxt[i][0]=arr[i];
                         table[i][0]=arr[i];
                    }

                     for (ll i = 1; i < LOG; i += 1) {
                       for (ll j = 0; j < n; j += 1) {
                       if(nxt[j][i-1]!=-1)  {
                           nxt[j][i] = nxt[nxt[j][i - 1]][i - 1];
                           table[j][i]=table[j][i-1]+table[nxt[j][i-1]][i-1];
                       }
                     }
                 }
             }

         // return Kth ancestor of a node x
           ll qry(ll x, ll k) {
     
            ll res = x;

            for (ll i = LOG - 1; i >= 0; i -= 1) {
                if (k>=(1<<i)) {
                    if(nxt[res][i]==-1) break;
                    k-=(1<<i);
                    res=nxt[res][i];
                }
            }
            if(k!=0) res=-2;
            
             return res;
        }
        
        // returns lca only if a and b are at same level in the tree

         ll lca(ll a,ll b){
         
         ll bit =LOG;

           while(bit >= 0) {
            if(nxt[a][bit] != nxt[b][bit]) {
                a = nxt[a][bit];
                b = nxt[b][bit];
            }
            bit--;
        }
        if(a != b) {
            a = nxt[a][0];
            b = nxt[b][0];
        }
              return a;

         }

      };

  
   void solve () {
    
    
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

