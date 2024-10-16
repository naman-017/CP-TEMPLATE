#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll) (1e9+7)

 
//naman chawda - naman14nov

/*factors in format of (1*n, 2*n/2, ...)
TC-sqrt(n)                 */
void factors_simple(int n){
  for(int i=1; i*i<=n; i++){
    if(n%i==0)
      cout << i << " * " << (n/i) << endl;
  }
}

/*putting all the factors in a vector 
without repetition of elements in the vector, eg=16
TC-sqrt(n)                  */
void factors(ll n, vector<ll>&facts){
  for(int i=1; i*i<=n; i++){
    if(n%i==0){
      facts.push_back(i);
      if((n/i) != i){
        facts.push_back(n/i);
      }
    }
  }
}

/*prime factorisation-trial division method, 
returns a vector containing all the prime factors of 'n'
if in trial division method, u dont get any number in the vector 
then 'n' is prime number, just check for an empty vector
TC-sqrt(n)                              */
vector<int> pm_factors(int n){
  vector<int> facts;
  for(int i=2; i*i<=n; i++){
    while(n%i==0){
      facts.push_back(i);
      n/=i;
    }
  }
  if(n>1)
    facts.push_back(n);
  return facts;
}


/*if u just want to know all the distinct factors, 
eg = for 16 = {2}, 15 = {3, 5}           
TC-sqrt(n)                */
vector<int> factors_vec(int n){
  vector<int> facts;
  for(int i=2; i*i<=n; i++){
    if(n%i==0){
      facts.push_back(i);
      while(n%i==0){
        n/=i;
      }
    }
  }
  if(n>1)
    facts.push_back(n);
  return facts;
}


/*sieve of eratosthenes
a boolean vector with 1 or 0 value for index as numbers
TC - n*log(log n)                               */
void sieve(ll n, vector<bool> &primes){
  primes[0]=primes[1]=false;
  for(ll i=2; i*i<=n; i++){
    if(primes[i]){
      for(ll j=i*i; j<=n; j+=i){
        primes[j]=false;
      }
    }
  }
}
/*int main() 
{
  ll n;
  cin >> n;
  vector<bool> primes(n+1, true);
  sieve(n, primes);
  cout << primes[12] << endl;
  return 0;
}*/



/*get the smallest prime factor in the array for each element
just call this func and use the array spf
TC- n*log(log n)                           */
const int N = 1e7;
int spf[N];
void solve_spf(){
  for(int i=0; i<N; i++){
    spf[i]=i;
  }
  for(int i=2; i*i<=N; i++){
    if(spf[i]==i){
      for(int j=i*i; j<N; j+=i){
        if(spf[j]==j){
          spf[j]=i;
        }
      }
    }
  }
}



/*get the highest prime factor in the array for each element
just call this func and use the array hpf
TC- n*log n                           */
const int n_ = 1e7;
int hpf[n_];
void solve_hcf(){
  for(int i=0; i<n_; i++){
    hpf[i]=i;
  }
  for(int i=2; i<n_; i++){
    if(hpf[i]==i){
      for(int j=2*i; j<n_; j+=i){
        hpf[j]=i;
      }
    }
  }
}





/*this is getting factors of a number in LOG-N TC,
just one precomputation for spf array which will take nlog(logn)
int main()
{
    int n;
    cin >> n;
    solve_spf();
    vector<int> v;
    while(n>1){
        v.push_back(spf[n]);
        n=n/spf[n];
    }
    for(auto it: v)
        cout << it << " ";
    cout << endl;

    return 0;
}*/

//prime factors of X in O(log N) TC
//returns a vector with all its distinct prime factors
vector<ll> distinct_primes(ll x){
    vector<ll> v;
    while(x!=1){
        ll y=spf[x];
        while(x%y==0)
            x/=y;
        v.push_back(y);
    }
    return v;
}


