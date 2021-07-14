#include <stdio.h>
#include <stdlib.h>

typedef struct Inscricoes {
	int RG;
	int partido;
 	} Inscricoes;

int inscritos(int d) {
	
	int aux, tam;
	Inscricoes inscritos[20];
	
	for(aux=0;aux<20;aux++){
		inscritos[aux].partido=0;
		inscritos[aux].RG=0;
	}
	
	printf("\nQuantos inscritos para o %do dia?", d);
	scanf("%d",&tam);
	if(tam>20){
		printf("\nACIMA DO SUPORTADO - Maximo de inscritos por dia eh 20");
		tam=20;
	}
	
	for(aux=0;aux<tam;aux++){
		printf("\n\n___%do INSCRITO (%do dia)___", aux+1, d);
		printf("\nCodigo do partido do inscrito:");
		scanf("%d", &inscritos[aux].partido);
		while(inscritos[aux].partido!=10 && inscritos[aux].partido!=12 && inscritos[aux].partido!=13 && inscritos[aux].partido!=22 && inscritos[aux].partido!=65){
			printf("\nERRO - codigo do partido nao reconhecido...\n");
			printf("\nCodigo do partido do inscrito:");
			scanf("%d", &inscritos[aux].partido);
		}
		printf("RG do inscrito (somente numeros):");
		scanf("%d", &inscritos[aux].RG);
		while(inscritos[aux].RG<=0){
			printf("\nERRO - RG invalido\n");
			printf("\nRG do inscrito (somente numeros):");
			scanf("%d", &inscritos[aux].RG);
		}
	}
	
	int testePartido, aux1, aux2;
	Inscricoes pergunta;
	Inscricoes responde;
	
	pergunta.RG= inscritos[0].RG;
	pergunta.partido=inscritos[0].partido;
	
	printf("\nFIM DAS INSCRICOES DO DIA %d", d);
	printf("\nDando inicio as perguntas...");
	printf("\nRG de numero %d do partido %d pergunta",pergunta.RG, pergunta.partido);
	for(aux1=0;aux1<tam;aux1++){
		printf("\nPara qual partido eh dirigida a pergunta?");
		scanf("%d", &testePartido);
		while(testePartido!=10 && testePartido!=12 && testePartido!=13 && testePartido!=22 && testePartido!=65){
			printf("\nERRO - codigo do partido nao reconhecido...\n");
			printf("\nPara qual partido eh dirigida a pergunta?");
			scanf("%d", &testePartido);
		}
		for(aux=0;aux<tam;aux++){
			if(testePartido==inscritos[aux].partido){
				for(aux2=0;aux2<tam;aux2++){
					if(inscritos[aux2].RG!=0){
						responde.partido=inscritos[aux].partido;
						responde.RG=inscritos[aux2].RG;
						inscritos[aux2].RG=0;//RG sendo 0 anulaa oportuindade de nova pergunta do representante
						if(podePerguntar(inscritos[aux2].RG)==1 && pergunta.RG!=responde.RG){
							printf("\nRG de numero %d do partido %d responde", responde.RG, responde.partido);
							printf("\n*\n*\n*\n");
							pergunta.partido=responde.partido;
							pergunta.RG=responde.RG;				
							printf("RG de numero %d do partido %d pergunta", pergunta.RG, pergunta.partido);
						}			
					}
				}
			}
		}
	}
}

int podePerguntar(int teste) {
	if(teste==0){
		return 1;
	}
	else{
		return 0;
	}
}

int main() {
	
	int dia;
	
	printf("Para a prefeitura de Campinas, existem 5 candidatos:");
	printf("\nDario Saadi - REPUBLICANOS(10)");
	printf("\nHelio de Oliveira - PDT(12)");
	printf("\nPedro Tourinho - PT(13)");
	printf("\nRafa Zimbaldi - PL(22)");
	printf("\nAlessandra - PCdoB(65)");
	
	printf("\nEm um forum, representantes de cada partido farão perguntas para debater sobre a eleição.\n");
	printf("Serão feitas no maximo 20 perguntas por dia, durante 5 dias e o programa ordena quem faz a pergunta.\n");
	
	for(dia=1;dia<6;dia++){
		inscritos(dia);
	}
	
	
	return 0;
}
