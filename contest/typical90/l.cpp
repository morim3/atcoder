#TODO

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i=0; i<(n); ++i)
#define FOR(i, j, n) for(ll i=(j); i<(n); ++i)


#define pb push_back
#define ALL(x) x.begin(),x.end() 

const ll mod = 1000000007; //10**9+7
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf

template <class T=ll>
T in(){ T x; cin >> x; return (x);}


class UnionFind {
public:
	vector<ll> par;

	void init(ll sz) {
		par.resize(sz, -1);
	}
	ll root(ll pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return par[pos];
	}
	void unite(ll u, ll v) {
		u = root(u); v = root(v);
		if (u == v) return;
		par[u] = v;
	}
	bool same(ll u, ll v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};


UnionFind uf;

signed main(){
    
    ll H=in();
    ll W=in();
    ll Q=in();
    bool used[2009][2009];
    uf.init(H*W);

    ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    

    REP(i, Q){
        ll ty = in();
        if(ty == 1){
            ll r=in(), c=in();
            ll exist = INF32;
            REP(i, 4){
                ll neibor = uf.root((r+dir[i][0])*H+c+dir[i][1]]);
                if(neibor < INF32){
                    state_tree[max(exist, neibor)] = min(exist, neibor);
                    exist = min(exist, neibor);
                }
            }
            if(exist<INF32) state[r][c] = exist;
            else state[r][c] = ++now;
            

        }else{
            ll ra=in(), ca=in(), rb=in(), cb=in();
            ll state_a = state[ra][ca];
            while(state_tree[state_a]<INF32){
                state_a = state_tree[state_a];
            }
            ll state_b = state[rb][cb];
            while(state_tree[state_b]<INF32){
                state_b = state_tree[state_b];
            }

            if(state_a == state_b){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }

        }
    }

    
    
}