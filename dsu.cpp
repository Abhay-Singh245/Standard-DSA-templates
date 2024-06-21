

# include<bits/stdc++.h>
# define ll long long
# define ld long double
#define M 1000000007
#define all(arr) arr.begin(),arr.end()
#define pll pair<ll,pair<ll,ll>> ;
#define CODE_BY_ABHAY_SINGH ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
 using namespace std;
 void pv(vector<ll>v){ for(ll i=0;i<(ll)v.size();i++) cout<<v[i]<<" ";cout<<endl;}
 void parr(ll n,ll v[]){ for(ll i=0;i<n;i++) cout<<v[i]<<" ";cout<<endl;}
 void pyn(bool f) {cout<<(f?"YES":"NO")<<endl;} 
const int N=2e5+3;
ll MX=1e18+10;


         class DSU
{
      public:
       
       ll n,number_component;
       vector<ll>parent,size,arr,minimum;
       
       DSU(ll n,vector<ll>arr){
       
        this->n=n;
        this->number_component=n;
        this->arr=arr;
        parent.resize(n);
        size.resize(n,1);
        minimum.resize(n);
     
        for(ll i=0;i<n;i++){
           parent[i]=i;
           minimum[i]=arr[i];
        }
 
       }
 
       ll find_par(ll node){
           
              if(node==parent[node]){
                 return node;
              }
               
               return  parent[node]=find_par(parent[node]);
       }
 
          void merge(ll node1,ll node2){
                
                ll par1=find_par(node1);
                ll par2=find_par(node2);
 
                if(par1==par2){
                    return;
                }
                number_component--;
                if(size[par1]>size[par2]){
                      parent[par2]=par1;
                      size[par1]+=size[par2];
                      minimum[par1]=min(minimum[par1],minimum[par2]);
                }
                else{
                       parent[par1]=par2;
                       size[par2]+=size[par1];
                       minimum[par2]=min(minimum[par1],minimum[par2]);
                }
 
          }
 
          pair<ll,ll> query(ll node){
             return {number_component,size[find_par(node)]};
          }
 
};




int main(){
   CODE_BY_ABHAY_SINGH

 return 0;
}