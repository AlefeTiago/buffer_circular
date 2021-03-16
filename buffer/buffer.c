#include <stdio.h>

char buffer[5];
char *pIn, *pOut, *pEnd;
char full;

void adicionar_buffer(char cara) {
  if (pIn==pOut && full){
  }
  else{
    *pIn++ = cara;
    if (pIn == pEnd){
      pIn = buffer;
    }
    if (pIn == pOut)  {
      full = 1;
    }
  }
}

void remover_buffer() {
  if (pOut==buffer && !full){
  }
  else{
    *pOut++=0;
    if (pOut == pEnd){
      pOut = buffer;
    }
  }
}

void imprimir_buffer() {
  for (int i = 0; i < 5; i++) {
    printf("%d", buffer[i]);
    }
}

int main() {

  pIn=pOut=&buffer[0];
  pEnd=&buffer[5];
  full=0;

  char cara;

  do {
    scanf("%c", &cara);
    if (cara == '\n') break;
    if (cara==(1)){
      adicionar_buffer(cara);
      imprimir_buffer();
    }
    else {
      remover_buffer();
      imprimir_buffer();
    }


  } while (1);

  return 0;
}


