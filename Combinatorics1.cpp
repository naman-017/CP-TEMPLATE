#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define lld long double
const ll mod=1e9+7;
const ll N = 1e6;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll mod_add(ll a, ll b, ll mod) {a = a % mod; b = b % mod; return (((a + b) % mod) + mod) % mod;}
ll mod_mul(ll a, ll b, ll mod) {a = a % mod; b = b % mod; return (((a * b) % mod) + mod) % mod;}
ll mod_sub(ll a, ll b, ll mod) {a = a % mod; b = b % mod; return (((a - b) % mod) + mod) % mod;}
//ll mod_div(ll a, ll b, ll mod) {a = a % mod; b = b % mod; return (mod_mul(a, mminvprime(b, mod), mod+ mod) % mod;}


//BoilerPlate template
ll modx(ll a, ll m = mod) {
    return a % m;
}
template <class T> class Math {
  public:
    vector<T> fact, invfact;
    Math() {}
    Math(ll n) {
        fact.resize(n);
        invfact.resize(n);
        fact[0] = invfact[0] = 1;
        for (ll i = 1; i < n; i++) {
            fact[i] = modx(i * fact[i - 1]);
            invfact[i] = modinv(fact[i]);
        }
    }
    T modinv(T x, T m = mod) { return expo(x, m - 2, m); }
    T expo(T base, T exp, T m = mod) {
        T res = 1;
        while (exp) {
            if (exp & 1)
                res = modx(res * base, m);
            base = modx(base * base, m);
            exp >>= 1;
        }
        return res;
    }
    T choose(T n, T k) {
        if (k < 0 || k > n)
            return 0;
        T ans = fact[n];
        ans = modx(ans * invfact[n - k]);
        ans = modx(ans * invfact[k]);
        return ans;
    }
};


//a to the power b with LOG-N TC using recursion
ll binary_expo1(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    ll temp=binary_expo1(a, b/2);
    temp*=temp;
    temp%=mod;
    if(b&1){
        temp*=a;
        temp%=mod;
    }
    return temp;
}


//a to the power b with LOG-N TC using iteration
ll binary_expo2(ll a, ll b){
    ll result=1;
    while(b>0){
        if(b&1){
            result*=a;
            result%=mod;
        }
        a*=a;
        a%=mod;
        b=(b>>1);
    }
    return result;
}


ll fact_brute(ll n) {
    ll sa = 1;
    for (int i = 1; i <= n; i++) {
        sa = mod_mul(sa, i, mod);
    }
    return sa;
}


ll n=1e6;
vector<ll> fact(n+1);
vector<ll> invfact(n+1);
//precomputation takes O(n) time complexity
void solve_factorial(){
	fact[0]=1;
	for(ll i=1; i<=n; i++){
		fact[i]=mod_mul(fact[i-1], i, mod);
	}
	invfact[n]=binary_expo1(fact[n], mod-2);
	for(ll i=n-1; i>=0; i--){
		invfact[i]=mod_mul(invfact[i+1], i+1, mod);
	}
}

ll combination1(ll n, ll r, vector<ll>&fact, vector<ll>&invfact){
    return mod_mul(fact[n], mod_mul(invfact[r], invfact[n-r], mod), mod);
}

ll combination2(ll n, ll r) {
  return mod_mul(fact_brute(n), binary_expo1(mod_mul(fact_brute(r), fact_brute(n - r), mod), mod - 2), mod);
}

/*
1/(n-1)! = n/n!
nCr = nCn-r
nCr = (n-1Cr-1)*(n-1Cr)
n summation k=0_to_n = 2^i
2^0 + 2^1 + 2^2 + ... + 2^n = 2^(n+1) - 1
Math<ll>m(N);
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll) (1e9+7)


void solve(){
    ll n;
    cin >> n;
    vector<ll>v(n);
    for(auto &it: v) cin>>it;

    vector<ll> ans;
    ans.push_back(1e9);
    ll sum=0;
    for(int i=1; i<n; i++){
        ll x=v[i]-sum;
        sum+=x;
        ans.push_back(x);
    }
    for(auto it: ans)
        cout << it << " ";
    cout << endl;

}

int main() {
    ll t;
    cin >> t;
    while(t--){
        solve();    
    }
    return 0;
}
