#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;
ifstream fin("test.in");
ofstream fout("insertion.out");
#define cin fin
#define cout fout
const int maxn=(1<<20)+1;
int arr[maxn], n;
long long cnt;
string str;
void insertion_sort(int* a, int s, int e){
	int j, k;
	for(int i=s+1; i<e; i++){
		for(k=a[i], j=i-1; k<a[j]&&j>=s; j--)
			a[j+1]=a[j], cnt++;
		a[j+1]=k, cnt++;
	}
}
int main(){
	while(getline(cin, str)){
		n=0;
		stringstream ss(str);
		while(ss>>arr[n]) n++;
		cnt=0;
		double t0=(double)clock()/CLOCKS_PER_SEC, t1;
		insertion_sort(arr, 0, n);
		t1=(double)clock()/CLOCKS_PER_SEC;
		cout<<t1-t0<<' '<<cnt<<endl;
	}
	return 0;
}