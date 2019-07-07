#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef pair<double , double> pdd;
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
const double eps = 1e-8;

pdd A , B , C , D;
double f(double t){
    double x1 = A.first + (B.first - A.first)*t;
    double y1 = A.second + (B.second - A.second)*t;
    double x2 = C.first + (D.first - C.first)*t;
    double y2 = C.second + (D.second - C.second)*t;

    return hypot(x1 - x2 , y1 - y2);
}


int main(){

int t;
sc(t);
int cases = 0;
    while(t--){
        cin>>A.first>>A.second;
        cin>>B.first>>B.second;
        cin>>C.first>>C.second;
        cin>>D.first>>D.second;
        printf("Case %d: " , ++cases);
        double l = 0 , r = 1;
        while(r - l > eps){
            double m1 = l + (r-l)/3;
            double m2 = r - (r-l)/3;
            double f1 = f(m1);
            double f2 = f(m2);
            if(f1 - f2 > eps)
                l = m1;
            else
                r = m2;
        }
        cout<<setprecision(6)<<fixed<<f(l)<<endl;
    }

return 0;
}
