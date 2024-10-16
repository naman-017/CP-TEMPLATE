#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mod (ll) (1e9+7)
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll getRandomNumber(ll l, ll r) {return uniform_int_distribution<ll>(l, r)(rng);} 


//find the max sum out of all the subarrays in O(n)
int find_max_subarr_sum(vector<int> &v, int sub_arr_len){
	int n=v.size();
	int sum=0;
    for(int i=0; i<sub_arr_len; i++)
    	sum+=v[i];
    int maxi=sum;
    for(int i=sub_arr_len; i<n; i++){
    	sum+=v[i];
    	sum-=v[i-sub_arr_len];
    	maxi=max(maxi, sum);
    }
    return maxi;
}

//find number of unique elements in each subarr
void unique_elm_subarr(vector<int> &v, int sub_arr_len){
	int n=v.size();
	map<int, int> m;
	for(int i=0; i<sub_arr_len; i++){
		m[v[i]]++;
	}
	cout << m.size() << " ";
	for(int i=sub_arr_len; i<n; i++){
		m[v[i-sub_arr_len]]--;
		if(m[v[i-sub_arr_len]]==0)
			m.erase(v[i-sub_arr_len]);
		m[v[i]]++;
		cout << m.size() << " ";
	}
	cout << endl;
}

//print the first negative elm in each subarr of size k
void first_neg_elm_in_each_subarr(vector<int> &v, int sub_arr_len){
	int n=v.size();
	queue<int> q;
	for(int i=0; i<sub_arr_len; i++){
		if(v[i]<0)
			q.push(i);
	}
	cout << v[q.front()] << " ";
	for(int i=0; i<n-sub_arr_len; i++){
		if(q.front()==i)
			q.pop();
		if(v[i+sub_arr_len]<0)
			q.push(i+sub_arr_len);
		cout << v[q.front()] << " ";
	}
	cout << endl;
}


void max_subrr_sum_unique_elm_subarr(vector<int> &v, int sub_arr_len){
	int n=v.size();
	map<int, int> m;
	int maxi=0;
	int sum=0;
	for(int i=0; i<sub_arr_len; i++){
		m[v[i]]++;
		sum+=v[i];
	}
	if(m.size()==sub_arr_len)
		maxi=sum;
	for(int i=0; i<n-sub_arr_len; i++){
		
		m[v[i]]--;
		if(m[v[i]]==0)	
			m.erase(v[i]);
		sum-=v[i];
		
		m[v[i+sub_arr_len]]++;
		sum+=v[i+sub_arr_len];

		if(m.size()==sub_arr_len){
			maxi=max(maxi, sum);
		}
	}
	cout << maxi << endl;

}

void sliding_window_minimum(vector<int> &v, int sub_arr_len){
	int n=v.size();
	deque<int> dq;
	vector<int> ans;
	for(int i=0; i<n; i++){

		while(!dq.empty() && v[dq.back()]>=v[i])
			dq.pop_back();
		dq.push_back(i);

		if(dq.front()==i-sub_arr_len){
			dq.pop_front();
		}

		if(i >= (sub_arr_len-1)){
			ans.push_back(v[dq.front()]);
		}
	}
	for(auto it: ans)
		cout << it << " ";
	cout << endl;
}


void sliding_window_maximum(vector<int> &v, int k){
	int n=v.size();
	deque<int> dq;
	vector<int> ans;
	for(int i=0; i<n; i++){

		while(!dq.empty() && v[dq.front()]<=v[i])
			dq.pop_front();
		dq.push_back(i);

		if(dq.back()==i-k){
			dq.pop_back();
		}

		if(i >= (k-1)){
			ans.push_back(v[dq.front()]);
		}
	}
	for(auto it: ans)
		cout << it << " ";
	cout << endl;
}

int main()
{
	int n, k;
	cin >>n>>k;
	vector<int> v(n);
	for(auto &it: v){
		cin >> it;
	}
	sliding_window_maximum(v, k);







	return 0;
}