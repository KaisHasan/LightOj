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
vector<pi> MST[MAX];
vector<edge> edges;
int rnk[MAX];
int par[MAX];

void initi(int n){
    for(int i = 0 ; i < n ; ++i)
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
int cnt;
int vis[MAX];
void dfs(int v){
    vis[v] = 1;
    cnt++;
    for(auto i : MST[v]){
        if(!vis[i.first]){
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
    int w;
    int sum = 0;
    for(int i = 0 ; i < n; ++i){
        for(int j = 0 ; j < n ; ++j){
            sc(w);
            if(w != 0){
                if(i == j){
                    sum += w;
                }
                else{
                    edges.pb({w , i , j});
                }
            }
        }
    }
    sort(edges.begin() , edges.end() , cmp);
    for(auto i : edges){
        if(_merge(i.u , i.v)){
            MST[i.u].pb({i.v , i.w});
            MST[i.v].pb({i.u , i.w});
        }
        else{
            sum += i.w;
        }
    }
    cnt = 0;
    memset(vis , 0 , sizeof(vis));
    dfs(0);
    if(cnt != n){
        printf("Case %d: -1\n" , o );
    }
    else
        printf("Case %d: %d\n" , o , sum);
    edges.clear();
    for(int i = 0 ;i < n ; ++i)
        MST[i].clear();
}


return 0;
}
