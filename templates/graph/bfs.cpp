#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define endl "\n"
#define F first
#define S second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(v) v.begin(), v.end()

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

const int N = 2005;
int lvl[N][N], p[N], in[N];

vector<int> adj[N];
int n,m,k;
vector<pair<int,int>> v;
vector<int> ans;



//Single source BFS with constructing path
void bfs(int src){
    queue<int> q;
    q.push(src);
    int level = 1;
//    lvl[src] = 1;

    while(level++ && !q.empty()){
        int sz = q.size();
        for(int i=0; i<sz; i++){
            int node = q.front();
            q.pop();
            for(auto ch : adj[node]){
                if(lvl[ch] != 0) continue;
                q.push(ch);
                p[ch] = node;
//                lvl[ch] = level;
            }
        }
    }
}

// BFS with multiple sources
void bfs(){
    queue<pair<int, int>> q;

    for(int i=0; i<v.size(); i++){
        q.push({v[i].F, v[i].S});
        lvl[v[i].F][v[i].S] = 1;
    }
    int level = 1;

    while(level++ && !q.empty()){
        int sz = q.size();
        for(int i=0; i<sz; i++){
            int curx = q.front().F, cury = q.front().S;
            q.pop();

            for(int i=0; i<4; i++){
                int x = curx + dx[i];
                int y = cury + dy[i];
                if(x<1 || x>n || y<1 || y>m || lvl[x][y] != 0){
                    continue;
                }
                else{
                    q.push({x,y});
                    lvl[x][y] = level;

                }
            }
        }
    }
}

// BFS topological sort
void topo(){
    queue<int> q;
    for(int i=1; i<=n; i++){
        if(in[i] == 0){
            q.push(i);
        }
    }
     while(!q.empty()){

        int node = q.front();
        ans.push_back(node);
        q.pop();
        for(auto ch : adj[node]){
            in[ch]--;
            if(in[ch] == 0){
                q.push(ch);
            }
        }
    }

    // check
    if(ans.size() != n){
        cout << "NO" << endl;
        return;
    }

    for(auto it : ans){
        cout << it << ' ';
    }
    cout << endl;
}




void solve(){

    while(cin >> n >> m){
        if(n == 0 && m == 0){
            return;
        }

        for(int i=0; i<N; i++){
            adj[i].clear();
        }
        ans.clear();

        for(int i=0; i<m; i++){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            in[v]++;
        }
        topo();
    }

}

int main(){
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
//    fast();
    int t = 1;
//    cin >> t;
     while(t--){
        solve();
    }
    return 0;
}
