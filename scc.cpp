
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

    class SCC {
        
        public:

         vector<vector<ll>>adj,Revadj,scc;
         vector<ll>vis,order;
         ll n,cnt;

          SCC (ll n,vector<ll> adj[]) {
             
              this->n=n;
              this->cnt=0;
              (this->adj).resize(n);
              (this->Revadj).resize(n);
              this->vis.assign(n,0);
              for(ll i=0;i<n;i++){
                       for(auto it:adj[i]){
                             this->adj[i].push_back(it);
                             this->Revadj[it].push_back(i);
                       }
              }

          }
           
           void dfs1(ll node){

                     vis[node]=1;

                     for(auto it:adj[node]){
                              if(!vis[it]){
                                    dfs1(it);
                              }
                     }
                     order.push_back(node);
           }
           void dfs2(ll node,vector<ll>&v){

                     vis[node]=1;
                     for(auto it:Revadj[node]){
                              if(!vis[it]){
                                    dfs2(it,v);
                              }
                     }
                     v.push_back(node);
           }
           
           void make_order(){
             for(ll i=0;i<n;i++){
                if(!vis[i]){
                       dfs1(i);
                }
           }
           }


           void store_scc(){
                
                 make_order();
                 vis.assign(n,0);
               while(!order.empty()){
                    
                    ll node=order.back();
                    order.pop_back();
                    if(vis[node]) continue;
                    cnt++;
                    vector<ll>temp;
                    dfs2(node,temp);
                    scc.push_back(temp);
               }    

           }

           vector<vector<ll>>get_scc(){
                 return scc;
           }
    };
  
 
     void solve(){

            
            ll n,m;
            cin>>n>>m;

            vector<ll>adj[n];

            while(m--){
                  ll a,b;
                  cin>>a>>b;
                  adj[--a].push_back(--b);
            }

            SCC *scc=new SCC(n,adj);
            
            scc->store_scc();
            vector<vector<ll>>v=scc->get_scc();
          
            ll cnt=0;
            
            vector<ll>ans(n);
            for(auto it:v){
                cnt++;
               for(auto ele:it){
                      ans[ele]=cnt;
               }
            }

            cout<<cnt<<endl;
            pv(ans);

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