#include<bits/stdc++.h>

using namespace std;
typedef pair<int , int> pi;
typedef pair<double , int > dpi;
typedef long long ll;
typedef unsigned long long ull;
#define sc(a) scanf("%d",&a)
#define scd(a) scanf("%lf" , &a)
#define pb push_back
const int MAX = 1e5+55;
const int inf = 1e9+77;
const int MOD = 1e9+7;
const double PI = 3.14159265359;
const double eps = 0.0000001;

int dx[] = {1 , -1 , 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
int vis[200][200];
char grid[100][100];
int n ,m ;
bool valid(int x , int y){
    return x >= 0 && y >= 0 && x < n && y < m && !vis[x][y] && grid[x][y] == '.';
}

int main(){

    int t;
    sc(t);
    for(int o = 1; o <= t ; ++o){
        memset(vis , 0 , sizeof(vis));
        sc(m);
        sc(n);

        int xloc , yloc;
        for(int i = 0; i < n ; ++i){
            string s;
            cin>>s;
            for(int j = 0 ; j < m ; ++j){
                grid[i][j] = s[j];
                if(grid[i][j] == '@'){
                    xloc = i;
                    yloc = j;
                }
            }
        }
        queue<pi> q;
        int res  = 0;
        q.push({xloc , yloc});
        while(!q.empty()){
            ++res;
            pi v = q.front();
            q.pop();
            for(int i = 0 ; i < 4 ; ++i){
                int nx = v.first + dx[i];
                int ny = v.second + dy[i];
                if(valid(nx , ny)){
                    vis[nx][ny] = 1;
                    q.push({nx , ny});
                }
            }
        }
        printf("Case %d: %d\n" , o , res);

    }




return 0;
}
