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

struct edge{
    ll to, cost;
    edge(ll to, ll cost): to(to), cost(cost) {}
};

typedef vector<edge> edges;
typedef vector<edges> graph;
typedef pair<ll, ll> P;

template <class T=ll>
T in(){ T x; cin >> x; return (x);}

ll ans[100009][30];
graph G;
vector<ll> X_0;
vector<int> ind(100009, 0);
bool used[100009];

int dfs(ll state){

    used[state] = true;
    int chs = 1;
    if(G[state].size()==1 && state != 0){
        ans[state][0] = X_0[state];
        return 1;
    }else{
        
        for(edge e: G[state]){
            if(used[e.to] == false){
                chs += dfs(e.to);
            }
            
        }
    }

    REP(i, G[state].size()){
        ind[i] = 0;
    }
    bool s = true;

    REP(i, min(chs, 20)){
        ll m = -1, mi = -1;
        for(edge e: G[state]){
            if(m < ans[e.to][ind[e.to]]){
                m = ans[e.to][ind[e.to]];
                mi = e.to;
            }
        }
        bool si = true;
        if(s && m < X_0[state]){
            m = X_0[state];
            s = false;
            si = false;
        }

        ans[state][i] = m;
        if(si) ind[mi] = ind[mi] + 1;

    }
    return chs;
}

signed main(){

    REP(i, 100009){
        used[i] = false;
    }

    REP(i, 100009){
        REP(j, 30){
            ans[i][j] = -1;
        }
    }

    ll N = in(), Q = in();
    
    REP(i, N){
        X_0.pb(in());
    }

    
    REP(i, N){
        edges es;
        G.pb(es);
    }
    REP(i, N-1){
        ll A = in()-1;
        ll B = in() -1;
        G[A].pb(edge(B, 1));
        G[B].pb(edge(A, 1));
    }

    dfs(0);

    REP(i, Q){
        ll V = in(), K = in();
        cout << ans[V-1][K-1] << endl;
    }


    
}