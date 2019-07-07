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

ll SIZE;
bitset<20000010> isprime;
vi primes;
void seive(ll n){
    SIZE = n + 1;
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for(ll i = 2 ; i <= SIZE ; ++i){
        if(isprime[i]){
            for(ll j = i * i ; j <= SIZE ; j += i)
                isprime[j] = 0;
            primes.pb((int)i);
        }
    }
}
bool is_prime(ll n){
    if(n <= SIZE)
        return isprime[n];
    int id = 0;
    ll p = primes[0];
    while(p * p <= n){
        if(n % p == 0)
            return 0;
        p = primes[++id];
    }
    return 1;
}
vector<ll> v;
void GenerateDivisors(ll n){
    ll i;
    v.clear();
    for( i = 2 ; i * i < n ; ++i){
        if(n%i == 0){
            if(is_prime(i))
                v.push_back(i);
            if(is_prime(n/i))
                v.push_back(n/i);
        }
    }
    if(i * i == n && is_prime(i))
        v.push_back(i);
}
int dis[2000];

int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    seive(2000);
    int t;
    sc(t);
    int cases = 0;
    while(t--){
        int x,y;
        sc(x);sc(y);
        queue<int> q;
        mem(dis , -1);
        dis[x] = 0;
        q.push(x);
        while(!q.empty()){
            int u = q.front();
            q.pop();
            if(u == y){
                break;
            }
            GenerateDivisors(u);
            for(auto i : v){
                int nx = u + i;
                if(nx > y)
                    continue;
                if(dis[nx] == -1){
                    dis[nx] = dis[u] + 1;
                    q.push(nx);
                }
            }
        }
        printf("Case %d: %d\n" , ++cases , dis[y]);
    }



return 0;
}
