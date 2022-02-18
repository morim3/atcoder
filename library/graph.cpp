#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf

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
