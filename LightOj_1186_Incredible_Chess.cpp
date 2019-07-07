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
const int MAX = 200;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = acos(-1.0);
const double eps = 1e-7;

int a[MAX] , b[MAX];
vi piles;

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        piles.clear();
        int n;
        sc(n);
        for(int i = 0 ; i < n ; ++i)
            sc(a[i]);
        for(int i = 0 ; i < n ; ++i)
            sc(b[i]);
        for(int i = 0 ; i < n ; ++i)
            piles.pb(abs(a[i] - b[i]) - 1);
        int res = 0;
        for(int i = 0 ; i < (int)piles.size() ; ++i)
            res ^= piles[i];
        printf("Case %d: " , ++cases);
        if(!res)
            printf("black wins");
        else
            printf("white wins");
        blank;
    }



return 0;
}
