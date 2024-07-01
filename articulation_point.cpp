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
 
   // ONCE A NOOB ALWAYS A NOOB 
int n; // number of nodes
vector<vector<int>> adj; // adjacency list of graph

vector<bool> visited;
vector<int> tin, low;
int timer;

void dfs(int v, int p = -1) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    int children=0;
    for (int to : adj[v]) {
        if (to == p) continue;
        if (visited[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] >= tin[v] && p!=-1)
           //     IS_CUTPOINT(v);
            ++children;
        }
    }
    if(p == -1 && children > 1){
        // IS_CUTPOINT(v);
    }
       
}

void find_cutpoints() {
    timer = 0;
    visited.assign(n, false);
    tin.assign(n, -1);
    low.assign(n, -1);
    for (int i = 0; i < n; ++i) {
        if (!visited[i])
            dfs (i);
    }
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