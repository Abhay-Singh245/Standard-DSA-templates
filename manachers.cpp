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
ll N=500010;
ll MN=-1e10;


  // ONCE A NOOB ALWAYS A NOOB


vector<ll> manachers(string S, ll N){

        vector<ll>A(N);

        // ...x character ... center ...x characters -> return x as A[center];
      
    ll r = 0, p = 0;
    for (int i = 0; i < N; i++)
    {
        if (i <= r)
            A[i] = min(A[2 * p - i], r - i);
        else
            A[i] = 0;
 
        while (i - A[i] - 1 >= 0 && i + A[i] + 1 < N && S[i - A[i] - 1] == S[i + A[i] + 1])
            A[i]++;
 
        if (r < i + A[i])
        {
            r = i + A[i];
            p = i;
        }
    }

    return A;
}

     void solve(){ 
        
                ll n;
                cin>>n;
                 string s;
                 cin>>s;
                 string r;
                 for(auto it:s){
                    r.push_back('#');
                    r.push_back(it);
                 }
                   r.push_back('#');
                   cout<<r<<endl;
                   vector<ll>v = manachers(r,2*n+1);
                   pv(v);
           
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