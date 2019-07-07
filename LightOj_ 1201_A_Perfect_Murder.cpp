#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef pair<long long , long long> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pi> vpi;
typedef unsigned long long ull;
#define MP  make_pair
#define mem(a , v)  memset(a , v , sizeof(a))
#define all(v)	((v).begin()), ((v).end())
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
#define INF 1e9
#define EPS 1e-9
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

#define NIL 0

vector< int > G[MAX] , adj[MAX];
int n, m, match[MAX], dist[MAX];
// n: number of nodes on left side, nodes are numbered 1 to n
// m: number of nodes on right side, nodes are numbered n+1 to n+m
// G = NIL[0] + G1[G[1---n]] + G2[G[n+1---n+m]]

bool bfs() {
    int i, u, v, len;
    queue< int > Q;
    for(i=1; i<=n; i++) {
        if(match[i]==NIL) {
            dist[i] = 0;
            Q.push(i);
        }
        else dist[i] = INF;
    }
    dist[NIL] = INF;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(u!=NIL) {
            len = G[u].size();
            for(i=0; i<len; i++) {
                v = G[u][i];
                if(dist[match[v]]==INF) {
                    dist[match[v]] = dist[u] + 1;
                    Q.push(match[v]);
                }
            }
        }
    }
    return (dist[NIL]!=INF);
}

bool dfs(int u) {
    int i, v, len;
    if(u!=NIL) {
        len = G[u].size();
        for(i=0; i<len; i++) {
            v = G[u][i];
            if(dist[match[v]]==dist[u]+1) {
                if(dfs(match[v])) {
                    match[v] = u;
                    match[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroft_karp() {
    int matching = 0, i;
    // match[] is assumed NIL for all vertex in G
    while(bfs())
        for(i=1; i<=n; i++)
            if(match[i]==NIL && dfs(i))
                matching++;
    return matching;
}

void init(){
    for(int i = 0 ; i <= n + m + 1 ; ++i){
        G[i].clear();
        adj[i].clear();
    }
    mem(match,0);
}

int cnt[2];
int vis[MAX];
void solve(int u , int side , int par){
    vis[u] = side + 1;
    cnt[side]++;
    for(auto v : adj[u]){
        if(!vis[v] && v != par){
            solve(v , 1 - side , u);
        }
    }
}

vpi edges;
int code[MAX];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        init();
        mem(cnt,0);
        mem(vis,0);
        mem(code,-1);
        edges.clear();
        int k;
        sc(k);
        int e;sc(e);
        for(int i = 0 ; i < e ; ++i){
            int x, y;
            sc(x);sc(y);
            adj[x].pb(y);
            adj[y].pb(x);
            edges.pb(MP(x,y));
        }
        for(int i = 1 ; i <= k ; ++i){
            if(!vis[i])
                solve(i , 0 , -1);
        }
        n = cnt[0];
        m = cnt[1];
        int id1 = 1;
        int id2 = n + 1;
        for(auto e1 : edges){
            int u = e1.first;
            int v = e1.second;
            if(code[u] == -1){
                if(vis[u] == 2)
                    code[u] = id2++;
                else
                    code[u] = id1++;
            }
            if(code[v] == -1){
                if(vis[v] == 2)
                    code[v] = id2++;
                else
                    code[v] = id1++;
            }
            u = code[u];
            v = code[v];
            G[u].pb(v);
            G[v].pb(u);
        }
        int flow = hopcroft_karp();
        int res = k - flow;
        printf("Case %d: %d\n" , ++cases , res);
    }




return 0;
}
