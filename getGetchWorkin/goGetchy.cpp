#include <string>
#include <curses.h>
#include <iostream>


int main(){

  while(1){
    int c ;
    c = getch();
    printf("%d\t %c",c, c);

    if(c == 'x' || c == ('x' - '\0')){
      break;
    }

  }
  return 0;
}
