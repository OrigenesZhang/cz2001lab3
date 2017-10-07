#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream fin("test.in");
ofstream fout("mergesort.out");
#define cin fin
#define cout fout
const int maxn=(1<<20)+1;
string str;
int tmp[maxn], arr[maxn], n;
void merge_sort(int* a, int s, int e){
	if(e-s<2) return;//conquer
	int m=s+(e-s>>1);
	merge_sort(a, s, m);
	merge_sort(a, m, e);//divide
	int p=s, q=m, r=s;
	while(p<m||q<e)
		if(q>=e||(p<m&&a[p]<=a[q])) tmp[r++]=a[p++];
		else tmp[r++]=a[q++];
	memcpy(a+s, tmp+s, (e-s)*sizeof(int));//merge
}
int main(){
	while(getline(cin, str)){//Every test case occupies exactly a line with an end-of-line mark; the input set terminates with an end-of-file mark
		stringstream ss(str);
		n=0;
		while(ss>>arr[n++]);
		merge_sort(arr, 0, n);
		for(int i=0; i<n; i++)
			cout<<arr[i]<<' ';
		cout<<endl;
	}
	return 0;
}