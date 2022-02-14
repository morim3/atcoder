#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i=0; i<(n); ++i)
typedef long long ll;

#define pb push_back
#define ALL(x) x.begin(),x.end() 

const int mod = 1000000007; //10**9+7
#define INF32 2147483647 //2.147483647×10^{9}:32bit整数のinf
#define INF64 9223372036854775807 //9.223372036854775807×10^{18}:64bit整数のinf

template <class T=int>
T in(){ T x; cin >> x; return (x);}

#define int ll

struct edge{
    int to, cost;
    edge(int to, int cost): to(to), cost(cost) {}
};

typedef vector<edge> edges;
typedef vector<edges> graph;
typedef pair<int, int> P;

vector<int> Dijkstra2(graph &G, int r){
    int V = G.size();
    vector<int> dist(V, INF32);
    priority_queue<P, vector<P>, greater<P> > pq;
    dist[r] = 0;
    pq.push(P(0, r));

    while(!pq.empty()){
        P p = pq.top();
        pq.pop();
        int v = p.second;
        if(dist[v]<p.first) continue;
        for(int i=0;i<G[v].size();i++){
            edge e = G[v][i];
            if(dist[e.to] <= dist[v] + e.cost) continue;
            dist[e.to] = dist[v] + e.cost;
            pq.push(P(dist[e.to], e.to));
        }
    }
    return dist;
}



signed main(){

    int N = in(); int M = in();
    vector<int> h;
    h.pb(INF32);
    REP(i, N){
        h.pb(in());
    }

    graph G(N+10);

    REP(i, M){
        int u = in(); int v = in();
        if(h[u] > h[v]){
            G[u].pb(edge(v, -(h[u]-h[v])));
            G[v].pb(edge(u, (h[u]-h[v])*2));
        }else{
            G[v].pb(edge(u, -(h[v]-h[u])));
            G[u].pb(edge(v, (h[v]-h[u])*2));
        }

    }

    auto dist = Dijkstra2(G, 1);

    int ans = INF32;
    REP(i, N+3){
        ans = min(dist[i], ans);
    }

    cout << -ans << endl;

    
}