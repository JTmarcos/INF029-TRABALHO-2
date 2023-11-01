#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "EstruturaVetores.h"
int ehPosicaoValida();
No vetorPrincipal[TAM];

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Retorno (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho) {

  int retorno = 0;
  if (posicao < 1 || posicao > 10) {

    return POSICAO_INVALIDA;
  }
  if (vetorPrincipal[posicao - 1].aux != NULL) {
    return JA_TEM_ESTRUTURA_AUXILIAR;
  }

  // o tamanho ser muito grande
  retorno = SEM_ESPACO_DE_MEMORIA;

  if (tamanho < 1) {
    return TAMANHO_INVALIDO;
  }
  // deu tudo certo, crie

  vetorPrincipal[posicao - 1].aux = malloc(tamanho * sizeof(int));
  vetorPrincipal[posicao - 1].tamTotal = tamanho;
  return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor) {
  int retorno = 0;
  int existeEstruturaAuxiliar = 0;
  int temEspaco = 0;
  int posicao_invalida = 0;

  if (posicao < 1 || posicao > 10) {
    posicao_invalida = 1;
  }

  if (vetorPrincipal[posicao].aux == NULL) {
    existeEstruturaAuxiliar = 0;

  } else {
    existeEstruturaAuxiliar = 1;
  }

  if (vetorPrincipal[posicao - 1].qntColocados ==
      vetorPrincipal[posicao - 1].tamTotal) {
    temEspaco = 0;

  } else {
    temEspaco = 1;
  }

  if (posicao_invalida)
    retorno = POSICAO_INVALIDA;
  else {
    // testar se existe a estrutura auxiliar
    if (vetorPrincipal[posicao - 1].aux != NULL) {
      existeEstruturaAuxiliar = 1;
    }

    if (existeEstruturaAuxiliar) {
      if (temEspaco) {
        // insere

        vetorPrincipal[posicao - 1]
            .aux[vetorPrincipal[posicao - 1].qntColocados] = valor;
        vetorPrincipal[posicao - 1].qntColocados++;
        retorno = SUCESSO;
      } else {
        retorno = SEM_ESPACO;
      }
    } else {
      retorno = SEM_ESTRUTURA_AUXILIAR;
    }
  }

  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar
da seguinte forma [3, 8, 7,  ,  ,  ]. Obs. Esta é uma exclusão lógica


Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int estaVazio(int posicao) {
  if (vetorPrincipal[posicao - 1].qntColocados == 0) {
    return ESTRUTURA_AUXILIAR_VAZIA;
  } else {
    return -999;
  }
}
int semEstruturaAuxiliar(int posicao) {
  if (vetorPrincipal[posicao - 1].aux == NULL) {
    return SEM_ESTRUTURA_AUXILIAR;
  } else {
    return -999;
  }
}
int excluirNumeroDoFinaldaEstrutura(int posicao) {

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
    return POSICAO_INVALIDA;
  }

  if (semEstruturaAuxiliar(posicao) == SEM_ESTRUTURA_AUXILIAR) {
    return SEM_ESTRUTURA_AUXILIAR;
  }

  if (estaVazio(posicao) == ESTRUTURA_AUXILIAR_VAZIA) {

    return ESTRUTURA_AUXILIAR_VAZIA;
  }

  vetorPrincipal[posicao - 1].qntColocados--;

  return SUCESSO;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições
anteriores ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o
valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ] Obs. Esta é
uma exclusão lógica Rertono (int) SUCESSO - excluido com sucesso 'valor' da
estrutura na posição 'posicao' ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
    return POSICAO_INVALIDA;
  }

  if (semEstruturaAuxiliar(posicao) == SEM_ESTRUTURA_AUXILIAR) {
    return SEM_ESTRUTURA_AUXILIAR;
  }

  if (estaVazio(posicao) == ESTRUTURA_AUXILIAR_VAZIA) {

    return ESTRUTURA_AUXILIAR_VAZIA;
  }

  int aux = 0, apagou = 0;

  for (int i = 0; i < vetorPrincipal[posicao - 1].qntColocados; i++) {

    if (vetorPrincipal[posicao - 1].aux[i] == valor) {
      vetorPrincipal[posicao - 1].qntColocados--;

      for (i = i; i < vetorPrincipal[posicao - 1].qntColocados; i++) {

        vetorPrincipal[posicao - 1].aux[i] =
            vetorPrincipal[posicao - 1].aux[i + 1];
      }

      return SUCESSO;
    }
  }

  return NUMERO_INEXISTENTE;
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao) {
  int retorno = 0;
  if (posicao < 1 || posicao > 10) {
    retorno = POSICAO_INVALIDA;
  } else
    retorno = SUCESSO;

  return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
    return POSICAO_INVALIDA;
  }

  if (semEstruturaAuxiliar(posicao) == SEM_ESTRUTURA_AUXILIAR) {
    return SEM_ESTRUTURA_AUXILIAR;
  }

  if (estaVazio(posicao) == ESTRUTURA_AUXILIAR_VAZIA) {

    return ESTRUTURA_AUXILIAR_VAZIA;
  }

  for (int i = 0; i < vetorPrincipal[posicao - 1].qntColocados; i++) {
    vetorAux[i] = vetorPrincipal[posicao - 1].aux[i];
  }

  return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao
