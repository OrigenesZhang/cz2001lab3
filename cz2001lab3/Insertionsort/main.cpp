#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;
ifstream fin("test.in");
ofstream fout("insertion.out");
#define cin fin
#define cout fout
const int maxn=(1<<20)+1;
int arr[maxn], n;
string str;
void insertion_sort(int* a, int s, int e){
	for(int i=s+1; i<e; i++){
		int cur=a[i];
		auto pos=lower_bound(a, a+i, cur);
		if(pos==a+i) continue;
		for(auto it=a+i-1; it!=pos; --it)
			*(it+1)=*it;
		*(pos+1)=*pos;
		*pos=cur;
	}
}
int main(){
	while(getline(cin, str)){
		n=0;
		stringstream ss(str);
		while(ss>>arr[n++]);
		insertion_sort(arr, 0, n);
		for(int i=0; i<n; i++)
			cout<<arr[i]<<' ';
		cout<<endl;
	}
	return 0;
}