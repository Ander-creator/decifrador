 /*
  * nome: Anderson Santos Silva
  * RA: 166191
  * Laboratório 6 - EA876
  * Objetivo: implementar um decodificador de caractéres
  * que vai receber uma mensagem codificada com a Cifra 
  * de Vingènere e printar a mensagem decodificada.
  */


#include <stdio.h>

#define TAM_BUFFER 60
char buffer_entrada[TAM_BUFFER];
char buffer_saida[TAM_BUFFER];
const char senha[] = "SENHASECRETA";

/*função que aplica a decodificação dos caractéres*/
char decod(char sen, char in){
  char out, a, b;
  a = in - 'A';
  b = sen - 'A';
  out = 'A' + (a - b + 26)%26;
  return out;
}

int main() {
  int i = 0, j = 0; 

  /* Leitura da entrada */
  fgets(buffer_entrada, TAM_BUFFER, stdin);

  while((buffer_entrada[i]!='\0') && (buffer_entrada[i]!='\n') && (i<TAM_BUFFER)){
    /*Condição para avaliarse temos uma letra ou outro caractére (pontuação, etc)*/
    if((buffer_entrada[i]>='A') && (buffer_entrada[i]<='Z'))
      buffer_saida[i] = decod(senha[j], buffer_entrada[i]);
    else buffer_saida[i] = buffer_entrada[i];

    i++;
    j++;
    if(j==12)j=0;
  }
  /* Escrever saida na tela */
  printf("%s\n", buffer_saida);

  return 0;
}
