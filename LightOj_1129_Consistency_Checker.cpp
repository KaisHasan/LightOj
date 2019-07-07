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

struct node{
    bool isword;
    node* child[15];
    node(){
        isword = 0;
        memset(child , 0 , sizeof(child));

    }
}*head;
bool test;
bool t2;
void _insert(string &s){
    node* it = head;
    for(int i = 0 ; i < s.size() ; ++i){
        int let = s[i] - '0';
        if(!it->child[let]){
            it->child[let] = new node();
            t2 = false;
        }
        if(it->isword)
            test = true;
        it = it->child[let];
    }
it->isword = 1;
}
//19 1

void _clear(node * it){
    for(int i = 0  ; i < 13 ; ++i){
        if(it->child[i])
            _clear(it->child[i]);
        delete it->child[i];
    }
}


int main(){
//freopen("output.txt" , "w" , stdout);
//freopen("input.txt" , "r" , stdin);

    int t;
    sc(t);
    int cases = 0;
    while(t--){
        head = new node();
        test = false;
        int n;
        sc(n);
        while(n--){
            string s;
            cin>>s;
            t2 = true;
            _insert(s);
            if(t2)
                test = true;
        }
        printf("Case %d: " , ++cases);
        if(!test)
            printf("YES");
        else
            printf("NO");
        blank;
        _clear(head);
    }




return 0;
}
