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

struct edge{
    int w , u , v;
};
bool cmp(edge a , edge b){
    return a.w < b.w;
}
bool cmp1(edge a , edge b){
    return a.w > b.w;
}
vector<pi> MST[MAX];
vector<edge> edges;
int rnk[MAX];
int par[MAX];
int vis[MAX];

void initi(int n){
    for(int i = 0 ; i <= n ; ++i)
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
int sum;
void dfs(int v){
    vis[v] = 1;
    for(auto i : MST[v]){
        if(!vis[i.first]){
            sum += i.second;
            dfs(i.first);
        }
    }
}

int main(){

int t;
sc(t);
for(int o = 1 ; o <= t ; ++o){
    memset(rnk , 1 , sizeof(rnk));
    int n;
    sc(n);
    initi(n);
    while(1){
        int w , u , v;
        sc(u);
        sc(v);
        sc(w);
        if(!u && !v && !w)
            break;
        edges.pb({w , u , v});
    }
    sort(edges.begin() , edges.end() , cmp);
    for(auto i : edges){
        if(_merge(i.u , i.v)){
            MST[i.u].pb({i.v , i.w});
            MST[i.v].pb({i.u , i.w});
        }
    }
    memset(vis , 0 , sizeof(vis));
    dfs(0);
    int min_sum = sum;
    sum = 0;

    for(int i = 0 ; i <= n ; ++i)
        MST[i].clear();
    sort(edges.begin() , edges.end() , cmp1);
    memset(rnk , 1 , sizeof(rnk));
    initi(n);
    for(auto i : edges){
        if(_merge(i.u , i.v)){
            MST[i.u].pb({i.v , i.w});
            MST[i.v].pb({i.u , i.w});
        }
    }
    memset(vis , 0 , sizeof(vis));
    dfs(0);
    int max_sum = sum;
    int tot_sum = min_sum + max_sum;
    printf("Case %d: " , o);
    if(tot_sum % 2)
        printf("%d/2\n" , min_sum + max_sum);
    else
        printf("%d\n" , (min_sum + max_sum) / 2);
    edges.clear();
    for(int i = 0 ; i <= n ; ++i)
        MST[i].clear();
    sum = 0;
}

return 0;
}
