#include <iostream>
#include<conio.h>
#include<windows.h>
using namespace std;

bool gameover;
int width=20;
int height=20;
int x,y,fruitx,fruity,score;

#define left 1
#define right 2
#define up 3
#define down 4

int dir;

void Setup(){
    gameover=false;
    x=width/2;
    y=height/2;
    fruitx=rand()%width;
    fruity=rand()%height;
    score=0;
}
void Draw(){
    system("cls");
    for (int i=0;i<width;i++){
        cout<<"#";
    }
    cout<<endl;
    for (int i=0;i<height;i++){
        for(int j=0;j<width;j++){
            if (j==0){
                cout<<"|";
            }
            else if (j==width-1){
                cout<<"|"<<endl;
            }
            else {
                if (i==y && j==x){
                    cout<<"O";
                }
                else if (i==fruity && j==fruitx){
                    cout<<"*";
                }
                else{
                    cout<<" ";
                }
            }
        }
    }
    cout<<endl;
    for (int i=0;i<width;i++){
        cout<<"#";
    }
    cout<<endl;
    
    cout<<"score="<<score<<endl;
}
void Input(){
    if (kbhit()){
        char ch=_getch();
        if (ch=='a'){
            dir=left;
        }
        else if (ch=='d'){
            dir=right;
        }
        else if (ch=='w'){
            dir=up;
        }
        else if (ch=='s'){
            dir=down;
        }
        else if (ch=='x'){
            gameover=true;
        }
    }
}
void Logic(){
    if (dir==left){
        x--;
    }
    else if (dir==right){
        x++;
    }
    else if (dir==up){
        y--;
    }
    else if (dir==down){
        y++;
    }
    if (x>=width || x<0 || y>=height || y<0 ){
        gameover=true;
    }
    if (x==fruitx && y==fruity){
        score+=10;
        fruitx=rand()%width;
        fruity=rand()%height;
    }
}


int main() {
    Setup();
    
    while (!gameover){
        Draw();
        Input();
        Logic();
        Sleep(200);
    }
}