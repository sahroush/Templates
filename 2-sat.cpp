struct twosat{ //~x = 2*x+1 , x = 2*x --> ~x = x^1
	int n;
	vector < vector < int > > in , out;
	vector < int >  mark , col , topo , ans;
	int c = 0;
	twosat(int N):
		n(N) , in(n*2+5) , out(n*2+5) , mark(n*2+5 , 0) , col(n*2+5, 0) , ans(n + 5){}
	bool operator [] (int x){ return(ans[x]);};
	void add_edge(int v , int u){
		in[u].pb(v) , out[v].pb(u);
	}
	void sfd(int v){
		mark[v] = 1;
		col[v] = c;
		for(int u : in[v]) if(!mark[u])
			sfd(u);
	}
	void dfs(int v){
		mark[v] = 1;
		for(int u : out[v]) if(!mark[u])
			dfs(u);
		topo.pb(v);
	}
	bool validate(){
		for(int i = 1 ; i <= 2*n + 1 ; i ++)if(!mark[i])dfs(i);
		reverse(topo.begin() , topo.end());
		memset(&mark[0] , 0 , sizeof(mark[0]) * mark.size());
		for(auto v : topo)
			if(!mark[v])
				c++ , sfd(v);
		for(int i = 1 ; i <= n ; i ++)if(col[2*i] == col[2*i+1])return(0);
		for(int i = 1 ; i <= n ; i ++)ans[i] = (col[2*i] > col[2*i + 1]);
		return(1);
	}
};