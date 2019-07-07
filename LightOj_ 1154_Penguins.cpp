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
#define INF 1e9
#define EPS 1e-9
vector<int> months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;


struct FlowEdge {
    int v, u;
    long long cap, flow = 0;
    FlowEdge(int v, int u, long long cap) : v(v), u(u), cap(cap) {}
};

struct Dinic {
    const long long flow_inf = 1e18;
    vector<FlowEdge> edges;
    vector<vector<int>> adj;
    int n, m = 0;
    int s, t;
    vector<int> level, ptr;
    queue<int> q;

    Dinic(int n, int s, int t) : n(n), s(s), t(t) {
        adj.resize(n);
        level.resize(n);
        ptr.resize(n);
    }

    void add_edge(int v, int u, long long cap) {
        edges.push_back(FlowEdge(v, u, cap));
        edges.push_back(FlowEdge(u, v, 0));
        adj[v].push_back(m);
        adj[u].push_back(m + 1);
        m += 2;
    }

    bool bfs() {
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (int id : adj[v]) {
                if (edges[id].cap - edges[id].flow < 1)
                    continue;
                if (level[edges[id].u] != -1)
                    continue;
                level[edges[id].u] = level[v] + 1;
                q.push(edges[id].u);
            }
        }
        return level[t] != -1;
    }

    long long dfs(int v, long long pushed) {
        if (pushed == 0)
            return 0;
        if (v == t)
            return pushed;
        for (int& cid = ptr[v]; cid < (int)adj[v].size(); cid++) {
            int id = adj[v][cid];
            int u = edges[id].u;
            if (level[v] + 1 != level[u] || edges[id].cap - edges[id].flow < 1)
                continue;
            long long tr = dfs(u, min(pushed, edges[id].cap - edges[id].flow));
            if (tr == 0)
                continue;
            edges[id].flow += tr;
            edges[id ^ 1].flow -= tr;
            return tr;
        }
        return 0;
    }
    int num = 0;
    long long flow() {
        long long f = 0;
        for(auto &e : edges)
            e.flow = 0;
        while (true) {
            fill(level.begin(), level.end(), -1);
            level[s] = 0;
            q.push(s);
            if (!bfs())
                break;
            fill(ptr.begin(), ptr.end(), 0);
            while (long long pushed = dfs(s, flow_inf)) {
                f += pushed;
            }
        }
        return f;
    }
};

struct node{
    double x , y;
    int np , c;
    node(double _x = 0.0, double _y = 0.0, int _np = 0, int _c = 0){
        x = _x;
        y = _y;
        np = _np;
        c = _c;
    }
    node(const node& t){
        x = t.x;
        y = t.y;
        np = t.np;
        c = t.c;
    }
};

node loc[300];
int in[300] , out[300];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    int t;
    sc(t);
    int cases = 0;
    while(t--){
        int n;
        sc(n);
        double dis;
        scd(dis);
        int tot = 0;
        in[0] = out[0] = 1;
        Dinic d(2*n + 1 , 0 , 1);
        for(int i = 1 ; i <= n ; ++i){
            in[i] = i;
            out[i] = i + n;
        }
        for(int i = 1 ; i <= n ; ++i){
            double x , y;
            scd(x);scd(y);
            int np;
            sc(np);
            int c;
            sc(c);
            tot += np;
            loc[i] = node(x , y , np , c);
            d.add_edge(in[i] , out[i] , c);
            d.add_edge(out[i] , in[i] , c);
        }
        dis *= dis;
        for(int i = 1 ; i <= n ; ++i){
            for(int j = 1 ; j <= n ; ++j){
                if(i == j)
                    continue;
                double x1 = loc[i].x;
                double y1 = loc[i].y;
                double x2 = loc[j].x;
                double y2 = loc[j].y;
                double dist = (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);
                if(dist - dis > eps)
                    continue;
                d.add_edge(out[i] , in[j] , loc[i].c);
            }
        }
        for(int i = 1 ; i <= n ; ++i){
            d.add_edge(0 , in[i] , loc[i].np);
        }
        int res = d.flow();
        vi ans;
        ans.clear();
        if(res == tot){
            ans.pb(0);
        }
        for(int i = 2 ; i <= n; ++i){
            d.t = i;
            res = d.flow();
            if(res == tot){
                ans.pb(i-1);
            }
        }
        printf("Case %d:" , ++cases);
        if((int)ans.size() == 0){
            printf(" -1\n");
        }
        else{
            for(auto it : ans)
                printf(" %d" , it);
            blank;
        }
    }




return 0;
}
