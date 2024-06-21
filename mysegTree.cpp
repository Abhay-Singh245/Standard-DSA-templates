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
      
   struct node{
         
          ll ans,lazy;
          node(){
              this->ans=0;  
              this->lazy=0;      
          }
      };
      
      class segTree{
         
            public:
             
            vector<node>Tree;

            segTree(ll n){
                 Tree.resize(4*n);
            }

            node merge(node node1,node node2){

                 node nd;
                 nd.ans=node1.ans+node2.ans;
                 return nd;

            }

            void push(ll idx,ll l,ll r){
                 
                 // Apply lazy
                  if(Tree[idx].lazy){
                       Tree[idx].ans+=(r-l+1)*Tree[idx].lazy;             
                // pushdown lazy;
                  if(l!=r){
                     Tree[2*idx].lazy+=Tree[idx].lazy;
                     Tree[2*idx+1].lazy+=Tree[idx].lazy;
                  }
                   Tree[idx].lazy=0;
                  }
            }

            node build(ll idx,ll l,ll r,vector<ll>&arr){
                  
                  if(l==r) {
                     Tree[idx].ans=arr[l];
                     return Tree[idx];
                  }
                  
                   ll mid=(l+r)/2;

                 return  Tree[idx]=merge(build(2*idx,l,mid,arr),build(2*idx+1,mid+1,r,arr));
            }

            ll query(ll idx,ll l,ll r,ll L,ll R){
                     
                     push(idx,l,r);

                   if(l>=L&&r<=R) {
                        push(idx,l,r);
                        return Tree[idx].ans;
                   }
                   if(l>R||r<L) return 0;

                   ll mid=(l+r)/2;

                   return query(2*idx,l,mid,L,R)+query(2*idx+1,mid+1,r,L,R);
            }
            
            void update(ll idx,ll l,ll r,ll L,ll R,ll val){
                       
                    push(idx,l,r);
                    if(l>=L&&r<=R){
                         Tree[idx].lazy+=val;
                         push(idx,l,r);
                         return; 
                    }
                    if(l>R||r<L) return ;

                    ll mid=(l+r)/2;

                    update(2*idx,l,mid,L,R,val);
                    update(2*idx+1,mid+1,r,L,R,val);
                    Tree[idx]=merge(Tree[2*idx],Tree[2*idx+1]);
            }

      };
       


     void solve(){
            segTree ST(99) ;
  
     }
 
int main(){

   CODE_BY_ABHAY_SINGH 
       ll T;
       T=1;
    //cin>>T;
    while(T--){
       solve();    
     }  
 return 0;
}
// Min segTree
// struct node{
         
//           ll ans,lazy;
//           node(){
//               this->ans=1e18;  
//               this->lazy=1e18;      
//           }
//       };
      
//       class segTree{
         
//             public:
             
//             vector<node>Tree;

//             segTree(ll n){
//                  Tree.resize(4*n);
//             }

//             node merge(node node1,node node2){

//                  node nd;
//                  nd.ans= min(node1.ans , node2.ans);
//                  return nd;

//             }

//             void push(ll idx,ll l,ll r){
                 
//                  // Apply lazy
//                   if(Tree[idx].lazy != 1e18){
//                        Tree[idx].ans =  Tree[idx].lazy ;             
//                 // pushdown lazy;
//                   if(l!=r){
//                      Tree[2*idx].lazy = min(Tree[idx].ans , Tree[2 * idx].lazy);
//                      Tree[2*idx+1].lazy = min(Tree[idx].ans , Tree[2 * idx + 1].lazy);
//                   }
//                    Tree[idx].lazy=1e18;
//                   }
//             }

//             node build(ll idx,ll l,ll r ){
                  
//                   if(l==r) {
//                      Tree[idx].ans = 1e18;
//                      return Tree[idx];
//                   }
                  
//                    ll mid=(l+r)/2;

//                  return  Tree[idx]=merge(build(2*idx,l,mid ),build(2*idx+1,mid+1,r ));
//             }

//             ll query(ll idx,ll l,ll r,ll L,ll R){
                     
//                      push(idx,l,r);

//                    if(l>=L&&r<=R) {
//                         push(idx,l,r);
//                         return Tree[idx].ans;
//                    }
//                    if(l>R||r<L) return 1e18;

//                    ll mid=(l+r)/2;

//                    return min(query(2*idx,l,mid,L,R) , query(2*idx+1,mid+1,r,L,R));
//             }
            
//             void update(ll idx,ll l,ll r,ll L,ll R,ll val){
                       
//                     push(idx,l,r);
//                     if(l>=L && r<=R){
//                          Tree[idx].lazy = val ;
//                          push(idx,l,r);
//                          return; 
//                     }
//                     if(l>R || r<L) return ;

//                     ll mid=(l+r)/2;

//                     update(2*idx,l,mid,L,R,val);
//                     update(2*idx+1,mid+1,r,L,R,val);
//                     Tree[idx]=merge(Tree[2*idx],Tree[2*idx+1]);
//             }

//       };
       
