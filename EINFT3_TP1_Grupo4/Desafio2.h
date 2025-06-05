typedef struct NoCircular LCD;

// a. Inicializar lista
LCD * InicializarLCD();

// b. Inserir n� numa posi��o espec�fica
void InserirNaPosicaoLCD(LCD ** l, int valor, int posicao);

// c. Remover n�
void RemoverElementoLCD(LCD ** l, int valor);

// d. Imprimir a lista
void ImprimirLCD(LCD * l);

// e. Procurar elemento
LCD * ProcurarElementoLCD(LCD * l, int valor);

// f. Remover n�meros pares e �mpares alternadamente at� restar um �nico n�mero
void RemoverAlternadamenteLCD(LCD ** l);

// g. Eliminar a lista Circular Duplamente Ligada
void EliminarLCD(LCD ** l);

