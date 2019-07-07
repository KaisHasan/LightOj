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
const int MAX = 5055;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

vpi adj[MAX];
vll dis[MAX];

void dijkstra (int src , int n) {
   priority_queue <pi , vpi , greater<pi> > pq;
   pq.push (MP(0, src));
   while (!pq.empty()) {
      int u = pq.top().second;
      int w = pq.top().first;
      pq.pop();
      if (dis[u].size() == 0) dis[u].push_back (w);
      else if (dis[u].back() != w) dis[u].push_back (w); //same path distance ignored

      if (dis[u].size() > 2) continue;

      for (auto node : adj[u]) {
         if (dis[node.first].size() == 2) continue;
         int cur_dis = node.second + w;
         pq.push (MP(cur_dis,node.first));
      }
   }
   if (dis[n].size() < 2) printf ("Impossible\n");
   else printf ("%lld\n", dis[n][1]);
}

int main(){

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        int n , m;
        sc(n);sc(m);
        while(m--){
            int u , v , w;
            sc(u);sc(v);sc(w);
            adj[u].pb(MP(v,w));
            adj[v].pb(MP(u,w));
        }
        printf("Case %d: ", ++cases);
        dijkstra(1 , n);
        for(int i = 0 ; i <= n ; ++i)
            adj[i].clear();
        for(int i = 0 ; i <= n ; ++i)
            dis[i].clear();
    }


return 0;
}
