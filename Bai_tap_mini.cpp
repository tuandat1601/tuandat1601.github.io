#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <windows.h>
 struct Sinhvien{
char hoten[40];
char mssv[10];
char gioitinh[5];	
int ngay,thang,nam;
	
	float dtb;
} ;//nhap sinh vien
void nhap(struct Sinhvien *&s,int *n){
	
	
	s=(Sinhvien*)malloc(*n*sizeof(Sinhvien));
	for(int i=0;i<*n;i++){
		printf("Nhap sinh vien %d",i+1);
			fflush(stdin);
	printf("\nMSSV: ");
	gets((s+i)->mssv);
	printf("\nHo va ten: ");

	gets((s+i)->hoten);
	fflush(stdin);
    printf("\nGioi tinh: ");
	scanf("%s",&(s+i)->gioitinh);
	fflush(stdin);
	printf("\nNgay, thang, nam: ");
	scanf("%d%d%d",&(s+i)->ngay,&(s+i)->thang,&(s+i)->nam);

	fflush(stdin);
    printf("\nNhap DTB: ");
    scanf("%f",&(s+i)->dtb);
	printf("\n");
	}

}
int xeploai(Sinhvien *s){
	
	if((s->dtb)<=5){
		printf("TB");
	}
	else if((s->dtb)>5&&(s->dtb)<=8){
		printf("K");
	}
	else{
			printf("G");
	}

	}
