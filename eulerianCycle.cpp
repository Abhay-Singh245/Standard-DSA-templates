#include<bits/stdc++.h>
#define ll long long
#define all(arr) arr.begin(),arr.end()
using namespace std;
void pv(vector<ll>v){ for(ll i=0;i<(ll)v.size();i++) cout<<v[i]<<" ";cout<<endl;}
void pyn(bool f) {cout<<(f?"Yes":"No")<<endl;} 
const ll mod=998244353 , M = 1e9 + 7 ;
 
   // ONCE A NOOB ALWAYS A NOOB 

     void solve(){
           
            ll n , m ;
            cin >> n >> m ;
            vector<ll>adj[n] , degree(n) ; 
            ll isolated = 0 ;

            for(ll i = 0 ; i < m ;i ++){
                   ll u  , v ;
                   cin >> u >> v ; 
                   adj[--u].push_back(--v);
                   adj[v].push_back(u);
                   degree[u] ++ , degree[v] ++ ;
            }

            for(ll i = 0 ; i < n ;i ++){
                   if(degree[i] & 1){
                       cout << "IMPOSSIBLE" << endl;
                       return;
                   }
                   if(degree[i] == 0) isolated ++ ;
            }
           
           vector <ll> ans ,  stk;

           stk.push_back(0);
           map<pair<ll,ll> , ll> mp;
           vector<ll>vis(n) ;

           while(!stk.empty()){
                 ll node = stk.back();
                                 
                while(!adj[node].empty() && mp.count({node , adj[node].back()})){
                       adj[node].pop_back() ;
                }
                 if(adj[node].empty()){                    
                     ans.push_back(node + 1);
                     vis[node] =  1 ;
                     stk.pop_back() ;
                 } else {
                      ll curr = adj[node].back();
                      adj[node].pop_back() ;
                      mp[{curr , node}] = 1 ;
                      stk.push_back(curr) ;
                 } 
           }

           if(accumulate(all(vis) , 0ll)  + isolated != n){
                     cout << "IMPOSSIBLE" << endl;
                     return;
           }

            pv(ans) ;

   } 

int main(){

   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    ll T = 1;
    // cin>>T;  
    while(T--){
     solve();  
   }  
 return 0;
}