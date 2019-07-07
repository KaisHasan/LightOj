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
#define sc(a) scanf("%d",&a)
#define scl(a) scanf("%lld",&a)
#define scd(a) scanf("%lf" , &a)
#define sch(a) scanf("%c" , &a)
#define blank printf("\n")
#define pla printf("plapla\n")
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 1e-7;

int n, m;
int a[MAX];


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);
    int t;
    sc(t);
    for(int cases = 1 ; cases <= t ; ++cases){
        sc(n);sc(m);
        for(int i =  0; i < n ; ++i)
            sc(a[i]);
        int st = 0 , en = 2 * 1e9;
        int res = 0;
        while(st <= en){
            int md = (st+en)>>1;
            if(check(md)){
                en = md - 1;
                res = md;
            }
            else{
                st = md + 1;
            }
        }
        printf("%d" , res);
        if(cases != t)
            blank;
    }




return 0;
}
