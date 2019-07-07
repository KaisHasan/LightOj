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

vi adj[MAX];
int inD[MAX];
int vis[MAX];
int outD[MAX];
void dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u])
        if(!vis[v])
            dfs(v);
}
vi nodes;

bool cmp(int a , int b){
    return outD[a] > outD[b];
}

int main(){

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        int n , m;
        sc(n);sc(m);
        mem(inD,0);
        mem(vis,0);
        mem(outD,0);
        for(int i = 0 ; i < m ; ++i){
            int u , v;
            sc(u);sc(v);
            adj[u].pb(v);
            inD[v]++;
            outD[u]++;
        }
        int cnt = 0;
        for(int i = 1 ; i <= n ; ++i){
            if(!inD[i]){
                ++cnt;
                dfs(i);
            }
        }
        for(int i = 1 ; i <= n ; ++i){
            if(!vis[i]){
                nodes.pb(i);
            }
        }
        sort(all(nodes) ,cmp);
        for(int i = 0 ; i < (int)nodes.size() ; ++i){
            int u = nodes[i];
            if(!vis[u]){
                ++cnt;
                dfs(u);
            }
        }
        nodes.clear();

        printf("Case %d: %d\n" , ++cases , cnt);
    }


return 0;
}
