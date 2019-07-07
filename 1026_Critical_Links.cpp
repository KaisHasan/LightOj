#include<bits/stdc++.h>

using namespace std;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 0.0000001;

struct edge{
    int u ,v;
    edge(int _u , int _v){
        u = _u;
        v = _v;
    }
};
set<int> nodes;
multiset<int> adj[MAX];
int dfs_num[MAX] , dfs_low[MAX];
int dfs_parent[MAX];
int dfsNumberCounter;
vector<edge> Bridges;

void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(auto v : adj[u]){
        if(dfs_num[v] == -1){
            dfs_parent[v] = u;
            articulationPointAndBridge(v);
            if(dfs_low[v] > dfs_num[u]){
                edge e(u , v);
                Bridges.pb(e);
            }
            dfs_low[u] = min(dfs_low[u] , dfs_low[v]);
        }
        else if(v != dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u] , dfs_num[v]);
        }
    }
}

bool cmp(edge a , edge b){
    if(a.u < b.u)
        return 1;
    else if(a.u > b.u)
        return 0;
    else
        return a.v < b.v;
}


int main(){

    int t;
    sc(t);
    for(int cases = 1 ; cases <= t ; ++cases){
        dfsNumberCounter = 0;
        memset(dfs_num , -1 , sizeof(dfs_num));
        memset(dfs_low , 0 , sizeof(dfs_low));
        memset(dfs_parent , 0 , sizeof(dfs_parent));
        Bridges.clear();
        nodes.clear();
        int n;
        sc(n);
        for(int i = 0 ; i < n ; ++i){
            int u , k;
            scanf("%d (%d)", &u, &k);
            nodes.insert(u);
            for(int i = 0 ; i < k ; ++i){
                int v;
                sc(v);
                adj[u].insert(v);
            }
        }

    for(auto i : nodes){
        if(dfs_num[i] == -1){
            articulationPointAndBridge(i);
        }
    }
    int sz = Bridges.size();
    int res = sz;
    for(int i = 0 ; i < sz; ++i){
        int uu = Bridges[i].u;
        int vv = Bridges[i].v;
        Bridges[i].u = min(uu , vv);
        Bridges[i].v = max(uu , vv);
        if(adj[Bridges[i].u].count(Bridges[i].v) > 1 || adj[Bridges[i].v].count(Bridges[i].u) > 1){
            --res;
            Bridges[i].u = -1;
            Bridges[i].v = -1;
        }
    }
    sort(Bridges.begin() , Bridges.end() , cmp);
    printf("Case %d:\n" , cases);
    printf("%d critical links\n"  ,res);
    for(auto e : Bridges){
        if(e.u == -1 || e.v == -1)
            continue;
        printf("%d - %d\n" , e.u , e.v);
    }
    for(auto i : nodes)
        adj[i].clear();
}




return 0;
}
