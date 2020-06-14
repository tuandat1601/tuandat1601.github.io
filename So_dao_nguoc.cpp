#include<iostream>

using namespace std;
int daonguoc(int n);
int main(){
 int n,S;
 cout<<"Nhap n:";
 cin>>n;
 S=daonguoc(n);
 cout<<"So dao nguoc la: "<<S<<endl;


return 0;
}
int daonguoc(int n){
	int sdn=0, du;
	while( n != 0){
	
		du= n%10;
		sdn= sdn*10+du;
		n /= 10;	
	}
 return sdn;
}
