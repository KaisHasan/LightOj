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
int dis1[MAX];
int dis2[MAX];
void BFS(int st){
    memset(vis , 0 , sizeof(vis));
    memset(dis1 , 0 , sizeof(dis1));
    queue<int> q;
    q.push(st);
    vis[st] = 1;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int i = 0 ; i < adj[v].size() ; ++i){
            if(!vis[adj[v][i]]){
                vis[adj[v][i]] = 1;
                dis1[adj[v][i]] = dis1[v] + 1;
                q.push(adj[v][i]);
            }
        }
    }
}

int main(){

    int t;
    sc(t);
    for(int o =1 ; o <= t ; ++o){

        int n;
        sc(n);
        int m;
        sc(m);

        for(int i = 0 ;i < m; ++i){
            int u , v;
            sc(u);
            sc(v);
            adj[u].pb(v);
            adj[v].pb(u);
        }
        int st , en;
        sc(st);
        sc(en);
        BFS(st);
        memset(vis , 0 , sizeof(vis));
        memset(dis2 , 0 , sizeof(dis2));
        queue<int> q;
        q.push(en);
        vis[en] = 1;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            for(int i = 0 ; i < adj[v].size() ; ++i){
                if(!vis[adj[v][i]]){
                    vis[adj[v][i]] = 1;
                    dis2[adj[v][i]] = dis2[v] + 1;
                    q.push(adj[v][i]);
                }
            }
        }
        int mx = 0;
        for(int i = 0 ;i< n ; ++i){
            int d = dis1[i] + dis2[i];
            if(d > mx)
                mx = d;
        }
        printf("Case %d: %d\n" , o , mx);
        for(int i = 0 ; i < n ; ++i){
            adj[i].clear();
        }
    }




return 0;
}
