#include<bits/stdc++.h>

using namespace std;
typedef long l;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
const int MAX = 1e5+55;
const int inf = 1e7+77;

int lyk , vam;
int mx;
int exist[MAX];
vector<int> adj[MAX];
int vis[MAX];
bool even;
void dfs(int v , int even){
    vis[v] = 1;
    if(even) lyk++;
    else vam++;
    for(int i = 0 ; i < adj[v].size() ; ++i){
        if(!vis[adj[v][i]]){
            dfs(adj[v][i] , 1 - even);
        }
    }
}

int main(){
int t;
sc(t);
for(int o = 1 ; o <= t ; ++o){
    memset(vis  , 0 , sizeof(vis));
    memset(exist  , 0 , sizeof(exist));
    int n;
    sc(n);
    mx = 0;
    for(int i = 0 ; i < n ; ++i){
        int x , y;
        sc(x);
        sc(y);
        exist[x] = 1;
        exist[y] = 1;
        adj[x].push_back(y);
        adj[y].push_back(x);
        mx = max(mx , x);
        mx = max(mx , y);
    }
    int res = 0;
    for(int i = 1 ; i <= mx ; ++i){
        if(vis[i] || !exist[i])
            continue;
        even = 1;
        lyk = 0 , vam = 0;
        dfs(i , even);
        res += max(lyk , vam);
    }
    printf("Case %d: " , o);
    printf("%d\n",res);
    for(int i = 0 ; i <= mx + 5 ; ++i)
        adj[i].clear();
}





return 0;
}
