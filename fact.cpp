#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 2e5+10;
const ll M = 1e9 + 7;

  // ONCE A NOOB ALWAYS A NOOB

  // question ban jaega hai bas jee ka basic permution and combination yaad karo

  ll FACT[N+10];

   ll bin_exp(ll a,ll b){
    ll result=1;
    while(b>0){
      if(b&1){
        result=(result*a)%M;
      }
      a=(a*a)%M;
      b>>=1;
    }
    return  result;
  }
 // you have to call this fact() as precalculation
  void fact(){
    FACT[0] = 1;
    for(ll i = 1;i<=1e5+10;i++){
       FACT[i] = (FACT[i-1]*i)%M; 
    }
  }

  ll comb(ll n,ll r){
    ll x=FACT[n];
    ll y=FACT[n-r];
     ll z=(FACT[r]*y)%M;
    return (x*bin_exp(z,M-2))%M;
  }

void solve(){
    
//   ll n;
//   cin>>n;
//   ll arr[n];
//   for(ll i=0;i<n;i++){
//      cin>>arr[i];
//     //arr[i]=1;
//   }
//     ll M=998244353;
//   ll n1=n/3;
//  ll ans=comb(n1,n1/2,M);
//   ll k=1;

//   for(ll i=1;i<=(n);i+=3){
//     map<ll,ll>mp;
//      ll a=arr[i-1],b=arr[i],c=arr[i+1];
//       mp[a]++,mp[b]++,mp[c]++;
//     ll mx[3]={a,b,c};
 
//     sort(mx,mx+3);
//     ll p=mx[2],q=mx[0];
//     if(mp[p]==3){
//       k=((k)*3)%M;
   
//     }
//     else if((mp[q]==2)){
//         k=((k)*2)%M;
//   }
//     mp.clear();
//   }
//     ans=((ans)*(k))%M;
//     cout<<ans<<endl;
  
}
int main(){
  ll t;
 // cin>>t;
 t=1;
  while(t--){
    solve();
  }
  return 0;
}