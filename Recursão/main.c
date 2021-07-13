#include <stdio.h>

float recursiva(float x){
  
  if(x==1){
    return 1;
  }
  else{
    return x/(x+(x-1)) + recursiva(x-1);
  }
  
}

void naoRecursiva(float x){
int i,n=x;
float res=0;

for(i=0; i<n; i++){
  res += x/(x+(x-1));
  x--;
}

printf("\nO resultado da sequencia invocado pela funcao nao recursiva é: %.2f",res);
}

int main(void) {

float x;
int f;

printf("Digite um valor para calcular a somatória da sequencia de n / (n + (n-1)) : ");
scanf("%f", &x);
printf("\nAgora, para calcular a sequencia, digite 1 para invocar uma funcao recursiva ou 2 para invocar uma funcao nao recursiva: ");
scanf("%d", &f);

if(f==1){
  x = recursiva(x);
  printf("\nO resultado da sequencia calculado pela funcao recursiva é: %.2f",x);
}
else if(f==2){
  naoRecursiva(x);
}
else{
  printf("\n\n\nValor incorreto!!!");
}

}