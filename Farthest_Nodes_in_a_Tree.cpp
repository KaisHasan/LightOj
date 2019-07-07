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

vector<pi> adj[MAX];
int vis[MAX];


int main(){

    int t;
    sc(t);
    for(int o =1 ; o <= t ; ++o){
        memset(vis , 0 , sizeof(vis));
        int n;
        sc(n);
        for(int i = 0 ;i < n - 1; ++i){
            int u , v , w;
            sc(u);
            sc(v);
            sc(w);
            adj[u].pb({v , w});
            adj[v].pb({u , w});
        }
        int leaf = -1;
        for(int i = 0 ; i < n ; ++i){
            if(adj[i].size() == 1){
                leaf = i;
                break;
            }
        }
        queue<int> q;
        q.push(leaf);
        vis[leaf] = 1;
        pi mx = {-1 , -1};
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int i = 0 ; i < adj[v].size() ; ++i){
                if(!vis[adj[v][i].first]){
                    vis[adj[v][i].first] = vis[v] + adj[v][i].second;
                    q.push(adj[v][i].first);
                    if(mx.first < vis[adj[v][i].first]){
                        mx.first = vis[adj[v][i].first];
                        mx.second = adj[v][i].first;
                    }
                }
            }
        }
        memset(vis , 0 , sizeof(vis));
        q.push(mx.second);
        vis[mx.second] = 1;
        int _mx = -1;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int i = 0 ; i < adj[v].size() ; ++i){
                if(!vis[adj[v][i].first]){
                    vis[adj[v][i].first] = vis[v] + adj[v][i].second;
                    q.push(adj[v][i].first);
                    _mx = max(_mx , vis[adj[v][i].first]);
                }
            }
        }
        printf("Case %d: %d\n" , o , _mx - 1);
        for(int i = 0; i < n ; ++i){
            adj[i].clear();
        }
    }




return 0;
}
