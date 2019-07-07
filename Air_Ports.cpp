#include<bits/stdc++.h>

using namespace std;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 0.0000001;

struct edge{
    int w , u , v;
};
bool cmp(edge a , edge b){
    return a.w < b.w;
}
vector<pi> MST[MAX];
vector<edge> edges;
int rnk[MAX];
int par[MAX];

void initi(int n){
    for(int i = 1 ; i <= n ; ++i)
        par[i] = i;
}

int parent(int v){
    if(par[v] == v)
        return v;
    return par[v] = parent(par[v]);
}

bool _merge(int u , int v){
    if(parent(u) == parent(v))
        return 0;
    if(rnk[parent(u)] < rnk[parent(v)]){
        par[parent(u)] = parent(v);
        rnk[parent(v)] += rnk[parent(u)];
        return 1;
    }
    else
    {
        par[parent(v)] = parent(u);
        rnk[parent(u)] += rnk[parent(v)];
        return 1;
    }
}
int vis[MAX];
void dfs(int v){
    vis[v] = 1;
    for(auto i : MST[v]){
        if(!vis[i.first]){
            dfs(i.first);
        }
    }
}

int main(){

int t;
sc(t);
for(int o = 1; o <= t ; ++o){
    memset(rnk , 1 , sizeof(rnk));
    ll n , m , A;
    scl(n);
    scl(m);
    scl(A);
    initi(n);
    for(int i = 0 ; i < m ;++i){
        int w , u , v;
        sc(u);
        sc(v);
        sc(w);
        edges.pb({w , u , v});
    }
    ll sum = 0;
    sort(edges.begin() , edges.end() , cmp);
    for(auto i : edges){
        if(i.w < A){
            if(_merge(i.u , i.v)){
                MST[i.u].pb({i.v , i.w});
                MST[i.v].pb({i.u , i.w});
                sum += i.w;
            }
        }
    }
    memset(vis , 0 , sizeof(vis));
    ll cnt = 0;
    for(int i = 1 ; i <= n ; ++i){
        if(!vis[i]){
            ++cnt;
            dfs(i);
        }
    }
    ll res = cnt * A + sum;
    printf("Case %d: %lld %lld\n" , o , res , cnt);
    for(int i = 1 ; i <=n ; ++i)
        MST[i].clear();
    edges.clear();
}


return 0;
}