(1..10)'. os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao
(1..10)' SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar POSICAO_INVALIDA -
Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
    return POSICAO_INVALIDA;
  }

  if (semEstruturaAuxiliar(posicao) == SEM_ESTRUTURA_AUXILIAR) {
    return SEM_ESTRUTURA_AUXILIAR;
  }

  if (estaVazio(posicao) == ESTRUTURA_AUXILIAR_VAZIA) {

    return ESTRUTURA_AUXILIAR_VAZIA;
  }

  for (int i = 0; i < vetorPrincipal[posicao - 1].qntColocados; i++) {
    vetorAux[i] = vetorPrincipal[posicao - 1].aux[i];
  }
  int j;

  for (int i = 1; vetorPrincipal[posicao - 1].qntColocados > i; i++) {
    int aux = vetorAux[i];
    j = i - 1;
    while (j >= 0 && vetorAux[j] > aux) {
      vetorAux[j + 1] = vetorAux[j];
      j--;
    }
    vetorAux[j + 1] = aux;
  }

  return SUCESSO;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
  int achou = 0, posi = 0;
  for (int i = 0; i < 10; i++) {
    if (vetorPrincipal[i].qntColocados > 0) {
      achou = 1;
      for (int j = 0; j < vetorPrincipal[i].qntColocados; j++) {
        vetorAux[posi] = vetorPrincipal[i].aux[j];
        posi++;
      }
    }
  }
  if (achou == 1) {

    return SUCESSO;
  } else {
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição
'posicao' TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares
estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {

  int achou = 0, posi = 0;
  for (int i = 0; i < 10; i++) {
    if (vetorPrincipal[i].qntColocados > 0) {
      achou = 1;
      for (int j = 0; j < vetorPrincipal[i].qntColocados; j++) {
        vetorAux[posi] = vetorPrincipal[i].aux[j];
        posi++;
      }
    }
  }

  if (achou == 1) {
    int j;
    for (int i = 1; posi > i; i++) {
      int aux = vetorAux[i];
      j = i - 1;
      while (j >= 0 && vetorAux[j] > aux) {
        vetorAux[j + 1] = vetorAux[j];
        j--;
      }
      vetorAux[j + 1] = aux;
    }
    return SUCESSO;
  } else {
    return TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  }
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o
novo tamanho 'novoTamanho' + tamanho atual Suponha o tamanho inicial = x, e novo
tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser
sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
    return POSICAO_INVALIDA;
  }

  if (semEstruturaAuxiliar(posicao) == SEM_ESTRUTURA_AUXILIAR) {
    return SEM_ESTRUTURA_AUXILIAR;
  }

  if (estaVazio(posicao) == ESTRUTURA_AUXILIAR_VAZIA) {

    return ESTRUTURA_AUXILIAR_VAZIA;
  }
  if (novoTamanho + vetorPrincipal[posicao - 1].tamTotal < 1) {
    return NOVO_TAMANHO_INVALIDO;
  }
  int *blocoAntigo = vetorPrincipal[posicao - 1].aux;

  int *novoBloco = (int *)realloc(
      vetorPrincipal[posicao - 1].aux,
      (vetorPrincipal[posicao - 1].tamTotal + novoTamanho) * sizeof(int));

  vetorPrincipal[posicao - 1].aux = novoBloco;
  vetorPrincipal[posicao - 1].tamTotal += novoTamanho;

  if (vetorPrincipal[posicao - 1].tamTotal <
      vetorPrincipal[posicao - 1].qntColocados) {
    vetorPrincipal[posicao - 1].qntColocados =
        vetorPrincipal[posicao - 1].tamTotal;
  }

  for (int i = 0; i < vetorPrincipal[posicao - 1].qntColocados; i++) {
    vetorPrincipal[posicao - 1].aux[i] = blocoAntigo[i];
  }
  

  return SUCESSO;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da
posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da
estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao) {

  if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
    return POSICAO_INVALIDA;
  }

  if (semEstruturaAuxiliar(posicao) == SEM_ESTRUTURA_AUXILIAR) {
    return SEM_ESTRUTURA_AUXILIAR;
  }

  if (estaVazio(posicao) == ESTRUTURA_AUXILIAR_VAZIA) {

    return ESTRUTURA_AUXILIAR_VAZIA;
  }

  return vetorPrincipal[posicao - 1].qntColocados;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes
em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/

lista *montarListaEncadeadaComCabecote() {
  lista *novo = (lista *)malloc(sizeof(lista));
  return novo;
}

lista *CriarLista(int valor) {
  lista *novo = (lista *)malloc(sizeof(lista));
  novo->valor = valor;
  novo->prox = NULL;

  return novo;
}

void inserirNoFim(lista **head, int valor) {
  lista *novo = CriarLista(valor);

  lista *current = *head;

  while (current->prox != NULL) {
    current = current->prox;
  }

  current->prox = novo;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em
vetorAux. Retorno void
*/
void getDadosListaEncadeadaComCabecote(lista *inicio, int vetorAux[]) {
  for (int i = 0; i < 10; i++) {
    if (vetorPrincipal[i].qntColocados != 0) {
      for (int j = 0; j < vetorPrincipal[i].qntColocados; j++) {
        inserirNoFim(&inicio, vetorPrincipal[i].aux[j]);
      }
    }
  }

  lista *current = inicio->prox;
  int i = 0;
  while (current != NULL) {
    vetorAux[i] = current->valor;
    current = current->prox;
    i++;
  }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno
    void.
*/
void destruirListaEncadeadaComCabecote(lista **inicio) {

 *inicio = NULL;
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa

*/

void inicializar() {
  for (int i = 0; i < TAM; i++) {
    vetorPrincipal[i].aux = NULL;
    vetorPrincipal[i].qntColocados = 0;
    vetorPrincipal[i].tamTotal = 0;
  }
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar() {
  for (int i = 0; i < 10; i++) {
    free(vetorPrincipal[i].aux);
  }
}