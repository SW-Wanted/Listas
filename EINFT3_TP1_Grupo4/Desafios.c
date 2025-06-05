#include <stdio.h>
#include <stdlib.h>
#include "Desafio1.h"
#include "Desafio2.h"

// ====================  D E S A F I O - 1  ==================== //

// Lista ligada simples
struct NoSimples {
    int valor;
    struct NoSimples * prox;
};

// a. Inicializar lista
LLS * InicializarLLS() {
    return NULL;
}

// b. Inserir nó numa posição específica
void InserirNaPosicaoLLS(LLS ** l, int valor, int posicao) {
	LLS * novo = (LLS*)malloc(sizeof(LLS));
	if(!novo)
	{
		printf("[Erro] Nao foi possivel fazer a alocacao de memoria!\n");
		exit(1);
	}
	
	if (posicao < 0)
	{
	    printf("[Erro] Posicao Invalida: \'%d\' \n", posicao);
		return;
	}
	
    novo->valor = valor;
	    
    if (posicao == 0) {
        novo->prox = *l;
        *l = novo;
        return;
    }
    
    LLS * aux = *l;
    int i;
    for (i = 0; aux != NULL && i < posicao - 1; i++)
    	aux = aux->prox;
    
    if (aux != NULL) {
        novo->prox = aux->prox;
        aux->prox = novo;
    } 
	else
	{
		printf("[Erro] Posicao nao encontrada: \'%d\'\n", posicao);
		free(novo);
	}
}

// c. Remover Elemento
void RemoverElementoLLS(LLS ** l, int valor) {
    LLS* aux = *l;
    LLS* ant = NULL;
    while (aux != NULL && aux->valor != valor) {
        ant = aux;
        aux = aux->prox;
    }
    
    if (aux != NULL) {
        if (ant == NULL)
		    *l = aux->prox;
		else
		 	ant->prox = aux->prox;

        free(aux);
        aux = NULL;
    }
}

// d. Procurar elemento
LLS * ProcurarElementoLLS(LLS * l, int valor) {
    while (l != NULL) {
        if (l->valor == valor) return l;
        l = l->prox;
    }
    return NULL;
}

// e. Criar duas listas com interseção em forma de Y
void CriarLLSIntersecao(LLS **lista1, LLS **lista2, int *vetor1, int *vetor2, int tam1, int tam2, int valorIntersecao) {
    int i;

    for (i = 0; i < tam1; i++) {
        InserirNaPosicaoLLS(lista1, vetor1[i], i);
    }

    LLS *intersecaoNo = ProcurarElementoLLS(*lista1, valorIntersecao);
    if (!intersecaoNo) {
        printf("[Erro] Valor de intersecao nao encontrado na primeira lista!\n");
        return;
    }

    for (i = 0; i < tam2; i++) {
        if (vetor2[i] == valorIntersecao) {
            break;
        }
        InserirNaPosicaoLLS(lista2, vetor2[i], i);
    }

    if (*lista2) {
        LLS *aux = *lista2;
        while (aux->prox) {
            aux = aux->prox;
        }
        aux->prox = intersecaoNo;
    } 
	else
 		*lista2 = intersecaoNo;
}


// f. Imprimir a lista
void ImprimirLLS(LLS * l) {
	int i = 0;
    while (l != NULL) {
        printf("%d -> ", l->valor);
        l = l->prox;
        i++;
        if (i == 10)
           system("pause");
    }
    printf("NULL\n");
}

// g. Eliminar a lista
void EliminarLLS(LLS ** l) {
    LLS * aux = *l;
    while (aux != NULL) {
        LLS* temp = aux;
        aux = aux->prox;
        free(temp);
        temp = NULL;
    }
    *l = NULL;
}

// ====================  D E S A F I O - 2  ==================== //

// Lista Circular Duplamente Ligada
struct NoCircular {
    int valor;
    struct NoCircular * prox;
    struct NoCircular * ant;
};

