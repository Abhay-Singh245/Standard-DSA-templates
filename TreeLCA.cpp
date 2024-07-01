#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define M 1000000007
#define all(arr) arr.begin(),arr.end()
#define CODE_BY_ABHAY_SINGH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
void pv(vector<ll>v){ for(ll i=0;i<(ll)v.size();i++) cout<<v[i]<<" ";cout<<endl;}
void pyn(bool f) {cout<<(f?"Yes":"No")<<endl;} 
const ll mod=998244353;
 
     class Tree{
 
            public:
            int n,LOG;
             vector <vector <int>> nxt;
             vector<int>level ;
 
             Tree(int n,int LOG = 30 ){
                    this->n = n;
                    this->LOG = LOG;
                    nxt.resize(n,vector<int>(LOG + 1 ,0));
                    level.resize(n , 0) ;
             }
 
             void build(vector<int>adj[]){
 
                  function<void(int , int , int)>dfs = [&](int node , int par , int lev) ->void{
 
                       level[node] = lev  ;
                       nxt[node][0] = max(par , 0) ;
                       for(int i = 1 ; i < LOG ; i ++){
                                nxt[node][i] = nxt[nxt[node][i - 1]][i - 1 ];
                       }
 
                       for(auto it : adj[node]){
                           if(it != par)  dfs(it , node , lev + 1) ;
                       }
 
                  } ;
                  dfs(0 , -1 , 0) ;
              }
 
         // return Kth ancestor of a node x

         int qry(int x, int k){
          
           int res = x;
           while (k > 0){
                
            int jump = k & (-k);
            int bit = __builtin_ctz(jump);
             res = nxt[res][bit];
           k -= jump;
          }
           return res;
        }
        
        // returns lca of a and b 
 
      ll lca(ll a,ll b ){
         
        if(level[a] > level[b]) swap(a, b);
           int diff = level[b] - level[a];
          b = qry( b , diff) ;
        int bit = LOG - 1;
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
              return a ;
         }
 
      };
 
 
     void solve(){
         
                ll n , m ;
                cin >> n >> m ;
 
                vector<int>adj[n] ;
                vector<ll>path(n);
 
                for(ll i = 0 ; i < n - 1 ; i ++){
                        ll u ,  v ;
                        cin >> u >>  v ;
                         -- u  , -- v ;
                        adj[u].push_back(v);
                        adj[v].push_back(u);
                }
                Tree Tr(n) ;
                Tr.build(adj) ;
             
               while(m --){
                    ll u , v ;
                    cin >> u >> v ;
                    -- u , -- v ;
                    path[u] ++ , path[v] ++ ;
                    ll L =  Tr.lca(u , v);
                    ll JU = Tr.nxt[L][0] ;
                  
                     path[L] -- ;
                    if(L != 0 ) path[JU] -- ;
               }
              
               vector<ll> ans(n);
               
               function<void(ll  , ll)> dfs = [&](ll node , ll par) ->void{
 
                        ans[node] = path[node] ;
                          for(auto it : adj[node]){
                                 if(it != par){
                                   dfs(it , node) ;
                                   ans[node] += ans[it] ;
                                 }
                          }
               };
              dfs(0 , -1) ;
              pv(ans) ;
   }
 
int main(){
   CODE_BY_ABHAY_SINGH
 
     ll T;
      T=1; 
  //  cin>>T;  
   while(T--){
   solve();  
   }  
 return 0;
}