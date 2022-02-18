
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

ll H, W;

bool suggest_neibor(ll r, ll c, ll dh, ll dw){
    if(r + dh <= 0 || r + dh > H){
        return false;
    }
    if(c + dw <= 0 || c + dw > W){
        return false;
    }

    return true;
}

UnionFind uf;

signed main(){
    
    H=in();
    W=in();
    ll Q=in();
    bool used[2009*2009];
    uf.init(H*W+2009);

    ll dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    

    REP(i, Q){
        ll ty = in();
        if(ty == 1){
            ll r=in(), c=in();
            ll index = r*W+c;
            used[index] = true;
            REP(i, 4){
                if(suggest_neibor(r, c, dir[i][0], dir[i][1])){
                    ll neibor = (r + dir[i][0]) * W + c + dir[i][1];
                    if(used[neibor]) uf.unite(neibor, index);
                    
                    
                }
                
            }
            
        }else{
            ll ra=in(), ca=in(), rb=in(), cb=in();
            


            if(used[ra*W+ca] && used[rb*W+cb] && uf.same(ra*W+ca, rb*W+cb)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }

        }
    }

    
    
