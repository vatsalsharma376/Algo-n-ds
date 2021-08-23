#include <bits/stdc++.h>
using namespace std;
#define int         long long int 
#define pb(x)       push_back(x);
#define in(y)       insert(y);
#define tt(t)       while(t--)
#define ff(n)       for(int i=0;i<n;i++)
#define fors(i,a,b) for(int i=a;i<b;i++)
#define all(v)      v.begin(),v.end()
#define ii          pair<int,int>
#define sz(v)       (int)v.size()

#define IOS         ios_base::sync_with_stdio(0), cin.tie(0);
#define nl          cout<<"\n"
#define MOD         1000000007
// -- FUNCTIONS START ----
int power(int x,int y){
	int ans = 1;
	while(y--) ans*=x;
	return ans;
}
int logg2(int x){
	return log2((long double)x);	
}

// -- FUNCTIONS END  -----

std::vector<int> arr;
int n;
void merge(int l,int mid,int r){
	int n1 = mid-l+1;
	int n2 = r-mid;  
	int a[n1];
	int b[n2];
	ff(n1) a[i]=arr[l+i];
	ff(n2) b[i]=arr[mid+1+i];

	int x = 0;
	int y = 0;
	while(x<n1 and y<n2){
		if(a[x]<b[y]){
			arr[l++]=a[x++];
		}
		else{
			arr[l++]=b[y++];
		}
	}
	while(x<n1){
		arr[l++]=a[x++];
	}
	while(y<n2){
		arr[l++]=b[y++];
	}
}
void mergesort(int l,int r){
	if(l<r){
		int mid = (l+r)/2;
		mergesort(l,mid);
		mergesort(mid+1,r);
		merge(l,mid,r);
	}
}
signed main()
{
    IOS;
    cin>>n;
    arr.resize(n);
    ff(n){
    	cin>>arr[i];
    }
    mergesort(0,n-1);
    ff(n) cout<<arr[i]<<" ";
}

