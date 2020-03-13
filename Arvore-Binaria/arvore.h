
typedef struct no No;

No *inicializar();
No *criarNo(int valor);
No *inserir(No *raiz, No *no);
void mostrar(No *raiz);
void buscar(No *raiz, int valor);
void mostrarNo(No *no);
int qtdElementos(No *raiz);
int altura(No *raiz);
void liberarMemoria(No *raiz);