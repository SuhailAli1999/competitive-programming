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

int dx[] = {1,2,-1,2,1,-2,-1,-2};
int dy[] = {2,1,2,-1,-2,1,-2,-1};

const int N = 1000005;
int vis[N] = {0};
vector<int> adj[N];
vector<int> v;
int n, m;

bool dfs(int node){
    vis[node] = 2;
    for(auto ch : adj[node]){
        if(vis[ch] == 0){
            if(dfs(ch) == false) return false;
        }
        if(vis[ch] == 2){
            return false;
        }
    }
    vis[node] = 1;
    v.push_back(node);
    return true;
}

void solve(){

    while(cin >> n >> m){
        if(n==0 && m==0) return;

        v.clear();
        memset(vis, 0, sizeof(vis));
        for(int i=1; i<=n; i++){
            adj[i].clear();
        }

        for(int i=0; i<m; i++){
            int u, v;
            cin >> u >> v;
            adj[v].push_back(u);
        }

        bool f = 0;

        for(int i=1; i<=n; i++){
            if(vis[i] == 0){
                if(!dfs(i)){
                    cout << "IMPOSSIBLE" << endl;
                    f = 1;
                    break;
                }
            }
        }

        if(f) continue;

        for(auto it : v){
            cout << it << endl;
        }

    }

}
int main(){
    //freopen("consecutive_cuts_chapter_1_validation_input.txt", "r", stdin);
    //freopen("second_friend_output.txt", "w", stdout);
//    fast();
    int t = 1, tt = 1;
//    cin >> t ;
    while(t--){
//        cout << "CASE #" << tt++ << ":" << endl;
        solve();
    }
    return 0;
}
