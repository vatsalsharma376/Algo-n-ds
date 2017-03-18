//Fenwick Tree 18317
 

#include <bits/stdc++.h>

#define pb(x) push_back(x);
#define in(y) insert(y);
#define tt(t) while(t--)
#define itr ::iterator it;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define si set<int>                      
#define msi map<string, int>
#define new cout<<endl
#define ff(n) for(int i=0;i<n;i++)
#define all(v) sort(v.begin(),v.end())
#define LstBit(i) ((i)&(-i))
using namespace std;
int n;
vector<int> arr,bit;
int sum(int i){
	++i;
	int ret=0;
	while(i>0){
		ret+=bit[i];
		i-=LstBit(i);
	}
	return ret;
}
int sumr(int a,int b){
	return sum(b)-sum(a-1);
}
void update(int i,int val){
	++i;
	while(i<=n){
		bit[i]+=val;
		i+=LstBit(i);
	}
}
void make_bit(){
	ff(n) update(i,arr[i]);
}
int main(){
    cin>>n;	//Elements
    arr.resize(n);
    bit.resize(n+1,0);
    ff(n) cin>>arr[i];
    make_bit();
    int m;	// Queries
    cin>>m; // Type 1- Sum[a,b] Type 2- Update[a]+=b;
    
    while(m--){
    	int ty;
    	int a,b;
    	cin>>ty>>a>>b;
    	--a;  
    	if(ty==1){
    		--b;
    		cout<<sumr(a,b)<<"\n";
    	}
    	else{
    		update(a,b);
    	}
    }
    return 0;
}
/*
Sample input
3
1 2 3
5
1 1 3
1 2 3
2 3 1
1 3 3
1 1 3

Sample output 
6
5
4
7
*/

