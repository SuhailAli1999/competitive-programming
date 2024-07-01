#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>; // order_of_key (), find_by_order()
typedef long long ll;
typedef long double ld;

#define endl "\n";
#define F first
#define S second
#define getunique(v) {sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end());}
#define all(v) v.begin(), v.end()

void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
}

// custom sort in priority queue
struct cmp1 {
    bool operator()(pair<int, int> const& a, pair<int, int> const& b){
        if(a.first == b.first){
            return a.second > b.second;
        }
        else {
            return a.first < b.first;
        }
    }
};

ll fix_mod(ll a, ll b){
    return (a % b + b) % b;
}

bool is_perfect_square(long double x){
    if (x >= 0) {
        long long sr = sqrt(x);
        return (sr * sr == x);
    }
    return false;
}

vector<int> get_divisors(int n){ // o(sqrt(n)) //factoring
    vector<int> ans;
    for(int i=1; i*i<= n; i++){
        if(n%i==0){
            ans.push_back(i);
            if(i*i != n){
                ans.push_back(n/i);
            }
        }
    }
    return ans;
}

vector<int> get_multiples(int x, int n){
    vector<int> ans;
    for(int m=x; m<=n; m+=x){
        ans.push_back(m);
    }
    return ans;
}

bool is_prime(int n){ // o(sqrt(n))
    if(n==1) return false;
    for(int p=2; p*p <= n; p++){
        if(n%p==0){
            return false;
        }
    }
    return true;
}

void sieve(int isPrime[], int N){ // o(n) -- o(n log(log(n)))
    fill(isPrime, isPrime+N, true);
    isPrime[0] = isPrime[1] = false;
    for(int p=2; p*p<N; p++){
        if (isPrime[p] == 1){
            for(int m = p*p; m<N; m+=p){
                isPrime[m] = false;
            }
        }
    }
}

void prime_factorization_sieve(vector<int> isPrime[], int N){ // o(n) -- o(n log(log(n)))
    for(int p=2; p<N; p++){
        if (isPrime[p].empty()){
            for(int m=p; m<N; m+=p){
                isPrime[m].push_back(p);
            }
        }
    }
}

vector<ll> prime_factorization(ll n){ //o(sqrt(n))
    vector<ll> ans;
    for (int p=2; p*p<=n; p++){
        while(n%p == 0){
            n/=p;
            ans.push_back(p);
        }
    }
    if(n!=1){
        ans.push_back(n);
    }

    return ans;
}

ll factorial(ll n){ // n! ---> o(n)
    vector<ll> v(n+1);
    v[0] = 1;
    for(int i=1; i<=n; i++){
        v[i] = v[i-1] * i;
    }
    return v[n];
}

/////////////////////////////////////// ncr_npr
ll mul(ll a, ll b) {
    return ((a % mod) * (b % mod)) % mod;
}

ll add(ll a, ll b) {
    a = (a + mod) % mod;
    b = (b + mod) % mod;
    return (a + b) % mod;
}

ll fastPower(ll base, ll power){
    if(power == 0) return 1;
    ll res = fastPower(base, power/2) % mod;
    if(power%2){
        return mul(res, res) * base;
    }
    else{
        return mul(res, res);
    }
}

ll modInv(ll n) {
    return fastPower(n, mod - 2);
}

ll fact[N+1], inv[N+1];

void precomputeFactorials(){
    fact[0] = 1;
    inv[0] = 1;

    for (int i = 1; i <= N; i++) {
        fact[i] = mul(fact[i - 1] , i) % mod;
        inv[i] = fastPower(fact[i], mod - 2);
    }
}

ll nCr(ll n, ll r) {
    return mul(mul(fact[n] , inv[r]), inv[n - r]);
}

ll nPr(ll n, ll r) {
    return mul(fact[n] , inv[n - r]);
}

///////////////////////////////////////////

// Function to calculate the sum of a geometric series mod

long long geometricSum(ll base, ll n, ll mod) {
    if (n == 0) return 1;
    if (base == 1) return n % mod;  // Special case when base is 1

    ll numerator = (fastPower(base, n) - 1 + mod) % mod;
    ll denominator = (base - 1 + mod) % mod;

    // Using Fermat's Little Theorem to find modular inverse of the denominator
    ll denominator_inv = fastPower(denominator, mod - 2);

    return (numerator * denominator_inv) % mod;
}

//complete search
void complete_search (int n){
    for(int mask=0; mask <(1<<n); mask++){
        for(int i=0; i<n; i++){
            if(((mask>>i)&1)){ // isOn
                cout << 1 << " ";
            }
            else{
                cout << 0 << " ";
            }
        }
        cout << endl;
    }
}
//all permission using backtracking
void bt(int i, vector<int> v, int vis[], int n){
    if(v.size() == n){

        for(auto it : v){
            cout << it << " ";
        }
        cout << endl;
    }

    for(int j=1; j<=n; j++){
        if(!vis[j]){
            vis[j] = 1;
            v.push_back(j);
            bt(i+1, v, vis, n);
            vis[j] = 0;
            v.pop_back();
        }
    }
}

void solve(){

}

int main(){
    //freopen("consecutive_cuts_chapter_1_validation_input.txt", "r", stdin);
    //freopen("second_friend_output.txt", "w", stdout);
    fast();
    int t = 1;
//    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}
