// https://math.iitm.ac.in/public_html/sryedida/caimna/index1.html
// https://www.geeksforgeeks.org/lagranges-interpolation/
// https://codeforces.com/blog/entry/82953
// todo : implement NlogN lagrange for equally spaced datapoints
#include<stdio.h>
#include<limits.h>
#include <sys/time.h>

int cmp (const void * a, const void * b) {
	double x=*(double*)a;
	double y=*(double*)b;
	return x>y?1:-1; 
}

struct pair{
	double X;
	double Y;
}typedef pair;	

unsigned int seed;
void get_seed(){
	struct timeval tv;
	gettimeofday(&tv, NULL);
	seed = tv.tv_sec ^ tv.tv_usec | 1;
}

int rand(){
	if(seed == 0)
		get_seed();
	return (seed*=3) >> 1;
}

double frand(){
	return rand()*1.0/2072235839.000000;
}

#define MAX_DEG 12
double coefficients[MAX_DEG+1];
double prand(int degree){
	for(int i=0;i<degree+1;i++){
		coefficients[i]=frand();
	}
}

double f(double x,int degree){
	double res=0;
	for(int i=0;i<degree+1;i++){
		res+=coefficients[i]*pow(x,i);
	}
	return res;
}

double lagrange_interpolate(pair data[],int N,double find){
	double res=0;
	for(int i=0;i<N;i++){
		double cur=data[i].Y*1.0;
		for(int j=0;j<N;j++){
			if(i!=j){
				cur*=(find-data[j].X);
				cur/=(data[i].X-data[j].X);
			}
		}
		res+=cur;
	}
	return res;
}

int main() {
	int N,degree;
	scanf("%d%d",&N,&degree);
	prand(degree);
	double x_points[N],y_points[N];
	for(int i=0;i<N;i++){
		x_points[i]=frand();
	}
	qsort(x_points,N,sizeof(double),cmp);
	pair data[N];
	for(int i=0;i<N;i++){
		y_points[i]=f(x_points[i],degree);
		data[i].X=x_points[i];
		data[i].Y=y_points[i];
	}
	double query=frand();
	double response=lagrange_interpolate(data,N,query);
	double answer=f(query,degree);

	printf("%lf : %lf , %lf\n",query,response,answer);
}

// 1085777486.000000
// 1105532385.000000
// 983329130.000000
// 1073943331.000000
// 1072235839.000000