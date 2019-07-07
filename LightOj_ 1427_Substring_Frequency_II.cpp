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


#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

typedef long long llint;
const int ALPHA = 26;

int V;
int trie[5*MAX][ALPHA];
vi vert[5*MAX];
int fn[5*MAX];

int node() {
  REP(i, ALPHA) trie[V][i] = 0;
  fn[V] = 0;
  vert[V].clear();
  return V++;
}

void insert(string &s , int num) {
  int t = 0;
  int n = (int)s.size();
  for (int i = 0 ; i < n ; ++i) {
    int c = s[i] - 'a';
    if (trie[t][c] == 0) trie[t][c] = node();
    t = trie[t][c];
  }
  vert[t].push_back(num);
}

void init_aho() {
  queue<int> Q;
  Q.push(0);

  while (!Q.empty()) {
    int t = Q.front(); Q.pop();

    REP(c, ALPHA) {
      int x = trie[t][c];
      if (x) {
        Q.push(x);

        if (t) {
          fn[x] = fn[t];
          while (fn[x] && trie[fn[x]][c] == 0) fn[x] = fn[fn[x]];
          if (trie[fn[x]][c]) fn[x] = trie[fn[x]][c];
          for(auto it : vert[fn[x]])
            vert[x].push_back(it);
        }
      }
    }
  }
}
string t;
int cnt[5*MAX];
//use global string t
void matching(){
    mem(cnt,0);
    int n = (int)t.size();
    int cur = 0;
    for(int i = 0 ; i < n ;++i){
        for(auto it : vert[cur])
            cnt[it]++;
        while(trie[cur][t[i]-'a'] == 0 && cur != 0)
            cur = fn[cur];
        if(trie[cur][t[i]-'a'])
            cur = trie[cur][t[i]-'a'];
    }
    for(auto it : vert[cur])
        cnt[it]++;
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);


    int tc;
    sc(tc);
    int cases = 0;
    while(tc--){
        int n;
        sc(n);
        t.clear();
        cin>>t;
        V = 0;
        int nothing = node();
        for(int i = 0 ; i < n;  ++i){
            string s;
            cin>>s;
            insert(s , i);
        }
        init_aho();
        matching();
        printf("Case %d:\n" , ++cases);
        for(int i = 0 ; i < n ; ++i)
            printf("%d\n" , cnt[i]);
    }




return 0;
}
