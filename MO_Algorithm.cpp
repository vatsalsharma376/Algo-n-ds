//MO's Algorithm O(m+n  *  sqrt(n)) No updates and offline queries   Sample Range Sum Query
//						 0 base indexing
#include <bits/stdc++.h>


using namespace std;
int block=0;
vector<pair<int,int> >quer;

bool cmp(pair<int,int> a,pair<int,int> b){ // Arrange by blocks of sqrt(n)
	if(a.first/block!=b.first/block) return a.first/block<b.first/block;
	return a.second<b.second;
}

void mos(vector<int> lis,int n,int q){
	block=(int)sqrt(n);
	sort(quer.begin(),quer.end(),cmp);
	int currL=0,currR=0,currS=0;
	int l,r;
	for(int i=0;i<q;i++){
		l=quer[i].first; r=quer[i].second;
		while(currL<l){				// REMOVE EXTRA Elements
			currS-=lis[currL];
			currL++;
		}
		while(currL>l){
			currS+=lis[currL-1];
			currL--;
		}
		while(currR<=r){
			currS+=lis[currR];
			currR++;
		}
		while(currR>r+1){
			currS-=lis[currR-1];
			currR--;
		}
		cout<<"Sum is "<<currS<<"\n";
	}
}
int main(){
    int n;
    int q;
    cin>>n>>q;
    vector<int> lis(n);
    //vector<pair<int,int> >quer;
    for(int i=0;i<n;i++){
    	cin>>lis[i];					// Taking in inputs
    }
    int l=0,r=0;
    for(int i=0;i<q;i++){
    	cin>>l>>r;	// Accept the queries
    
    	quer.push_back(make_pair(l,r));
    }
    mos(lis,n,q);
    
    
    return 0;
}