//xuat danh sach sinh vien
void xuatds(Sinhvien *s,int n){
	
	printf("%-10s %-20s %-5s %-5s %-5s %-5s %-8s %-10s\n", 
	"MSSV", "Ho va ten",  "Gioi Tinh", "Ngay ","Thang","Nam","DTB","Xep loai");
	for(int i=0;i<n;i++){
		printf("%-10s %-20s %-10s %-5d %-5d %-5d %-8.1f ",(s+i)->mssv,(s+i)->hoten,(s+i)->gioitinh,(s+i)->ngay,
	(s+i)->thang,(s+i)->nam,(s+i)->dtb);
     
	xeploai(s+i);

	printf("\n");
printf("-----------------------------------------------------"
	"----------------------------------------------------------------\n");
	
}
}
//sap xep sinh vien theo die trung binh
void sapxepdiemgiam(Sinhvien *s,int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if((s+i)->dtb<(s+j)->dtb){//khai bao bien trung gian la temp co kieu struct
			Sinhvien temp;	
			
			strcpy(temp.mssv,(s+j)->mssv);
			strcpy(temp.hoten,(s+j)->hoten);
			strcpy(temp.gioitinh,(s+j)->gioitinh);
			temp.ngay=(s+j)->ngay;
			temp.thang=(s+j)->thang;
			temp.nam=(s+j)->nam;
			temp.dtb=(s+j)->dtb	;
			
			
			
			strcpy((s+j)->mssv,(s+i)->mssv);
			strcpy((s+j)->hoten,(s+i)->hoten);
			strcpy((s+j)->gioitinh,(s+i)->gioitinh);
			(s+j)->ngay=(s+i)->ngay;
			(s+j)->thang=(s+i)->thang;
			(s+j)->nam=(s+i)->nam;
			(s+j)->dtb=(s+i)->dtb	;
			
			
			strcpy((s+i)->mssv,temp.mssv);
			strcpy((s+i)->hoten,temp.hoten);
			strcpy((s+i)->gioitinh,temp.gioitinh);
		(s+i)->ngay=temp.ngay;
			(s+i)->thang=temp.thang;
			(s+i)->nam=temp.nam;
			(s+i)->dtb=temp.dtb	;
			}
		}
	}
	
}
 void timkiem(Sinhvien *s,int n){
 	char ten[30];
 	fflush(stdin);
 	printf("\n Nhap ten sinh vien can tim: ");
 	gets(ten);
 	for(int i=0;i<n;i++){
 		if(strcmp(ten,(s+i)->hoten)==0){
 				printf("%-10s %-20s %-5s %-5s %-5s %-5s %-8.1s\n", 
	"MSSV", "Ho va ten",  "Gioi Tinh", "Ngay","Thang","Nam","DTB\n");
 			printf("%-10s %-20s %-10s %-5d %-5d %-5d %-8.1f \n",(s+i)->mssv,(s+i)->hoten,(s+i)->gioitinh,(s+i)->ngay,
	(s+i)->thang,(s+i)->nam,(s+i)->dtb);
		 }
		 else{
		 	printf("Khong ton tai sinh vien trong danh sach! ahihi");
		 }
	 }
 }
 void sapxepten(Sinhvien *s,int n){
 		for(int i=0;i<n-1;i++){
		  for(int j=i+1;j<n;j++){
			if(strcmp((s+i)->hoten,(s+j)->hoten)==1){//khai bao bien trung gian la temp co kieu struct
			Sinhvien temp;	
			strcpy(temp.mssv,(s+j)->mssv);
			strcpy(temp.hoten,(s+j)->hoten);
			strcpy(temp.gioitinh,(s+j)->gioitinh);
			temp.ngay=(s+j)->ngay;
			temp.thang=(s+j)->thang;
			temp.nam=(s+j)->nam;
			temp.dtb=(s+j)->dtb	;
			
			
			
			strcpy((s+j)->mssv,(s+i)->mssv);
			strcpy((s+j)->hoten,(s+i)->hoten);
			strcpy((s+j)->gioitinh,(s+i)->gioitinh);
			(s+j)->ngay=(s+i)->ngay;
			(s+j)->thang=(s+i)->thang;
			(s+j)->nam=(s+i)->nam;
			(s+j)->dtb=(s+i)->dtb	;
			
			
			strcpy((s+i)->mssv,temp.mssv);
			strcpy((s+i)->hoten,temp.hoten);
			strcpy((s+i)->gioitinh,temp.gioitinh);
		(s+i)->ngay=temp.ngay;
			(s+i)->thang=temp.thang;
			(s+i)->nam=temp.nam;
			(s+i)->dtb=temp.dtb	;
			}
		}
	}
 }

 void ghifile(Sinhvien *s,int &n){
 	
 	//ghi thong tin sinh vien vao flie co ten la sinh vien
 	FILE *fOut=fopen("sv.txt","a");
 	
 	for(int i=0;i<n;i++){
 			
 			fprintf(fOut,"%-10s %-20s %-10s %-5d %-5d %-5d %-8.1f \n",(s+i)->mssv,(s+i)->hoten,(s+i)->gioitinh,(s+i)->ngay,
	(s+i)->thang,(s+i)->nam,(s+i)->dtb);
	 }
	 fclose(fOut);
 }	
 void docFile( Sinhvien *s) {
 
	FILE *fOut ;
	fOut= fopen("sv.txt", "r");
	

	int i = 0;
	if(fOut) {
			printf("%-10s %-20s %-5s %-5s %-5s %-5s %-8s\n", 
	"MSSV", "Ho va ten",  "Gioi Tinh", "Ngay ","Thang","Nam","DTB");
		for(;;) {
			fscanf(fOut,"%-10s %-20[^\n] %-10s %-5d %-5d %-5d %-8.1f \n",(s+i)->mssv,(s+i)->hoten,(s+i)->gioitinh,&(s+i)->ngay,
	&(s+i)->thang,&(s+i)->nam,&(s+i)->dtb);
	printf("%-10s %-20[^\n] %-10s %-5d %-5d %-5d %-8.1f \n",(s+i)->mssv,(s+i)->hoten,(s+i)->gioitinh,&(s+i)->ngay,
	&(s+i)->thang,&(s+i)->nam,&(s+i)->dtb);
		if(feof(fOut)) {
				break;
		}
		i++;
	}
}
else if(fOut==NULL){
	printf("\n Khong the mo file ");
	exit(1);
}
fclose(fOut);
}
int main(){
	int n;
	struct Sinhvien *s;
	int choice,tieptuc;
	
docFile(s);
	
	do{
	
		printf("=============== MENU ===============");
		printf("\n1. Them n Sinh vien vao danh sach file ");
		
		printf("\n2. Sap xep theo ten.");
		printf("\n3. Sap xep theo diem tb giam dan.");
		printf("\n4. Tim sinh vien theo ten.");
	    
	    printf("\n5.Xep loai tung sinh vien.");
	    printf("\n6.Ghi file.");
		printf("\n0. Thoat chuong trinh.");
		printf("\nBan chon ? ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Nhap so sv ban muon lam viec: ");
	scanf("%d",&n);
			nhap(s,&n);
			
			break;
		
			case 2:sapxepten(s,n);
			
			xuatds(s,n);
			break;
			case 3:sapxepdiemgiam(s,n);
			xuatds(s,n);
			break;
			case 4:timkiem(s,n);
			break;
			case 5:
				xuatds(s,n);
				break;
			case 6:ghifile(s,n);
			break;
			case 0:	
			for(int k=3;k>=0;k--){
				
				system("cls");
        		printf("                    THOAT TRONG:%d ",k);
        		
        		Sleep(1000);
        	}
        	exit(0);
				break;
			
			exit(0);
        	break;
			default:
				printf("Sai chuc nang, vui long chon lai!\n");
				break;	
		}
			printf("\n\tBan co muon tiep tuc khong? (1: Co, 2:Khong): ");
	scanf("%d",&tieptuc);
	
}while(tieptuc==1);




 



}

