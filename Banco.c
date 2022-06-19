#include <stdio.h>

int main(){
    int numeroC1,numeroC2,numeroC3,conta,ContaOrigem,ContaDestino;
    float saldo1,saldo2,saldo3,valor;
    int escolha;
    
    //Ler número da conta 1
    printf("Numero da primeira conta a ser adicionada: ");
    scanf("%i%*c",&numeroC1);

    //Ler número da conta 2
    do{
    printf("Numero da segunda conta a ser adicionada: ");    
    scanf("%i%*c",&numeroC2);
    if(numeroC2==numeroC1)
        printf("Esse numero de conta ja esta uso.\n");
    }while(numeroC2==numeroC1);

    //Ler número da conta 3
    do{
    printf("Numero da terceira conta a ser adicionada: ");    
    scanf("%i%*c",&numeroC3);
    if(numeroC3==numeroC1 || numeroC3==numeroC2)
        printf("Esse numero de conta ja esta uso.\n");
    }while(numeroC3==numeroC1 || numeroC3==numeroC2);

    //Inicializar saldos das contas 1, 2 e 3
    saldo1=0;
    saldo2=0;
    saldo3=0;

    //Operações enquanto escolha for diferente de zero
    do{
        printf("--------------------------------");
        printf("\nMenu de operacoes: ");
        printf("\n\nCredito - digite 1");
        printf("\nDebito - digite 2");
        printf("\nTransferir - digite 3");
        printf("\nConsultar saldo - digite 4");
        printf("\nSair - digite 0\n");
        printf("\nDigite o numero da operacao: ");
        scanf("%i%*c",&escolha);
        
        //Escolha 1: Operação de crédito
        if(escolha==1){
            printf("Operacao de credito selecionada.");
            //Ler o número da conta a ser creditada
            printf("\nNumero da conta a ser creditada: ");
            scanf("%i%*c",&conta);

            //Verificar se o número da conta existe
            if(conta==numeroC1 || conta==numeroC2|| conta==numeroC3){
                
                //Ler o valor a ser creditado na conta
                do{
                printf("Digite o valor (valor>0) a ser creditado na conta %i (ou 0 para voltar ao menu): ",conta);
                scanf("%f%*c",&valor);
                if(valor<0)
                    printf("O valor a ser creditado deve ser maior que zero.\n");  
                if(valor==0)
                    printf("A opcao de voltar ao menu foi selecionada.\n");
                }while(valor<0);
                
                //Se o valor digitado for válido
                if(valor>0){
                    //Creditar o valor digitado da conta
                    if(conta==numeroC1)
                        saldo1=saldo1+valor;
                    else if(conta==numeroC2)
                        saldo2=saldo2+valor;
                    else if(conta==numeroC3)
                        saldo3=saldo3+valor;  
                    printf("Operacao de credito realizada com sucesso.\n");                  
                }
                }
            else
                printf("Numero de conta inexistente.\n");
        }

        //Escolha 2: Operação de débito
        else if(escolha==2){
            printf("Operacao de debito selecionada.");
            //Ler o número da conta a ser debitada
            printf("\nNumero da conta a ser debitada: ");
            scanf("%i%*c",&conta);

            //Verificar se o número da conta existe
            if(conta==numeroC1 || conta==numeroC2|| conta==numeroC3){
                
                //Ler o valor a ser debitado na conta
                do{
                printf("Digite o valor (valor>0) a ser debitado na conta %i (ou 0 para voltar ao menu): ",conta);
                scanf("%f%*c",&valor);
                if(valor<0)
                    printf("O valor a ser debitado deve ser maior que zero.\n");  
                if(valor==0)
                    printf("A opcao de voltar ao menu foi selecionada.\n");
                }while(valor<0);
                
                //Se o valor digitado for válido
                if(valor>0){
                    //Debitar o valor digitado da conta se o saldo for maior ou igual ao valor
                    if(conta==numeroC1){
                        if((saldo1-valor)>=0){
                            saldo1=saldo1-valor;
                            printf("Operacao de debito realizada com sucesso.\n");   
                        }                        
                        else 
                            printf("Saldo insuficiente para a realizacao do debito.\n"); 
                    }
                    else if(conta==numeroC2){
                        if((saldo2-valor)>=0){
                            saldo2=saldo2-valor;
                            printf("Operacao de debito realizada com sucesso.\n");   
                        }                        
                        else 
                            printf("Saldo insuficiente para a realizacao do debito.\n"); 
                    }
                    else if(conta==numeroC3){
                        if((saldo3-valor)>=0){
                            saldo3=saldo3-valor;
                            printf("Operacao de debito realizada com sucesso.\n");   
                        }                        
                        else 
                            printf("Saldo insuficiente para a realizacao do debito.\n"); 
                    }                   
                }
                }
            else
                printf("Numero de conta inexistente.\n");
        }

        //Escolha 3: Operação de transferência
        else if(escolha==3){
            printf("Operacao de transferencia selecionada.");
            //Ler o número da conta de origem da transferência
            printf("\nNumero da conta de origem da transferencia: ");
            scanf("%i%*c",&ContaOrigem);

            //Verificar se o número da conta de origem existe
            if(ContaOrigem==numeroC1 || ContaOrigem==numeroC2 || ContaOrigem==numeroC3){
                
                //Ler o número da conta de destino da transferência
                printf("Numero da conta de destino da transferencia: ");
                scanf("%i%*c",&ContaDestino);
                
                //Verificar se o número da conta de destino é válido
                if((ContaDestino==numeroC1 || ContaDestino==numeroC2 || ContaDestino==numeroC3)&&(ContaDestino!=ContaOrigem)){
                //Ler o valor da transferencia
                do{
                printf("Digite o valor (valor>0) da transferencia (ou 0 para voltar ao menu): ");
                scanf("%f%*c",&valor);
                if(valor<0)
                    printf("O valor da transferencia deve ser maior que zero.\n"); 
                if(valor==0)
                printf("A opcao de voltar ao menu foi selecionada.\n"); 
                }while(valor<0);
                
                //Se o valor digitado for válido
                if(valor>0){
                    //Verificar se é possível debitar o valor na conta de origem e, se for possível, adicionar à conta de destino
                    if(ContaOrigem==numeroC1){
                        if((saldo1-valor)>=0){
                            saldo1=saldo1-valor;
                            if(ContaDestino==numeroC2)
                                saldo2=saldo2+valor;
                            else if(ContaDestino==numeroC3)
                                saldo3=saldo3+valor;
                            printf("Operacao de transferencia realizada com sucesso.\n");   
                        }                        
                        else 
                            printf("Saldo da conta de origem insuficiente para a realizacao da transferencia.\n"); 
                    }
                    else if(ContaOrigem==numeroC2){
                        if((saldo2-valor)>=0){
                            saldo2=saldo2-valor;
                            if(ContaDestino==numeroC1)
                                saldo1=saldo1+valor;
                            else if(ContaDestino==numeroC3)
                                saldo3=saldo3+valor;
                            printf("Operacao de transferencia realizada com sucesso.\n");   
                        }                        
                        else 
                            printf("Saldo da conta de origem insuficiente para a realizacao da transferencia.\n");
                    }
                    else if(ContaOrigem==numeroC3){
                        if((saldo3-valor)>=0){
                            saldo3=saldo3-valor;
                            if(ContaDestino==numeroC1)
                                saldo1=saldo1+valor;
                            else if(ContaDestino==numeroC2)
                                saldo2=saldo2+valor;
                            printf("Operacao de transferencia realizada com sucesso.\n"); 
                        }                        
                        else 
                            printf("Saldo da conta de origem insuficiente para a realizacao da transferencia.\n");
                    }             
                }
                }
                else if(ContaDestino==ContaOrigem)
                    printf("A conta de destido nao pode ser igual a conta de origem da transferencia.");
                else 
                    printf("Numero de conta de destino inexistente.\n");
            }
            else
                printf("Numero de conta de origem inexistente.\n");
        }
        //Escolha 4: Consultar saldo
        else if(escolha==4){
            printf("Operacao de consultar saldo selecionada.");
            //Ler o número da conta para consultar o saldo
            printf("\nNumero da conta para consultar o saldo: ");
            scanf("%i%*c",&conta);

            //Verificar se o número da conta existe
            if(conta==numeroC1 || conta==numeroC2|| conta==numeroC3){
                if(conta==numeroC1){
                    printf("Saldo disponivel na conta %i: %.2f",conta,saldo1);
                }
                else if(conta==numeroC2){
                    printf("Saldo disponivel na conta %i: %.2f",conta,saldo2);
                }
                else if(conta==numeroC3){
                    printf("Saldo disponivel na conta %i: %.2f",conta,saldo3);
                }                
                printf("\nConsulta ao saldo realizada com sucesso.\n");
            } 
            else
                printf("Numero de conta inexistente.\n");
        }

        //Se nenhuma operação de 0 a 4 foi selecionada, escreva número de operação inválido
        else if(escolha!=0)
            printf("Numero de operacao invalido.\n");
        else if(escolha==0)
            printf("A opcao sair foi selecionada.\n");

    }while(escolha!=0);
    
    //Imprimir o nº da conta e o saldo final
    printf("--------------------------------");
    printf("\nNumero da conta / Saldo final");
    printf("\n%i \t  \t %.2f",numeroC1,saldo1);
    printf("\n%i \t  \t %.2f",numeroC2,saldo2);
    printf("\n%i \t  \t %.2f",numeroC3,saldo3);

    return 0;
}