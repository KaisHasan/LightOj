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
int vis[MAX] , cnt[MAX] , cmp[MAX] , inD[MAX] , mn[MAX];
vi SCC;
vpi edges;
int dfs_num[MAX] , dfs_low[MAX];
int dfsNumberCounter;
int numSCC;
int n;

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
        mn[numSCC] = u;
        while(1){
            int v = SCC.back();
            SCC.pop_back();
            vis[v] = 0;
            cmp[v] = numSCC;
            cnt[numSCC]++;
            mn[numSCC] = min(mn[numSCC] , v);
            if(u == v)
                break;
        }
    }
}
int dp[MAX];
int solve(int node){
    int &res = dp[node];
    if(res != -1)
        return res;
    res = cnt[node];
    for(auto v : G[node]){
        res += solve(v);
    }
    return res;
}


int main(){

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        memset(vis , 0 , sizeof(vis));
        memset(dfs_num , -1 ,sizeof(dfs_num));
        memset(dfs_low , 0 , sizeof(dfs_low));
        dfsNumberCounter = numSCC = 0;
        edges.clear();
        mem(cnt,0);
        mem(inD,0);
        SCC.clear();
        sc(n);
        int m = n;
        while(m--){
            int u , v;
            sc(u);sc(v);
            --u;--v;
            adj[u].pb(v);
            edges.pb(MP(u,v));
        }
        for(int i = 0 ; i < n ; ++i){
            if(dfs_num[i] == -1){
                tarjanSCC(i);
            }
        }
        for(auto e : edges){
            int u = e.first;
            int v = e.second;
            if(cmp[u] != cmp[v]){
                G[cmp[u]].pb(cmp[v]);
                inD[cmp[v]]++;
            }
        }
        mem(dp,-1);
        pi ans = MP(-1,-1);
        for(int i = 1 ; i <= numSCC ; ++i){
            if(inD[i])
                continue;
            int res = solve(i);
            if(res > ans.first){
                ans = MP(res , mn[i]);
            }
            else if(res == ans.first){
                ans = MP(res , min(ans.second , mn[i]));
            }
        }

        printf("Case %d: %d\n" , ++cases , ans.second + 1);
        for(int i = 0; i <= n ; ++i)
            adj[i].clear();
        for(int i = 0 ; i <= numSCC ; ++i)
            G[i].clear();
    }


return 0;
}
