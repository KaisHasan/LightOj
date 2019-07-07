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
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

vi adj[MAX] , G[MAX];
int n , m;
vpi edges;
int vis[MAX], cmp[MAX] , inD[MAX] , outD[MAX];
vi SCC;
int dfs_num[MAX] , dfs_low[MAX];
int dfsNumberCounter;
int numSCC;

void tarjanSCC(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    vis[u] = 1;
    SCC.pb(u);
    for(auto v : adj[u]){
        if(dfs_num[v] == -1){
            tarjanSCC(v);
        }
        if(vis[v]){
            dfs_low[u] = min(dfs_low[u] , dfs_low[v]);
        }
    }

    if(dfs_num[u] == dfs_low[u]){
        ++numSCC;
        while(1){
            int v = SCC.back();
            SCC.pop_back();
            vis[v] = 0;
            cmp[v] = numSCC;
            if(u == v)
                break;
        }
    }
}

int main(){

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        memset(vis , 0 , sizeof(vis));
        memset(dfs_num , -1 ,sizeof(dfs_num));
        memset(dfs_low , 0 , sizeof(dfs_low));
        mem(inD,0);
        mem(outD,0);
        dfsNumberCounter = numSCC = 0;
        SCC.clear();
        edges.clear();
        sc(n);sc(m);
        while(m--){
            int u , v;
            sc(u);sc(v);
            adj[u].pb(v);
            edges.pb(MP(u,v));
        }
        for(int i = 1 ; i <= n ; ++i){
            if(dfs_num[i] == -1)
                tarjanSCC(i);
        }
        for(auto e : edges){
            int u = e.first;
            int v = e.second;
            if(cmp[u] != cmp[v]){
                G[cmp[u]].pb(cmp[v]);
                inD[cmp[v]]++;
                outD[cmp[u]]++;
            }
        }
        int c1 = 0 , c2 = 0;
        for(int i = 1 ; i <= numSCC ; ++i){
            c1 += (inD[i] == 0);
            c2 += (outD[i] == 0);
        }
        int ans = max(c1 ,c2);
        if(numSCC == 1)
            ans = 0;
        printf("Case %d: %d\n" , ++cases , ans);
        for(int i = 0 ; i <= n ; ++i)
            adj[i].clear();
        for(int i = 0 ; i <= numSCC ; ++i){
            G[i].clear();
        }

    }


return 0;
}
