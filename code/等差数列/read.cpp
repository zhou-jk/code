long long n,m,seed;
long long l,r,x,y;
long long rnd(){
	seed^=seed<<26;
	seed^=seed>>14;
	seed^=seed<<19;
	if(seed<0)seed=-seed;
	return seed;
}
void readData(){
	l=rnd()%m+1;
	r=rnd()%m+1;
	if(l>r)swap(l,r);
	if(l==m)l--;
	if(l==r)r++;
	if(rnd()%3==0){
		x=rnd()%m+1;
		y=rnd()%m+x;
		y-=(y-x)%(r-l);
		if(x==y)y+=r-l;
	}else{
		x=rnd()%m+1;
		y=x+(1+rnd()%1000)*(r-l);
	}
}