// a. Inicializar lista
LCD * InicializarLCD() {
    return NULL;
}

// b. Inserir nó numa posição específica
void InserirNaPosicaoLCD(LCD **l, int valor, int posicao) {
    
    if (posicao < 0) {
        printf("[Erro] Posicao Invalida: \'%d\'\n", posicao);
        return;
    }
    
	LCD *novo = (LCD *)malloc(sizeof(LCD));
	if (!novo) {
        printf("Erro de Alocacao!\n");
        exit(1);
    }
     
    novo->valor = valor;

    if (*l == NULL) {
        if (posicao == 0) {
            novo->prox = novo;
            novo->ant = novo;
            *l = novo;
        } else { 
            printf("[Erro] Posicao nao encontrada: \'%d\'\n", posicao);
            free(novo);
        }
        return;
    }

    LCD *aux = *l;

    if (posicao == 0) {
        novo->prox = *l;
        novo->ant = aux->ant;
        aux->ant->prox = novo;
        aux->ant = novo;
        *l = novo;
        return;
    }
    
	int i;
    for (i = 0; i < posicao - 1 && aux->prox != *l; i++)
    	aux = aux->prox;
    	
    if (i == posicao - 1) {
        novo->prox = aux->prox;
        novo->ant = aux;
        aux->prox->ant = novo;
        aux->prox = novo;
    } else {
        printf("[Erro] Posicao nao encontrada: \'%d\'\n", posicao);
        free(novo);
    }
}

// c. Remover Elemento
void RemoverElementoLCD(LCD ** l, int valor) {
    if (*l == NULL) return;
    LCD* aux = *l;
    do {
        if (aux->valor == valor) {
            if (aux->prox == aux) {
                *l = NULL;
            } else {
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
                if (*l == aux) *l = aux->prox;
            }
            free(aux);
            aux = NULL;
            return;
        }
        aux = aux->prox;
    } while (aux != *l);
}

// d. Imprimir a lista
void ImprimirLCD(LCD * l) {
    if (l == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    LCD* aux = l;
    do {
        printf("%d <-> ", aux->valor);
        aux = aux->prox;
    } while (aux != l);

    printf("(circular)\n");
}
// e. Procurar elemento
LCD* ProcurarElementoLCD(LCD * l, int valor) {
    LCD* aux = l;
    if (l == NULL) return NULL;
    do {
        if (aux->valor == valor) return aux;
        aux = aux->prox;
    } while (aux != l);
    return NULL;
}

// f. Remover números pares e ímpares alternadamente até restar um único número
void RemoverAlternadamenteLCD(LCD **l) {
    if (*l == NULL) return;
    
	// Se o útlimo elemento da lista for 'par', então a rodada começa por eliminar os 'ímpares'.
	// » O inverso também acontece.	 
    int removerPar = (*l)->ant->valor % 2 == 0 ? 0 : 1;
    
	while ((*l)->prox != *l) {
        LCD * aux = *l;
        do {
            LCD * temp = aux->prox;
            
            if ((removerPar && aux->valor % 2 == 0) || (!removerPar && aux->valor % 2 != 0)) {
                printf("Removendo %s: %d\n", removerPar ? "par" : "impar", aux->valor);
                RemoverElementoLCD(l, aux->valor);
            }
            aux = temp;
        } while (aux != aux->ant && aux->prox != *l);
        removerPar = !removerPar;
    }
    printf("Valor restante: %d\n", (*l)->valor);
}

// g. Eliminar a lista
void EliminarLCD(LCD ** l) {
    if (*l == NULL) return;
    LCD* aux = *l;
    do {
        LCD * temp = aux;
        aux = aux->prox;
        free(temp);
        temp = NULL;
    } while (aux != *l);
    *l = NULL;
}

main()
{
	// TESTE AQUI TODAS AS OPERAÇÕES DOS DESAFIOS
	
}
