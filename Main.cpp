#include <ncurses.h>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
int main(){
    initscr();
    printw("Hello world");
    refresh();
    getch();
    endwin();
    return 0;
}