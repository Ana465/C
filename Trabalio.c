#include <stdio.h>

void DesenhaLinha(void);//fun��o que n�o retorna valor e desenha uma linha composta por caracteres
float calcula(float p, float h);//fun��o para calcular o IMC

int main(){

    int i, opcao, quantidade;//variaveis inteiras: i para o contador, op��o para o n�mero escolhido no MENU e quantidade para quantas pessoas ter�o o IMC calculado
    float altura[10], peso[10], result;//variaveis de ponto flutuante para armzenamento do resultado do calculo e dois vetores tipo float para armazenamento dos dados "peso" e "altura"
    char nome[10][10];//matriz para armazenar o nome do usu�rio com tamanho m�ximo de dez caracteres

    printf("\n\tEste programa realizara o calculo do IMC (indice de massa corporea).\n");//print de apresenta��o do programa
    DesenhaLinha();//chamamento da fun��o para desenhar a linha de caracteres
    printf("\n");//linha a mais para separar o titulo do menu

    do{//inicio do Do While, para realizar as seguintes fun��es enquanto o valor digitado para a op��o n�o for zero
        printf("\nMENU:\nCalcular IMC - 1\nVer Tabela - 2\nSair - 0\nDigite a opcao desejada: ");//print para mostrar o menu do programa
        scanf("%d", &opcao);//leitura do valor digitado para a op��o escolhida

        if(opcao!=1 && opcao!=2 && opcao!=0){//compara��o para mostrar quando o valor inserido n�o se encontra no menu, tornando a op��o inv�lida e mostrando novamente o menu

            printf("\nOPCAO INVALIDA!\n");//aviso de op��o inv�lida
        }

        switch(opcao){//especifica��o do que ir� acontecer nos casos de op��o digitada pelo usu�rio
            case 1://especifica��o do que ir� acontecer caso a op��o selecionada do MENU seja '1'
                printf("\nInforme a quantidade de pessoas que terao o IMC calculado -nao pode ultrapassar de 10-: ");//pede para que o usu�rio especifique a quantidade de pessoas que ele quer que tenham o c�lculo do IMC realizado, avisando que o limite � 10
                scanf("%d", &quantidade);//leitura do valor inteiro digitado, armazenando-o na vari�vel "quantidade

                if(quantidade>10){//verifica��o para o caso da quantidade inserida ultrapassar o limite permitido
                    printf("\nLimite de quantidade de pessoas ultrapassado.");//aviso de que o limimte foi ultrapassado
                    break;//para o la�o e volta no menu
                }

                    for(i = 0; i<quantidade; i++){//la�o de repeti��o que rodar� incrementando o contador inicializado em 0, at� que o mesmo atinja o n�mero limite de quantidade de pessoas
                        printf("\nNome: ");//leitura do nome
                        scanf("%s", nome[i]);//armazenamento do nome no vetor de caracteres
                        printf("Insira os dados separando-os com um ponto para separar as casas decimais, ao inves de virgulas.\nEX: Peso: 60.7 e Altura: 1.70.");//aviso para que o usu�rio insira os dados separando casas decimais com um ponto, porque, ao usar virgula, iria ocorrer um erro no programa devido ao padr�o da linguagem C.
                        printf("\nAltura: ");//leitura da altura
                        scanf("%f", &altura[i]);//armazenamento da altura na posi��o do vetor "altura"
                        printf("Peso: ");//leitura do peso
                        scanf("%f", &peso[i]);//armazenamento do valor lido na posi��o do vetor "peso"

                        DesenhaLinha();//chamamento da fun��o para separar as partes do programa para que a visualiza��o dos resultados torne-se mais identific�vel

                        result = calcula(peso[i], altura[i]);//vari�vel "result" recebendo o resultado do c�lculo da fun��o, para a qual foi passada como par�metro o peso e a altura lidos

                        printf("\nIMC %s: %.2f\n", nome[i], result);//mostra o nome da pessoa e seu imc
                    }
                    break;
            case 2://especifica��o do que ir� acontecer caso a op��o selecionada do MENU seja '2'
                printf("\n\t ");DesenhaLinha();
                printf("\n\t\t      IMC        -----    SITUACAO\n\t\tMenor que 17       -  MUITO ABAIXO DO PESO\n\t\tEntre 17 e 18,49   -  ABAIXO DO PESO\n\t\tEntre 18,5 e 24,99 -  PESO NORMAL\n\t\tEntre 25 e 29,99   -  ACIMA DO PESO\n\t\tEntre 30 e 34,99   -  OBESIDADE 1\n\t\tEntre 35 e 39,99   -  OBESIDADE 2 (severa)\n\t\tAcima de 40        -  OBESIDADE 3 (morbida)");//valores para a tabela tabulados.
                printf("\n\t   ");DesenhaLinha();
                printf("\n");
                break;
           }//fim da parte do switch (op��o)
                }while(opcao!=0);//para o la�o quando a opcao digitada for 0
}//fim do int main
void DesenhaLinha(void){//especifica��o da fun��o que n�o retorna valor
         printf("\t     =================================");//printa na tela um conjunto de caracteres '=' quando chamada no int main
}//fim da parte do c�digo da fun��o DesenhaLinha
float calcula(float p, float h){//especifica��o da fun��o que calcula o imc, tendo variaveis float para receber o peso e a altura
         return  p/(h*h);//retorna como valor o c�lculo do peso dividido pela altura vezes altura

}//fim da parte do c�digo da fun��o Calcula
