#include <bits/stdc++.h>
using namespace std;

using ll = long long; 

class node {
public:
    vector <node*> bit; bool e;
    vector <int> ct;
    node () {
        bit.resize(2); e = 0;
        ct.resize(2);
    }
    void setEnd () {e = 1;}
    bool isEnd () {return e;}
};

class Trie {
public:
    ll sz; node* root;
    Trie (ll bit_count) {
        sz = bit_count; root = new node(); 
    } 

    void insert (ll x) {
        node* cur = root;
        for (ll bit = sz; bit >= 0; bit -= 1) {
            ll bt = (x >> bit & 1);
            if (cur -> bit[bt] == NULL) cur -> bit[bt] = new node();
            cur -> ct[bt] += 1;
            cur = cur -> bit[bt];
        }
        cur -> setEnd ();
    }
    
    void remove (ll x) {
        node* cur = root;
        for (ll bit = sz; bit >= 0; bit -= 1) {
            ll c_bit = (x >> bit & 1);
            cur -> ct[c_bit] -= 1;
            cur = cur -> bit[c_bit];
        }
    }

    bool isPresent (ll x) {
        node* cur = root;
        for (ll bit = sz; bit >= 0; bit -= 1) {
            if (cur -> ct[(x >> bit & 1)] == 0) return false;
            cur = cur -> bit[(x >> bit & 1)];
        }
        return (cur -> isEnd());
    }

    ll mxXor (ll x) {
        node* cur = root; ll res = 0;
        for (ll bit = sz; bit >= 0; bit -= 1) {
            ll c_bit = (x >> bit & 1);
            if (cur -> ct[1 - c_bit]) {
                res |= (1ll << bit); cur = cur -> bit[1 - c_bit];
            }
            else if (cur -> ct[c_bit]) {
                cur = cur -> bit[c_bit];
            }
        }
        return res;
    }

    ll mnXor (ll x) {
        node* cur = root; ll res = 0;
        for (ll bit = sz; bit >= 0; bit -= 1) {
            if (cur -> bit[(x >> bit & 1)]) cur = cur -> bit[(x >> bit & 1)];
            else if (cur -> bit[1 - (x >> bit & 1)]) {
                res |= (1ll << bit); cur = cur -> bit[1 - (x >> bit & 1)];
            }
        }
        return res;
    }
};

int main () {
    ios_base::sync_with_stdio();cin.tie(0);cout.tie(0);
    // int t_; cin >> t_;
    int t_ = 1;

    function <void()> solve = [&] () {
        ll n; cin >> n;

        ll x = 0;

        vector <ll> a (n);

        set <ll> st; Trie tree (32);

        for (ll i = 0; i < n - 1; i += 1) {
            cin >> a[i]; x ^= a[i];
            tree.insert (x);
        }

        for (ll op = 0; op < n; op += 1) {
            ll mx = max(op, tree.mxXor (op)), mn = min(tree.mnXor (op), op);

            if (mx == n - 1 && mn == 0) {
                vector <ll> ans;
                ans.push_back(op);
                for (ll i = 0; i < n - 1; i += 1) {
                    ans.push_back((ans.back() ^ a[i]));
                }

                for (auto ele : ans) {
                    cout << ele << " ";
                }
                cout << endl; return;
            }
        }
        cout << -1 << endl;
    };

    for (int i = 0; i < t_; i += 1) {
        solve ();
    }
}