#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define endl "\n"
#define F first
#define S second


const int N = 200005;
vector<int> adj[N];
int vis[N] = {0};

// Undirected graph
// if cyclic return true else return false

bool isCyclic(int node, int p){
    vis[node] = 1;
    for(auto ch : adj[node]){
        if(vis[ch] == 1 && ch != p){
            return true;
        }
        else if(!vis[ch]){
            if(isCyclic(ch, node)) return true;
        }
    }
    return false;
}

// Directed graph
// if cyclic return true else return false
bool isCyclic(int node){
    vis[node] = 2;
    for(auto ch : adj[node]){
        if(vis[ch] == 0){
            if(isCyclic(ch) == true) return true;
        }
        if(vis[ch] == 2){
            return true;
        }
    }
    vis[node] = 1;
    return false;
}


void solve(){
    memset(vis, 0, sizeof(vis));
    for(int i=1; i<=n; i++){
          adj[i].clear();
      }

     for(int i=0; i<m; i++){
          int u, v;
          cin >> u >> v;
          adj[v].push_back(u);
       }
}

int main(){
    //freopen("consecutive_cuts_chapter_1_validation_input.txt", "r", stdin);
    //freopen("second_friend_output.txt", "w", stdout);
    fast();
    int t = 1;
    cin >> t ;
     while(t--){
        solve();
    }
    return 0;
}
