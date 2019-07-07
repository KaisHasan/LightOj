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

map<string , int> code;
vi adj[MAX];
int n;
bool cycle;
int vis[MAX];
int dfs(int u){
    vis[u] = 1;
    for(auto v : adj[u]){
        if(!vis[v])
            dfs(v);
        else if(vis[v] == 1)
            cycle = true;
    }
    vis[u] = 2;
}

int main(){

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        int m;
        sc(m);
        n = 0;
        while(m--){
            string s , t;
            cin>>s>>t;
            if(code.find(s) == code.end())
                code[s] = n++;
            if(code.find(t) == code.end())
                code[t] = n++;
            int u = code[s];
            int v = code[t];
            adj[u].pb(v);
        }
        cycle = false;
        mem(vis,0);
        for(int i = 0 ; i < n ; ++i){
            if(!vis[i])
                dfs(i);
        }
        printf("Case %d: " , ++cases);
        if(cycle)
            printf("No");
        else
            printf("Yes");
        blank;
        code.clear();
        for(int i = 0 ; i < n ; ++i)
            adj[i].clear();

    }


return 0;
}
