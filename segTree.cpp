#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"
const int N = 1e5+2, MOD = 1e9+7;


template <class T, class U>
struct Lsegtree {
    ll n; vector <T> st; vector <U> lazy; T e; U u;
    Lsegtree (ll n, T e, U u) {
        this -> n = n; this -> e = e; this -> u = u;
        st.assign (4 * n, e); lazy.assign (4 * n, u);
    }
 
    T combine (T l, T r) {
        T ans = max (l, r); return ans;
    }
 
    void buildUtil (ll v, ll tl, ll tr, vector <T> &a) {
        if (tl == tr) {
            st[v] = a[tl]; return;
        }
        ll tm = (tl + tr) >> 1;
        buildUtil (2 * v + 1, tl, tm, a);
        buildUtil (2 * v + 2, tm + 1, tr, a);
        st[v] = combine (st[2 * v + 1], st[2 * v + 2]);
    }
 
    T apply (T cur, U upd, ll tl, ll tr) {
        T ans = max (cur, upd); return ans;
    }
 
    U combineUpdate (U old_upd, U new_upd, ll tl, ll tr) {
        U res = max(old_upd, new_upd); return res; 
    }
 
    void push_down (ll v, ll tl, ll tr) {
        if (lazy[v] == u) return;
        st[v] = apply (st[v], lazy[v], tl, tr);
        if (2 * v + 2 < 4 * n) {
            ll tm = (tl + tr) >> 1;
            lazy[2 * v + 1] = combineUpdate (lazy[2 * v + 1], lazy[v], tl, tm);
            lazy[2 * v + 2] = combineUpdate (lazy[2 * v + 2], lazy[v], tm + 1, tr);
        }
        lazy[v] = u;
    }
 
    T queryUtil (ll v, ll tl, ll tr, ll l, ll r) {
        push_down (v, tl, tr);
        if (l > r) return e;
        if (tr < l || tl > r) return e;
        if (l <= tl && r >= tr) return st[v];
        ll tm = (tl + tr) >> 1;
        return combine (queryUtil (2 * v + 1, tl, tm, l, r), 
                        queryUtil (2 * v + 2, tm + 1, tr, l, r));
    }
 
    void updateUtil (ll v, ll tl, ll tr, ll l, ll r, U upd) {
        push_down (v, tl, tr);
        if (tr < l || tl > r) return;
        if (tl >= l && tr <= r) {
            lazy[v] = combineUpdate (lazy[v], upd, tl, tr); push_down (v, tl, tr);
        }
        else {
            ll tm = (tl + tr) >> 1;
            updateUtil (2 * v + 1, tl, tm, l, r, upd);
            updateUtil (2 * v + 2, tm  + 1, tr, l, r, upd);
            st[v] = combine (st[2 * v + 1], st[2 * v + 2]);
        }
    }
 
    void build (vector <T> a) {
             assert ( a.size() == n);
            buildUtil (0, 0, n - 1, a);
    }
 
    T query (ll l, ll r) {
        return queryUtil (0, 0, n - 1, l, r);
    }
 
    void update (ll l, ll r, U upd) {
        updateUtil (0, 0, n - 1, l, r, upd);
    }
};
 


signed main(){
    
    return 0;
}


