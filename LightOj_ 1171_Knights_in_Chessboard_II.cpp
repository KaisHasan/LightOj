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
#define NIL 0

vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

vector< int > G[MAX];
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
    }
    mem(match,0);
}

int grid[333][333];
int dx[] = {2 , -2 , 1 , 1, 2 , -2  , -1 , -1};
int dy[] = {1 , 1 , 2 , -2 , -1 , -1 , 2 , -2};
int r , c;

bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < r && y < c && grid[x][y];
}

int code(int x , int y){
    return (x * c) + y + 1;
}

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        sc(r);sc(c);int k;sc(k);
        init();
        mem(grid , 1);
        n = r * c;
        for(int i = 0 ; i < k ; ++i){
            int x ,  y;
            sc(x);sc(y);
            --x;--y;
            grid[x][y] = 0;
        }
        for(int i = 0 ; i < r ; ++i){
            for(int j = 0 ; j < c ; ++j){
                if(grid[i][j]){
                    int x = i;
                    int y = j;
                    for(int k = 0 ; k < 8 ; ++k){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(valid(nx,ny)){
                            G[code(x,y)].pb(code(nx,ny));
                        }
                    }
                }
            }
        }

        int res = n - hopcroft_karp() - k;
        printf("Case %d: %d\n" , ++cases , res);
    }




return 0;
}
