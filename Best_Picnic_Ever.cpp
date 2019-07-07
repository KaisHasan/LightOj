#include<bits/stdc++.h>

using namespace std;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define scd(a) scanf("%lf" , &a)
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 0.0000001;

vector<int> adj[MAX];
int vis[MAX];
int reachable[MAX];
int dfs(int v){
    vis[v] = 1;
    reachable[v] += 1;
    for(int i = 0 ; i < adj[v].size() ; ++i){
        if(!vis[adj[v][i]]){
            dfs(adj[v][i]);
        }
    }
}

int main(){

    int t;
    sc(t);
    for(int o = 1 ; o <= t ; ++o){
        memset(reachable , 0 , sizeof(reachable));
        int k , n , m;
        sc(k);
        sc(n);
        sc(m);
        vector<int> friends;
        for(int i = 0 ; i < k ; ++i){
            int x;
            sc(x);
            friends.pb(x);
        }
        for(int i = 0 ; i < m ; ++i){
            int u , v;
            sc(u);
            sc(v);
            adj[u].pb(v);
        }

        for(auto _friend : friends){
            memset(vis , 0 ,sizeof(vis));
            dfs(_friend);
        }
        int res = 0;
        for(int i = 1 ; i <= n  ; ++i){
            if(reachable[i] == k){
                ++res;
            }
        }
        printf("Case %d: %d\n" , o , res);
        for(int i = 1 ; i <= n ; ++i){
            adj[i].clear();
        }
        friends.clear();
    }




return 0;
}
