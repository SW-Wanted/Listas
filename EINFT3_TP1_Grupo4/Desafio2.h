typedef struct NoCircular LCD;

// a. Inicializar lista
LCD * InicializarLCD();

// b. Inserir nó numa posição específica
void InserirNaPosicaoLCD(LCD ** l, int valor, int posicao);

// c. Remover nó
void RemoverElementoLCD(LCD ** l, int valor);

// d. Imprimir a lista
void ImprimirLCD(LCD * l);

// e. Procurar elemento
LCD * ProcurarElementoLCD(LCD * l, int valor);

// f. Remover números pares e ímpares alternadamente até restar um único número
void RemoverAlternadamenteLCD(LCD ** l);

// g. Eliminar a lista Circular Duplamente Ligada
void EliminarLCD(LCD ** l);

