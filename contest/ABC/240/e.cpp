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


struct edge{
    ll to, cost;
    edge(ll to, ll cost): to(to), cost(cost) {}
};
typedef vector<edge> edges;
typedef vector<edges> graph;
typedef pair<ll, ll> P;
graph G;

pair<ll, ll> ans[200009];

ll cum = 1;
void dfs(ll parent, ll now){
    ll prev_cum = cum;
    if(G[now].size() != 1 || now == 0){
        for(edge e: G[now]){
        if(e.to != parent){
            dfs(now, e.to);
        }
    }
    }else{
        ans[now].first = cum;
        ans[now].second = cum;
        cum++;
        return;
    }
    
    ans[now].first = prev_cum;
    ans[now].second = cum-1;

}

signed main(){

    ll N = in();

    REP(i, N){
        edges es;
        G.pb(es);
    }
    REP(i, N-1){
        ll A = in() -1;
        ll B = in() -1;
        G[A].pb(edge(B, 1));
        G[B].pb(edge(A, 1));
    }

    dfs(-1, 0);

    REP(i, N){
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    
}