#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>
#include <string.h>


int converteBinarioDecimal(char x[]);
void verificaTamanho(char x[]);
void verificaBinario(char x[]);
void validadorNumero(char x[]);
int executaUla(int valorDecimal1, int valorDecimal2, int opDecimal,);
void exibirMenu();


int main ()
{
	setlocale(LC_ALL,"Portuguese");
	
	char valorBinario1[10], valorBinario2[10], opBinario[10];
	int valorDecimal1, valorDecimal2, opDecimal, opMenu;


	exibirMenu();
	scanf("%d",&opMenu);
    
	while (opMenu != 8){
		
		switch (opMenu) {
			
			case 1:{
				printf("\n Entre com o valor para o Registrador A: ");
				scanf("%s", &valorBinario1);
				validadorNumero(valorBinario1);
				valorDecimal1 = converteBinarioDecimal(valorBinario1); break;
			}
			case 2:{
				printf("\n Entre com o valor para o Registrador B:");
	    		scanf("%s", &valorBinario2);
	    		validadorNumero(valorBinario2);
				valorDecimal2 = converteBinarioDecimal(valorBinario2); break;
			}
			case 3:{
				printf("\n %d", valorDecimal1); 
				break;
			}
			case 4:{
				printf("\n %d", valorDecimal2);
				break;
			}
			case 5:{
				break;
			}
			case 6:{
	    			printf("\n Entre com a operação:");
	    			scanf("%s",&opBinario);
	    			validadorNumero(opBinario);
					opDecimal = converteBinarioDecimal(opBinario); break;
			}
			case 7:{
					int resultado = executaUla(valorDecimal1, valorDecimal2, opDecimal);
					valorDecimal1 = valorDecimal1 + resultado;
					printf("\n Resultado da Operação: %d \n", resultado);break;
			}
			case 8:{
				return 0;
				break;
			}
			default:
				printf("Opção inválida!"); break;
		}
		exibirMenu();
		scanf("%d",&opMenu);
		
	}
    
   	int x = executaUla(valorDecimal1, valorDecimal2, opDecimal);
	printf("%d", x);
	
	
	return 0;
}


/* MÉTODOS */

void exibirMenu(){
	printf("\n");
	printf("----------------------------\n");
	printf("    MENU PRINCIPAL ULA      \n");
	printf("----------------------------\n");
	printf("1 - Definir Registrador A\n");
    printf("2 - Definir Registrador B\n");
    printf("3 - Ler Registrador A\n");
    printf("4 - Ler Registrador B\n");
    printf("5 - Ler Registrador de Flags\n");
    printf("6 - Definir Operação\n");
    printf("7 - Executar ULA \n");
    printf("8 - Sair\n");
    printf("----------------------------\n");
	printf("Entre com a opção:");
}


int executaUla(int valorDecimal1, int valorDecimal2, int opDecimal){
	int resultado = 0;
	switch (opDecimal)
    
    {
    	case 0:{
    		resultado = valorDecimal1+valorDecimal2; break;			
		}
		case 1:{
			resultado = valorDecimal1-valorDecimal2; break;
		}
		case 2:{
			resultado = valorDecimal1*valorDecimal2; break;
		}
		case 3:{
			resultado = valorDecimal1/valorDecimal2; break;
		}
		case 4:{
			resultado = sqrt(valorDecimal1); break;
		}
		case 5:{
			resultado = sqrt(valorDecimal1) + sqrt(valorDecimal2); break;
		}
		case 6:{
			resultado = pow(valorDecimal1,2); break;
		}
		case 7:{
			resultado = pow(valorDecimal1,2) + pow(valorDecimal2,2); break;
		}
		default:
			resultado = 00; break;
	}
	
	return resultado;
}

void validadorNumero(char x[]){
	verificaBinario(x);
	verificaTamanho(x);
}

void verificaBinario(char x[]){
	int i, tam;
	tam = strlen(x); //VERIFICA O TAMANHO DO NUMERO INFORMADO
	
	for (i = tam-1; i >= 0; i--) {
	
		if(x[i]!= '1' && x[i] != '0') { // VERIFICA SE O NÚMERO É DIFERENTE DE 0 E 1
			printf("nao binario"); // ALERTA CASO O NÚMERO NÃO SEJA BINARIO
			exit(0); // ENCERRA A EXECUÇÃO DO PROGRAMA
		}
	}
}

void verificaTamanho(char x[]){
	int tam = strlen(x); //VERIFICA O TAMANHO DO NUMERO INFORMADO;
	
	
	if(tam > 5){ //CONFERE SE O NUMERO NÃO ULTRAPASSOU O LIMITE
		printf("Limite Excedido \n");// Alerta caso tenha ultrapassado
		system ("pause");
		exit(0);
	}
}

int converteBinarioDecimal(char x[]){
	int i, tam, novoValor = 0;
	tam = strlen(x); //VERIFICA O TAMANHO DO NUMERO INFORMADO
		

    char bin[100];
    unsigned long dec = 0;
    int i = 0;
    int s;
    fgets( bin, sizeof(bin), stdin);
    s = strlen( bin );
    while( s-- ) {
        if( bin[s] == '0' || bin[s] == '1' ) {
            dec = dec + pow(2, i++) * (bin[s] - '0');
        }
    };
    printf("\nDecimal Equivalente ao Numero Binario: \t %u\n", dec);
    return 0;
}