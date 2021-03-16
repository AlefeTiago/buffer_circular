#include <stdio.h>

char buffer[5];
char *pIn, *pOut, *pEnd;
char full;
int quantidade;
// Aqui eu criei as vari�veis globais que vou usar durante o programa. Um buffer de tamanho 5, um ponteiro pIn que avalia
//onde vai ser alocado o proximo n�mero no buffer, um ponteiro pOut que avalia o termo mais antigo do buffer, um ponteiro que avalia o �ltimo item do buffer, uma vari�vel
//avisa quando o buffer est� cheio e uma vari�vel que avisa quantos espa�os no buffer s�o diferentes de NULL.

void adicionar_buffer(char c) {// a fun��o que adiciona valores no buffer (� chamada na main)
  if (pIn==pOut && full){ //esse if n�o deixa que um buffer cheio seja sobrescrito
  }
  else{
    *pIn = c; // se o buffer n�o estiver cheio, a posi��o apontada por pIn recebe o valor digitado na fun��o main.
    pIn=pIn+1; // como pIn deve apontar para onde o pr�ximo item ser� escrito, aqui ele � incrementado.
    ++quantidade; // como "quantidade" foi iniciado com 0 na main, e um novo valor foi inserido no buffer, quantidade � incrementada.
    if (pIn == pEnd){ // como o buffer deve ser circular, quando pIn aponta para pEnd ele volta para a posi��o buffer[0]
      pIn = buffer;
    }
    if (pIn == pOut)  { // aqui � definido o caso particular onde o buffer � considerado cheio, quando pIn iria sobrescrever pOut
      full = 1;
    }
  }
}

void remover_buffer(){ // a fun��o que remove itens do buffer(� chamada pela fun��o main)

    if (pIn == pOut  &&  !full){//evita que o programa tente remover itens de buffers vazios.
        pIn=buffer; // se o buffer estiver vazio, essa linha for�a o proximo item a ser inserido na posi��o 0.
    }
    else {
        *pOut=(char)0; // transforma o item apontado por pOut em Null.
        pOut=pOut+1; // como agora pOut n�o � o mais antigo, deve ser incrementado.
        if (quantidade>0){
            --quantidade; //aqui, se quantidade for >0, o valor quantidade de itens � decrementado, j� que um item foi removido.
        }

    if (pOut >= pEnd){ //assim como na fun��o adicionar, isso garante a circularidade do buffer.
        pOut = buffer;
    }
    }
}
void imprimir_buffer() { // fun��o usada para imprimir os valores do vetor formatados

    int h=quantidade; // aqui eu  uma vari�vel que recebe o valor da vari�vel global quantidade, para nunca mudar o valor de quantidade dentro da fun��o.
    for (int i = 0; i < 5; i++) {
        if (buffer[i]!=0 && h!=1 ){
          printf("%c ", buffer[i]); //aqui, para cada valor do vetor diferente de zero, se a quantidade � diferente de zero eu exibo o
          // valor na tela com espa�o entre os caracteres e decremento a mascara para quantidade (assim, quanto s� sobrar um item no vetor
        // para exibir eu quebro a linha.
        --h;
        }
        else if (buffer[i]!=0 && h==1){
             printf("%c", buffer[i]);
        }
    }
    printf("\n"); // parte do c�digo que garante a quebra de linha ap�s o �ltimo elemento sem espa�o no final.
}


int main() {

  pIn=pOut=&buffer[0];
  pEnd=&buffer[5];
  full=0;
  quantidade=0;
  char cara;
  // acima � apenas uma inicializa��o das vari�veis globais que foram enunciadas fora da fun��o main. (expliquei acima cada uma)
  do {
    scanf("%c", &cara);
    if (cara == '\n') break; // quebra o la�o do programa principal se o enter for pressionado para quebrar a linha do input
    if (cara>='0'&& cara<='9'){//enquanto o la�o n�o � quebrado o programa avalia se � um n�mero ou um caractere.
      adicionar_buffer(cara);
      imprimir_buffer();
      // se for um n�mero a fun��o main chama a fun��o adicionar_buffer com o par�metro do input e depois chama a fun��o que printa
      // a cada itera��o do la�o (do-while).
    }
    else if (cara>='a' && cara<='z' || cara>='A' && cara<='Z') {
      remover_buffer();
      imprimir_buffer();
      // se for um caractere a fun��o main chama a fun��o remove_buffer e depois chama a fun��o que printa a cada itera��o do la�o
      //(do-while).
    }


  } while (1);

  return 0;
}

