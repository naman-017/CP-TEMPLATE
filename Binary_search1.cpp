#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll) (1e9+7)

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
  
#define ordered_set tree<pair<int, int>, null_type,less<pair<int, int>>, rb_tree_tag,tree_order_statistics_node_update> 
/*mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 
*/

// TC-LOG(N)
int binary_search1(vector<int> &v, int to_find){
    int n=v.size();
    int lo=0, hi=n-1, mid;
    while(hi-lo > 1){
        mid=(hi+lo)/2;
        if(v[mid]<to_find){
            lo=mid+1;
        }
        else{
            hi=mid;
        }
    }
    if(v[lo]==to_find)
        cout << lo << endl;
    else if(v[hi]==to_find)
        cout << hi << endl;
    else
        cout << "not found!" << endl;
}


int lower_bound1(vector<int> &v, int to_find){
    int n=v.size();
    int lo=0, hi=n-1;
    int mid;
    while(hi-lo>1){
        mid=(lo+hi)/2;
        if(v[mid]<to_find)
            lo=mid+1;
        else
            hi=mid;
    }
    if(v[lo]>=to_find)
        return lo;
    if(v[hi]>=to_find)
        return hi;
    return -1;
}

int upper_bound1(vector<int> &v, int to_find){
    int n=v.size();
    int lo=0, hi=n-1;
    int mid;
    while(hi-lo>1){
        mid=(lo+hi)/2;
        if(v[mid]<=to_find)
            lo=mid+1;
        else
            hi=mid;
    }
    //cout << v[lo] << " " << v[hi] << endl;
    if(v[lo]>to_find)
        return lo;
    if(v[hi]>to_find)
        return hi;
    return n;
}

double eps=1e-6;
double mul(double mid, int n){
    double y=1;
    for(int i=0; i<n; i++)
        y*=mid;
    return y;
}
int nth_root(double x, int n){
    double lo=1, hi=x;
    double mid;
    while(hi-lo > eps){
        mid=(hi+lo)/2;
        if(mul(mid, n) < x)
            lo=mid;
        else
            hi=mid;
    }
    cout << mid << endl;
    //cout << setprecision(10) << mid << endl;
    //cout << pow(x, 1.0/2);
}


pair<ll, ll> intersection(pair<ll, ll> a, pair<ll, ll> b){
    return make_pair(max(a.first, b.first), min(a.second, b.second));
}

pair<double, double> intersection_double(pair<double, double> a, pair<double, double> b){
    return make_pair(max(a.first, b.first), min(a.second, b.second));
}







/*#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll) (1e9+7)*/


int main()
{
    vector<ll> teachers={1, 4, 7, 8, 12};
    ll lower=--lower_bound(teachers.begin(), teachers.end(), 2)-teachers.begin()+1;
    ll upper=upper_bound(teachers.begin(), teachers.end(), 2)-teachers.begin()+1;
    cout << lower << " " << upper << endl;
    


}




