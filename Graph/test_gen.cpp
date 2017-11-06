#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
ofstream fout("test.out");
#define cout fout
typedef long long ll;
const char table[]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', ' ', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const int maxn=12345;
vector<int> G[maxn];
unordered_map<string, int> mmap;
unordered_map<int, string> mat;
int V, E, cnt;
void string_gen(int V){
	mmap.clear();
	mat.clear();
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(0, 52);
	int cur=0, lenmax=64, len;
	while(cur<V){
		len=dis(gen)%lenmax;
		if(len<3) len=lenmax-len;
		string s="";
		int llen=len;
		while(llen--) s+=table[dis(gen)];
		if(mmap[s]) continue;
		mmap[s]=++cur;
		mat[cur]=s;
	}
}
int main(){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(2, 100000);
	label:
	V=dis(gen)%10001;
	if(V<2) goto label;
	E=V;
	E=dis(gen);
	if(E>V*(V-1)/2-V+1) E=V*(V-1)/2-V+1;
	string_gen(V);
	for(int i=1; i<V; i++){
		if(dis(gen)&1) G[dis(gen)%10001].push_back(i);
		else G[i].push_back(dis(gen)%10001);
	}
	while(cnt<E){
		auto x=dis(gen)%V;
		auto y=dis(gen)%V;
		if(y==x) continue;
		auto it1=find(G[y].begin(), G[y].end(), x);
		auto it2=find(G[x].begin(), G[x].end(), y);
		if(it1!=G[y].end()||it2!=G[x].end()) continue;
		cnt++&1?G[x].push_back(y):G[y].push_back(int(x));
	}
	cout<<V+E-1<<endl;
	for(int i=0; i<V; i++)
		for(int v:G[i])
			cout<<mat[i+1]<<'\n'<<mat[v+1]<<endl;
	ll Q=dis(gen)%9987;
	cout<<Q<<endl;
	while(Q--){
		auto x=dis(gen)%V;
		auto y=dis(gen)%V;
		cout<<mat[x+1]<<'\n'<<mat[y+1]<<endl;
	}
	return 0;
}