#include <stdio.h>

char buffer[5];
char *pIn, *pOut, *pEnd;
char full;
int quantidade;
// Aqui eu criei as variáveis globais que vou usar durante o programa. Um buffer de tamanho 5, um ponteiro pIn que avalia
//onde vai ser alocado o proximo número no buffer, um ponteiro pOut que avalia o termo mais antigo do buffer, um ponteiro que avalia o último item do buffer, uma variável
//avisa quando o buffer está cheio e uma variável que avisa quantos espaços no buffer são diferentes de NULL.

void adicionar_buffer(char c) {// a função que adiciona valores no buffer (é chamada na main)
  if (pIn==pOut && full){ //esse if não deixa que um buffer cheio seja sobrescrito
  }
  else{
    *pIn = c; // se o buffer não estiver cheio, a posição apontada por pIn recebe o valor digitado na função main.
    pIn=pIn+1; // como pIn deve apontar para onde o próximo item será escrito, aqui ele é incrementado.
    ++quantidade; // como "quantidade" foi iniciado com 0 na main, e um novo valor foi inserido no buffer, quantidade é incrementada.
    if (pIn == pEnd){ // como o buffer deve ser circular, quando pIn aponta para pEnd ele volta para a posição buffer[0]
      pIn = buffer;
    }
    if (pIn == pOut)  { // aqui é definido o caso particular onde o buffer é considerado cheio, quando pIn iria sobrescrever pOut
      full = 1;
    }
  }
}

void remover_buffer(){ // a função que remove itens do buffer(é chamada pela função main)

    if (pIn == pOut  &&  !full){//evita que o programa tente remover itens de buffers vazios.
        pIn=buffer; // se o buffer estiver vazio, essa linha força o proximo item a ser inserido na posição 0.
    }
    else {
        *pOut=(char)0; // transforma o item apontado por pOut em Null.
        pOut=pOut+1; // como agora pOut não é o mais antigo, deve ser incrementado.
        if (quantidade>0){
            --quantidade; //aqui, se quantidade for >0, o valor quantidade de itens é decrementado, já que um item foi removido.
        }

    if (pOut >= pEnd){ //assim como na função adicionar, isso garante a circularidade do buffer.
        pOut = buffer;
    }
    }
}
void imprimir_buffer() { // função usada para imprimir os valores do vetor formatados

    int h=quantidade; // aqui eu  uma variável que recebe o valor da variável global quantidade, para nunca mudar o valor de quantidade dentro da função.
    for (int i = 0; i < 5; i++) {
        if (buffer[i]!=0 && h!=1 ){
          printf("%c ", buffer[i]); //aqui, para cada valor do vetor diferente de zero, se a quantidade é diferente de zero eu exibo o
          // valor na tela com espaço entre os caracteres e decremento a mascara para quantidade (assim, quanto só sobrar um item no vetor
        // para exibir eu quebro a linha.
        --h;
        }
        else if (buffer[i]!=0 && h==1){
             printf("%c", buffer[i]);
        }
    }
    printf("\n"); // parte do código que garante a quebra de linha após o último elemento sem espaço no final.
}


int main() {

  pIn=pOut=&buffer[0];
  pEnd=&buffer[5];
  full=0;
  quantidade=0;
  char cara;
  // acima é apenas uma inicialização das variáveis globais que foram enunciadas fora da função main. (expliquei acima cada uma)
  do {
    scanf("%c", &cara);
    if (cara == '\n') break; // quebra o laço do programa principal se o enter for pressionado para quebrar a linha do input
    if (cara>='0'&& cara<='9'){//enquanto o laço não é quebrado o programa avalia se é um número ou um caractere.
      adicionar_buffer(cara);
      imprimir_buffer();
      // se for um número a função main chama a função adicionar_buffer com o parâmetro do input e depois chama a função que printa
      // a cada iteração do laço (do-while).
    }
    else if (cara>='a' && cara<='z' || cara>='A' && cara<='Z') {
      remover_buffer();
      imprimir_buffer();
      // se for um caractere a função main chama a função remove_buffer e depois chama a função que printa a cada iteração do laço
      //(do-while).
    }


  } while (1);

  return 0;
}

