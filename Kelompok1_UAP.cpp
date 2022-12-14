#include <iostream> 
#include <conio.h> 
#include <windows.h>
#define manDef 2 //untuk bikin konstan
#define rintDef 74 

using namespace std;
char x[7]={'S','C','O','R','E',' ',':'};
int Yman;
int speed = 30;
int gameover = 0;
int score,a;

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void map() {
    system("cls"); 
    gameover = 0;
    gotoxy(0, 0); 
	cout<<x;
    for (int i = 0; i < 79; i++){
    	gotoxy(i, 1); cout<<"#";
    	gotoxy(i, 25); cout<<"#";
	} 
}

void jumpman(int jump = 0) { 
    int kaki = 0;	

    if (jump == 0)
        Yman = 0;
    else if (jump == 2)
        Yman--;
    else Yman++;

    gotoxy(manDef, 20 - Yman);
	cout<<"                 ";
    gotoxy(manDef, 21 - Yman);
	cout<<"           (>.<)   ";
    gotoxy(manDef, 22 - Yman);
	cout<<"           /     \ ";
    gotoxy(manDef, 23 - Yman);
    if (jump == 1 || jump == 2) {
        cout<<"                 ";
        gotoxy(2, 24 - Yman);
        cout<<"       --    --  ";
    } 
	else if (kaki == 0) {
        cout<<"            ( )  ";
        gotoxy(2, 24 - Yman);
        cout<<"           ||  ";
        kaki = !kaki;
    } 
	else if (kaki == 1) {
        cout<<"                 ";
        gotoxy(2, 24 - Yman);
        cout<<"                 ";
        kaki = !kaki;
    }

    gotoxy(2, 25 - Yman);
    if (jump == 0) {
        cout<<"#############";
    } 
	else {
        cout<<"                ";
    } 

    Sleep(speed);

}
void outrint() {	
    static int rintX = 0;  
	static int score = 0;
    if (rintX == 56 && Yman < 3) {
        gotoxy(36, 11);
		cout<<"Game Over";
        getch();
        gameover = 1; 
    }

    gotoxy(rintDef - rintX, 21);cout<<" _ _ ";
    gotoxy(rintDef - rintX, 22);cout<<"|'-'| ";

    rintX++;

    if (rintX == 73){
        rintX =0;
        score++;
        gotoxy(11, 0);cout<<score; 
    }
}
void play(){ 
	system("cls");
    char jumping;
    int i=0;
	map();
    while (true) {
        while (!kbhit()) {
            if( gameover==1 ){
            	return;
			}
			jumpman();
            outrint();
        }
        jumping = getch();
        if (jumping == ' ') {

            while( i < 12) {
                jumpman(1);
                outrint();
                i++;
            }
            while(i > 0) {
                jumpman(2);
                outrint();
                i--;
        	}
        }
		else if (jumping == 'p'||jumping=='P')
           getch();
		else if (jumping == 20)
           break;
    }
}

void nama(){
	cout<<"Enter Nama : ";
	cin>>a;
}

void instructions() {
	system("cls");
	cout<<"Instructions";
	cout<<"\n----------------";
	cout<<"\n1. Jump to avoid obstacles";
	cout<<"\n2. Press 'Spacebar' to jump ";
	cout<<"\n3. Press 'p' to pause game ";
	cout<<"\n4. Press 'Escape' to exit from game";
	cout<<"\n\nPress any key to go back to menu";
	getch();
}

int main() {

    do{
		system("cls");
		gotoxy(10,5); cout<<"     GAME BY GROUP 1   "; 
		gotoxy(10,6); cout<<"         Jumping Girl       ";  
		gotoxy(10,9); cout<<"1. Mulai ";
		gotoxy(10,10); cout<<"2. Panduan ";	 
		gotoxy(10,11); cout<<"3. Keluar";
		gotoxy(1,1);nama();
		gotoxy(10,13); cout<<"Pilih Menu: ";
		char choose = getche();
		if( choose=='1') play();
		else if( choose=='2') instructions();
		else if( choose=='3') exit(0);

	}while(1);

	return 0;
}
