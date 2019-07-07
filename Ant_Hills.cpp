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

vector<int> adj[MAX];
int dfs_num[MAX] , dfs_low[MAX];
int dfs_parent[MAX];
int dfsNumberCounter;
int articulation_vertex[MAX];
int dfsRoot , RootChildren;

void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++;
    for(auto v : adj[u]){
        if(dfs_num[v] == -1){
            dfs_parent[v] = u;
            if(u == dfsRoot)
                ++RootChildren;
            articulationPointAndBridge(v);
            if(dfs_low[v] >= dfs_num[u])
                articulation_vertex[u] = 1;
            dfs_low[u] = min(dfs_low[u] , dfs_low[v]);
        }
        else if(v != dfs_parent[u]){
            dfs_low[u] = min(dfs_low[u] , dfs_num[v]);
        }
    }
}


int main(){

    int t;
    sc(t);
    for(int cases = 1 ; cases <= t ; ++cases){
        RootChildren = 0;
        dfsNumberCounter = 1;
        memset(dfs_num , -1 , sizeof(dfs_num));
        memset(dfs_low , 0 , sizeof(dfs_low));
        memset(dfs_parent , 0 , sizeof(dfs_parent));
        memset(articulation_vertex , 0 , sizeof(articulation_vertex));

        int n , m;
        sc(n);sc(m);
        for(int i = 0 ;i < m ; ++i){
            int u , v;
            sc(u);sc(v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int res = 0;
        for(int i = 1 ; i <= n ; ++i){
            if(dfs_num[i] == -1){
                RootChildren = 0;
                dfsRoot = i;
                articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (RootChildren > 1);
                for(int j = 1 ; j <= n ; ++j){
                    if(articulation_vertex[j]){
                        ++res;
                    }
                }
            }
        }
        printf("Case %d: %d\n" , cases , res);
        for(int i = 1 ; i <= n ; ++i)
            adj[i].clear();
    }




return 0;
}
