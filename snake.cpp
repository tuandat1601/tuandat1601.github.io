#include<iostream>
#include"mylib.h"
using namespace std;
int sl = 7;
void ve_tuong_tren();
void ve_tuong_duoi();
void ve_tuong_phai();
void ve_tuong_trai();
void ve_tuong();
void khoi_tao_ran(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void xu_li_ran(int toadox[], int toadoy[], int x, int y,int &xqua,int &yqua);
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
void them(int a[], int x);
void xoa(int a[], int vt);
bool ran_cham_tuong(int x0, int y0);
bool ran_cham_duoi(int toadox[], int toadoy[]);
bool kt(int toadox[], int toadoy[]);
void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[]);
bool ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool ran_an_qua(int xqua, int yqua, int x0, int y0);
int main() {
	
	bool gameover = false;
	int toadox[100], toadoy[100];
	ve_tuong();
	khoi_tao_ran(toadox,toadoy);
	ve_ran(toadox, toadoy);
	srand(time(NULL));
	int xqua = 0, yqua = 0;
	tao_qua(xqua, yqua,toadox,toadoy);
	int x = 50, y = 13;//dinh hinh vi tri ran di chuyen
	int check = 2;
	while (gameover == false) {
		
		xoa_du_lieu_cu(toadox, toadoy);
		
		if (_kbhit()) {
			char kitu = _getch();
			if (kitu == -32) {
				kitu = _getch();
				if (kitu == 72&&check!=0) {
					check = 1;//len
				}
				else if (kitu == 80&&check!=1) {
					//xuong
					check = 0;
				}
				else if (kitu == 77&&check!=3) {
					check = 2;
				}
				else if (kitu == 75 && check != 2) {
					check = 3;
				}
			}
		}
		if (check == 0) {
			y++;
		}
		else if (check == 1) {
			y--;
		}
		else if (check == 2) {
			x++;
		}
		else if (check == 3) {
			x--;
		}
		if (check == 0) {
			//di xuong
		}
		else if (check == 1) {
			//di len
		}
		
		else if (check == 3) {
			//qua phai
		}
		
		xu_li_ran(toadox, toadoy,x,y,xqua,yqua);
		gameover=kt(toadox, toadoy);
		Sleep(300);
	}
	
	_getch();
		return 0;
}
void ve_tuong_tren() {
	int x = 10, y = 1;
	while (x <= 100) {
		gotoXY(x, y);
		cout << "+";
		x++;
	}
}
	void ve_tuong_duoi() {
		int x = 10, y = 26;
		while (x <= 100) {
			gotoXY(x, y);
			cout << "+";
			x++;
		}
	
}
	void ve_tuong_phai() {
		int x = 100, y = 1;
		while (y < 26) {
			gotoXY(x, y);
			cout << "+";
			y++;
		}

	}
	void ve_tuong_trai() {
		int x = 10, y = 1;
		while (y < 26) {
			gotoXY(x, y);
			cout << "+";
			y++;
		}

	}
	void ve_tuong() {
		SetColor(11);
		ve_tuong_tren();
		ve_tuong_duoi();
		ve_tuong_phai();
		ve_tuong_trai();
	}
	void khoi_tao_ran(int toadox[], int toadoy[]) {
		int x = 50, y = 13;
		for (int i = 0; i < sl; i++) {
			toadox[i] = x;
			toadoy[i] = y;
			x--;
		}
	}
	void ve_ran(int toadox[],int toadoy[]) {
		for (int i = 0; i < sl; i++) {
			gotoXY(toadox[i], toadoy[i]);
			if (i == 0) {
				cout << "0";
			}
			else {
				cout << "o";
			}
		}
		gotoXY(toadox[0], toadoy[0]);
		cout << "0";
		gotoXY(toadox[1], toadoy[1]);
		cout << "o";
		gotoXY(toadox[2], toadoy[2]);
		cout << "o";
	}
	void xoa_du_lieu_cu(int toadox[], int toadoy[]) {
		for (int i = 0; i < sl; i++) {
			gotoXY(toadox[i], toadoy[i]);
			cout << " ";
		}
	}
	void xu_li_ran(int toadox[], int toadoy[], int x, int y,int &xqua,int &yqua) {
		//them toa do moi vao dau mang
		them(toadox, x);
		them(toadoy, y);
		//xoa toa do cuoi mang
		if (ran_an_qua(xqua, yqua, toadox[0], toadoy[0]) == false) {
			xoa(toadox, sl - 1);
			xoa(toadoy, sl - 1);
		}
		else {
			tao_qua(xqua, yqua, toadox, toadoy);
		}
		//ve ran
		ve_ran(toadox, toadoy);
		
	}
	void them(int a[],int x) {
		for (int i = sl; i > 0; i--) {
			a[i] = a[i - 1];
		}
		a[0] = x;
		sl++;
	}
	void xoa(int a[],  int vt) {
		for (int i = vt; i < sl; i++) {
			a[i] = a[i + 1];
		}
		sl--;
	}
	bool ran_cham_tuong(int x0, int y0) {
		//ran cham tuong tuong tren
		if (y0 == 1 && (x0 >= 10 && x0 <= 100)) {
			return true;//game over
		}//cham tuong duoi
		else if (y0 == 26 && (x0 >= 10 && x0 <= 100)) {
			return true;//game over
		}//cham tuong phai
		else if (x0 == 100 && (y0 >= 1 && y0 <= 26)) {
			return true;//game over
		}//cham tuong trai
		else if (x0 == 0 && (y0 >= 1 && y0 <= 26)) {
			return true;//game over
		}
		return false;
	}
	bool ran_cham_duoi(int toadox[],int toadoy[]) {
		for (int i = 1; i < sl; i++) {
			if (toadox[0] == toadox[i] && toadoy[0] == toadoy[i]) {
				return true;//game over
			}
		}
		return false;
	}
	bool kt(int toadox[], int toadoy[]) {


		bool kt1 = ran_cham_duoi(toadox, toadoy);
		bool kt2 = ran_cham_tuong(toadox[0], toadoy[0]);
		if (kt1 == true || kt2 == true) {
			return true;
		}
		return false;
	}
	void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[]) {
	
		do {
			//x tu 11 - 99
			xqua = rand() % (99 - 11 + 1) + 11;
			//y tu 2-25
			yqua = rand() % (25 - 2 + 1) + 2;
		} while (ran_de_qua(xqua, yqua, toadox, toadoy) == true);
		int i = rand() % (15 - 1 + 1) + 1;
			SetColor(i);
		gotoXY(xqua, yqua);
		cout << "$";
		SetColor(7);
	}
	bool ran_de_qua(int xqua,int yqua,int toadox[],int toadoy[]) {
		for (int i = 0; i < sl; i++) {
			if (xqua == toadox[i] && yqua == toadoy[i]) {
				return true;//ran de len qua
			}

		}
		return false;
	}
	bool ran_an_qua(int xqua,int yqua,int x0,int y0) {
		if (x0 == xqua && y0 == yqua) {
			return true;//an qua
		}
		return false;
	}
