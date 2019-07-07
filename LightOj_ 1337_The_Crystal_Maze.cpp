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

int n , m;
char grid[505][505];
int dx[] = {0 , 0 , 1 , -1};
int dy[]= {1 , -1 , 0 , 0};
int vis[505][505] , cmp[505][505] , cnt[MAX];
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m && vis[x][y] == 0 && grid[x][y] != '#';
}
int num;
void dfs(int x , int y){
    vis[x][y] = 1;
    cmp[x][y] = num;
    if(grid[x][y] != '.')
        cnt[num]++;
    for(int i = 0 ; i < 4 ; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(valid(nx,ny))
            dfs(nx,ny);
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        sc(n);sc(m);
        int q;
        sc(q);
        mem(cnt,0);
        mem(vis,0);
        mem(cmp,0);
        num = 0;
        for(int i = 0 ;i < n ; ++i){
            string s;
            cin>>s;
            for(int j = 0; j < m ; ++j)
                grid[i][j] = s[j];
        }
        for(int i = 0 ; i < n ; ++i){
            for(int j = 0 ; j < m ; ++j){
                if(valid(i,j)){
                    ++num;
                    dfs(i,j);
                }
            }
        }
        printf("Case %d:\n" , ++cases);
        while(q--){
            int x , y;
            sc(x);sc(y);
            --x;--y;
            printf("%d\n" , cnt[cmp[x][y]]);
        }
    }



return 0;
}
