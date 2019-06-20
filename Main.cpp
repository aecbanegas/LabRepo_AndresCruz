#include <ncurses.h>
#include <vector>
#include <string>
#include "leerArchivo.h"
using std::vector;
using std::string;
bool debeSeguir(char* linea){
    if(sizeof(linea)>=4){
        if(linea[0]=='e'&&linea[1]=='x'&&linea[2]=='i'&&linea[3]=='t'){
            return false;
        }
    }
    return true;
}
bool crearCarpeta(char* linea){
    if(sizeof(linea)>=5){
        if (linea[0]=='m'&&linea[1]=='k'&&linea[2]=='d'&&linea[3]=='i'&&linea[4]=='r')
        {
            return true;
        }
    }
    return false;
}
bool entrarCarpeta(char* linea){
    if(sizeof(linea)>=2){
        if (linea[0]=='c'&&linea[1]=='d')
        {
            return true;
        }
    }
    return false;
}
bool regresarCarpeta(char* linea){
    if(sizeof(linea)>=3){
        if (linea[0]=='c'&&linea[1]=='d'&&linea[2]=='/')
        {
            return true;
        }
    }
    return false;
}
bool limpiarPantalla(char* linea){
    if(sizeof(linea)>=5){
        if (linea[0]=='c'&&linea[1]=='l'&&linea[2]=='e'&&linea[3]=='a'&&linea[4]=='r')
        {
            clear();
            refresh();
            return true;
        }
    }
    return false;
}
int main(){
    //vector<char[100]>carpetas;
    char usuario[100]="home";
    char maquinavirtual[100]="@vm-gauss";
    char carpeta[100];
    initscr();
    //printw("%s%s:~$ ",usuario,maquinavirtual);
    //refresh();
    char lineacodigo[100];
    //getstr(lineacodigo);
    bool seguir=true;
    bool dentrocarpeta=false;
    //seguir=debeSeguir(lineacodigo);//exit
    while(seguir){//while   
        if(has_colors()){
            start_color();
            init_pair(1,COLOR_GREEN,COLOR_BLACK);
            attron(COLOR_PAIR(1));
        
        if(dentrocarpeta){
            printw("%s%s:~/",usuario,maquinavirtual);
            attroff(COLOR_PAIR(1));   
            printw("%s",carpeta);
            printw("$ ");
        }
        else{
            printw("%s%s:~$ ",usuario,maquinavirtual);
            attroff(COLOR_PAIR(1));   
        }
        }
        refresh();
        getstr(lineacodigo);
        /*if(crearCarpeta(lineacodigo)){//detecta si se escribe un mkdir y lo ingresa en un vector de carpetas
            int acumular=0;
            char temporal[100];
            for (int i = 6; i < sizeof(lineacodigo); i++)
            {
                temporal[acumular]=lineacodigo[i];
                acumular++;
            }
      //      carpetas.push_back(temporal);
            
        }
        if(entrarCarpeta(lineacodigo)){//entra en carpeta si existe
            int acumular=0;
            char temporal[100];
            for (int i = 3; i < sizeof(lineacodigo); i++){
                temporal[acumular]=lineacodigo[i];
                acumular++;
            }
            for (int i = 0; i < carpetas.size(); i++){
                for (int j = 0; j < sizeof(carpetas[i]); j++)
                {
                    if(temporal[j]==carpetas[i][j]){
                        dentrocarpeta=true;
                    } 
                }
            }
            for (int i = 0; i < sizeof(temporal); i++)
            {
                carpeta[i]=temporal[i];
            }
        }*/
        if(regresarCarpeta(lineacodigo)){//verifica un regreso a la carpeta padre
            dentrocarpeta=false;
        }
        if(limpiarPantalla(lineacodigo)){//verifica si debe limpiar pantalla
            
        }
        if(lineacodigo[0]=='c'&&lineacodigo[1]=='h'&&lineacodigo[2]=='a'&&lineacodigo[3]=='n'&&lineacodigo[4]=='g'&&lineacodigo[5]=='e'&&lineacodigo[6]=='U'&&lineacodigo[7]=='s'&&lineacodigo[8]=='e'&&lineacodigo[9]=='r'){
            int acumular=0;
            for (int i = 11; i < sizeof(lineacodigo); i++){
                usuario[acumular]=lineacodigo[i];
                acumular++;
            }
        }
        if(lineacodigo[0]=='c'&&lineacodigo[1]=='h'&&lineacodigo[2]=='a'&&lineacodigo[3]=='n'&&lineacodigo[4]=='g'&&lineacodigo[5]=='e'&&lineacodigo[6]=='M'&&lineacodigo[7]=='a'&&lineacodigo[8]=='c'&&lineacodigo[9]=='h'&&lineacodigo[10]=='i'&&lineacodigo[11]=='n'&&lineacodigo[12]=='e')
        {
            int acumular=1;
            for (int i = 14; i < sizeof(lineacodigo)-1; i++){
                maquinavirtual[acumular]=lineacodigo[i];
                acumular++;
            }

        }
        if (lineacodigo[0]=='c'&&lineacodigo[1]=='h'&&lineacodigo[2]=='a'&&lineacodigo[3]=='n'&&lineacodigo[4]=='g'&&lineacodigo[5]=='e'&&lineacodigo[6]=='C'&&lineacodigo[7]=='o'&&lineacodigo[8]=='l'&&lineacodigo[9]=='o'&&lineacodigo[10]=='r')
        {
            if (lineacodigo[12]=='w'||lineacodigo[12]=='W')
            {
                start_color();
                init_pair(1,COLOR_RED,COLOR_WHITE);
                wbkgd(stdscr,COLOR_PAIR(1));
            }else if(lineacodigo[12]=='b'||lineacodigo[12]=='B'){
                start_color();
                init_pair(1,COLOR_WHITE,COLOR_BLACK);
                wbkgd(stdscr,COLOR_PAIR(1));
            }else if(lineacodigo[12]=='r'||lineacodigo[12]=='R'){
                start_color();
                init_pair(1,COLOR_YELLOW,COLOR_RED);
                wbkgd(stdscr,COLOR_PAIR(1));
            }   
        }
        seguir=debeSeguir(lineacodigo);
        //detecta si se escribe un exit
    }//fin while
    endwin();
    
    return 0;
}