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

vector<ll> Dijkstra2(graph &G, ll r){
    ll V = G.size();
    vector<ll> dist(V, INF64);
    priority_queue<P, vector<P>, greater<P> > pq;
    dist[r] = 0;
    pq.push(P(0, r));

    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        ll v = p.second;
        if(dist[v]<p.first) continue;
        for(ll i=0;i<G[v].size();i++){
            edge e = G[v][i];
            if(dist[e.to] <= dist[v] + e.cost) continue;
            dist[e.to] = dist[v] + e.cost;
            pq.push(P(dist[e.to], e.to));
        }
    }
    return dist;
}

signed main(){

    ll N=in(), M=in();
    graph G(N);
    REP(i, M){k
        ll A=in(), B=in(), C=in();
        G[A-1].pb(edge(B-1, C));
        G[B-1].pb(edge(A-1, C));
    }

    auto dist_0 = Dijkstra2(G, 0);
    auto dist_1 = Dijkstra2(G, N-1);

    REP(i, N){
        cout << dist_0[i] + dist_1[i] << endl;
    }

    


    
}