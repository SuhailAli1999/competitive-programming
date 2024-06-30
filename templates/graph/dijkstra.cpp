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

int dx[] = {0, -1, 1};
int dy[] = {1, 0, 0};
const int N = 100;
const ll mod = 1e9+7;
int vis[N];
int dist[N];
int p[N];
int n, m;
vector<pair<int,int>> adj[N];

vector<int> get_path(int src, int node){
    vector<int> path;
    while(node != src){
        path.push_back(node);
        node = p[node];
    }
    path.push_back(node);
    reverse(all(path));
    return path;
}

// dijkstra single source shortest paths problem  O(n^2)
void dijkstraaa(int src){
    dist[src] = 0;
    for(int i=0; i<n; i++){
        int mnCost = 1e9, mnNode = 0;
        for(int u=0; u<n; u++){
            if(vis[u]) continue;
            if(dist[u] < mnCost){
               mnNode = u;
               mnCost = dist[u];
            }
        }
        vis[mnNode] = 1;
        for(auto [ch,c] : adj[mnNode]){
            int newCost = dist[mnNode] + c;
            if(newCost < dist[ch]){ // Relaxation
                dist[ch] = newCost;
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << i << " " << dist[i] << endl;
    }
}


// dijkstra single source shortest paths problem priority_queue O(n log(n))
void dijkstraa(int src){
    priority_queue<pair<int, int>, vector<pair<int,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while(!pq.empty()){

        auto [mnCost, mnNode] = pq.top();
        pq.pop();

        if(dist[mnNode] < mnCost) continue;

        for(auto [ch,c] : adj[mnNode]){
            int newCost = dist[mnNode] + c;
            if(newCost < dist[ch]){ // Relaxation
                dist[ch] = newCost;
                p[ch] = mnNode;
                pq.push({newCost, ch});
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << i << " " << dist[i] << endl;
    }
}

// dijkstra single source shortest paths problem set O(n log(n))
void dijkstra(int src){
    set<pair<int, int>> st;
    dist[src] = 0;
    st.insert({0, src});
    while(!st.empty()){

        auto [mnCost, mnNode] = *st.begin();
        st.erase(st.begin());

        for(auto [ch,c] : adj[mnNode]){
            int newCost = dist[mnNode] + c;
            if(newCost < dist[ch]){ // Relaxation
                st.erase({dist[ch], ch});
                dist[ch] = newCost;
                p[ch] = mnNode;
                st.insert({newCost, ch});
            }
        }
    }

    for(int i=0; i<n; i++){
        cout << i << " " << dist[i] << endl;
    }
}

void solve(){
    cin >> n >> m;

    for(int i=0; i<m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    int src;
    cin >> src;
    memset(dist, '?', sizeof dist);
    dijkstra(src);

}


int main(){
//   #ifndef ONLINE_JUDEGE
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
//   #endif
    fast();
    int t = 1;
    cin >> t ;
    while(t--){
        solve();
    }
    return 0;
}