//a to the power b with LOG-N TC using recursion
ll power_rec(ll a, ll b){
    if(b==0) return 1;
    if(b==1) return a;
    ll temp=power_rec(a, b/2);
    temp*=temp;
    temp%=mod;
    if(b&1){
        temp*=a;
        temp%=mod;
    }
    return temp;
}


//a to the power b with LOG-N TC using iteration
ll power_itr(ll a, ll b){
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



//https://www.youtube.com/watch?v=utZcJ0leZ_g
//gcd & lcm video link
/*gcd of two numbers-recursive- EUCLIDEAN ALGORITHM
TC - LOG(MIN(A, B))              */
ll gcd_rec(ll a, ll b){
    if(a==0) return b;
    return gcd_rec(b%a, a);
}

/*gcd of two numbers-iterative- EUCLIDEAN ALGORITHM
TC - LOG(MIN(A, B))              */
ll gcd_itr(ll a, ll b){
    while(a){
        ll t=a;
        a=b%a;
        b=t;
    }
    return b;
}


ll lcm__(ll a, ll b){
    ll ans = (a*b)/gcd_rec(a, b);
    return ans;
}

/*
lcm(a, b)=(a*b)/gcd(a, b);
*/

void lcm_of_n_numbers(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(auto &it: v) cin>>it;
    int temp=v[0];
    for(int i=1; i<n; i++){
        temp=(temp*v[i])/gcd_rec(temp, v[i]);
    }
    cout << temp << endl;
}

/*
x = gcd(a, b, c)
y = gcd(a, b, c, d)
gcd can either remain same or equal once we start adding numbers
x >= y
*/


/*
minimum fraction of (a/b)
a/b = (a/gcd(a, b))/(b/gcd(a, b))
*/


/* if you want to use sieve algo in main()

const int Na=1e6;
bool primes[Na+1];

int main() {
    memset(primes, true, sizeof(primes));
    for(ll i=2; i*i<=Na; i++){
      if(primes[i]){
        for(ll j=i*i; j<=Na; j+=i){
          primes[j]=false;
        }
      }
    }
}

use the primes array*/


/*int main() {
    solve_spf();
    int cnt=0;
    int x=18;
    int numdiv=1;
    int sum=0;
    while(x!=1){
        int smallestprm=spf[x], cnt=0;
        while(x%smallestprm==0){
            x/=spf[x];
            cnt++;
        }
        //numdiv*=(cnt+1);
        cout << smallestprm << "^" << cnt << endl;
    }
    //this will give number of divisors of N including N and 1
    //cout << numdiv << endl;
}*/


//this will only keep the unique elements in the vector
//(v).erase(unique(v.begin(), v.end()), v.end());



ll euler_totient_func(ll n){
    ll result=n;
    for(int i=2; i*i<=n; i++){
        if(n%i==0){
            while(n%i==0)
                n/=i;
            result-=result/i;
        }
    }
    if(n>1)
        result-=result/n;
    return result;
}


// euler func values for each num from 1 to n
void phi_1_to_n(int n) {
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++)
        phi[i] = i;

    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= n; j += i)
                phi[j] -= phi[j] / i;
        }
    }
}




#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll) (1e9+7)



void solve(){
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(auto &it: v) cin>>it;

    sort(v.begin(), v.end());
    ll cnt=0;
    ll l=-1, r=-1;
    for(int i=0; i<n-1; i++){
        ll x=v[i], y=v[i+1];
        
        ll start=(y+1)-x;
        ll ed=(x+y)-1;
        cout << start << " " << ed << endl;

        if(l==-1 && r==-1){
            cnt+=(ed-start+1);
            l=start, r=ed;
        }
        
        if(start<l){
            cnt+=((l-1)-start+1);
            l=start;   
        }
        if(ed>r){
            cnt+=(ed-(r+1)+1);
            r=ed;
        }
        
    }
    cout << cnt << endl;

    
}

int main()
{
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
}
