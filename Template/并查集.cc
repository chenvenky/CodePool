/**
* Title: 并查集     
*/

// 查询根&&路径压缩
int get_par(int a){
	if(par[a]!=a)
		par[a] = get_par(par[a]);  // 机智的路径压缩
	return par[a]; 
}

// 查询 a，b是否在同一个集合
int query(int a, int b){
	return get_par(a) == get_par(b); 
}

// 合并 a 集合 与 b 集合  
void merge(int a, int b){
	par[get_par(a)] = get_par(b); 
}
