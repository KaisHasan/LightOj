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
#define sc(a) scanf(" %d ",&a)
#define scl(a) scanf(" %lld ",&a)
#define scd(a) scanf(" %lf " , &a)
#define sch(a) scanf(" %c " , &a)
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

int convert(char c){
    if(isupper(c))
        return c - 'A' + 26;
    return c - 'a';
}

#define MN  55
#define MS 100001

struct trie{
  struct node{
    int c;
    int a[MN];
  };

  node tree[MS];
  void clear(){
    tree[nodes].c = 0;
    memset(tree[nodes].a, -1, sizeof tree[nodes].a);
    nodes++;
  }

  int nodes;

  void init(){
    nodes = 0;
    clear();
  }

  int add(const string &s, bool query = 0){
    int cur_node = 0;
    for(int i = 0; i < s.size(); ++i){
      int id = convert(s[i]);
      if(tree[cur_node].a[id] == -1){
        if(query) return 0;
        tree[cur_node].a[id] = nodes;
        clear();
      }
      cur_node = tree[cur_node].a[id];
    }
    if(!query) tree[cur_node].c++;
    return tree[cur_node].c;
  }

};

trie tree;


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        int n;
        sc(n);
        string s;
        tree.init();
        for(int i = 0 ; i < n ; ++i){
            getline(cin , s);
            if((int)s.size() > 2)
                sort(s.begin() + 1 , s.end()-1);
            tree.add(s);
        }
        int k;
        sc(k);
        printf("Case %d:\n" , ++cases);
        while(k--){
            string temp;
            getline(cin , temp);
            int res = 1;
            stringstream iss(temp);
            string f;
            while(iss>>f){
                if((int)f.size() > 2)
                    sort(f.begin() + 1 , f.end()-1);
                res *= tree.add(f , 1);
            }
            printf("%d\n" , res);
        }
        tree.clear();
    }




return 0;
}
