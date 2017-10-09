#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
using namespace std;
ofstream fout("test.out");
#define cout fout
const long long a=24999983, b=24999973;
const int maxn=(1<<20)+1;
int arr[maxn], buff[maxn];
inline long long seed(){
	time_t timer;
	struct tm y2k={0};
	long long secs;
	y2k.tm_hour=0, y2k.tm_min=0, y2k.tm_sec=0;
	y2k.tm_year=117, y2k.tm_mon=0, y2k.tm_mday=1;
	timer=time(NULL);
	secs=difftime(timer, mktime(&y2k));
	return secs;
}
inline long long next_randint(long long x, long long MOD){
	return (a*x+b)%MOD;
}
void fisher_and_yates(int n){
	memcpy(arr, buff, n*sizeof(int));
	long long x=seed();
	for(int i=0; i<n; i++){
		x=next_randint(x, i+1);
		swap(arr[i], arr[x]);
	}
	for(int i=0; i<n; i++)
		cout<<arr[i]<<' ';
	cout<<endl;
}
int main(){
	for(int i=0; i<maxn; i++)
		buff[i]=i+1;
	for(int i=1000; i<=1000000; i+=10000){
		fisher_and_yates(i);
		//Ascending order
		/*for(int j=0; j<i; j++)
			cout<<buff[j]<<' ';
		cout<<endl;*/
	}
	return 0;
}