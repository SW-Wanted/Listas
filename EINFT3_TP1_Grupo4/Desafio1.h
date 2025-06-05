typedef struct NoSimples LLS;

// a. Criar lista
LLS * InicializarLLS();

// b. Inserir nó numa posição específica
void InserirNaPosicaoLLS(LLS ** l, int valor, int posicao);

// c. Remover nó
void RemoverElementoLLS(LLS ** l, int valor);

// d. Procurar elemento
LLS * ProcurarElementoLLS(LLS * l, int valor);

// e. Criar duas listas com interseção em forma de Y
void CriarLLSIntersecao(LLS ** lista1, LLS ** lista2, int * vetor1, int * vetor2, int tam1, int tam2, int valorIntersecao);

// f. Imprimir as listas criadas na alínea anterior
void ImprimirLLS(LLS * l);

// g. Eliminar a Lista Ligada Simples
void EliminarLLS(LLS ** l);
