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

char grid[100][100];
int dx[] = {1 , -1, 0 , 0};
int dy[] = {0 , 0 , 1 , -1};
int vis[100][100];
int dis[100][100];
bool valid(int x , int y){
    return grid[x][y] != '#' && grid[x][y] != 'm' && !vis[x][y];
}
pi h;

int BFS(int x , int y){
    memset(vis , 0 , sizeof(vis));
    memset(dis , 0 , sizeof(dis));
    queue<pi> q;
    q.push({x , y});
    vis[x][y] = 1;
    while(!q.empty()){
        pi v = q.front();
        q.pop();
        for(int i = 0 ; i < 4 ; ++i){
            int nx = v.first + dx[i];
            int ny = v.second + dy[i];
            if(valid(nx , ny)){
                vis[nx][ny] = 1;
                dis[nx][ny] = dis[v.first][v.second] + 1;
                if(nx == h.first && ny == h.second){
                    return dis[nx][ny];
                }
                q.push({nx,ny});
            }
        }
    }
}

int main(){

    int t;
    sc(t);
    for(int o = 1; o <= t ; ++o){
        int n , m;
        pi a , b , c;
        sc(n);
        sc(m);
        for(int i = 0 ; i < n ; ++i){
            string s ;
            cin>>s;
            for(int j = 0; j < m ; ++j){
                grid[i][j] = s[j];
                switch(grid[i][j]){
                    case 'a': a.first = i;a.second = j;break;
                    case 'b': b.first = i;b.second = j;break;
                    case 'c': c.first = i;c.second = j;break;
                    case 'h': h.first = i;h.second = j;break;
                }
            }
        }
    int res = max(BFS(a.first , a.second) , max(BFS(b.first , b.second) , BFS(c.first , c.second)));
    printf("Case %d: %d\n" , o , res);
    }




return 0;
}
