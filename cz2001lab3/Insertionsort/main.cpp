#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstring>
using namespace std;
ifstream fin("test.in");
ofstream fout("insertion.out");
#define cin fin
#define cout fout
const int maxn=(1<<20)+1;
int arr[maxn], n, buff[maxn];
long long cnt;
double t[5], c[5];
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
		while(ss>>buff[n++]);
		for(int i=0; i<3; i++){
			memcpy(arr, buff, sizeof(buff));
			cnt=0;
			double t0=(double)clock()/CLOCKS_PER_SEC, t1;
			insertion_sort(arr, 0, n);
			t1=(double)clock()/CLOCKS_PER_SEC;
			t[i]=t1-t0, c[i]=cnt;
		}
		cout<<(t[0]+t[1]+t[2])/3<<' '<<(c[0]+c[1]+c[2])/3<<endl;
	}
	return 0;
}