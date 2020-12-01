typedef struct no No;
typedef struct sapato Sapato;

No *inicializar();
No *criarNo(int valor);
No *inserir(No *raiz, No *no);
No *retira(No *raiz, No *no);
void mostrar(No *raiz);
void buscar(No *raiz, int valor);
void liberarMemoria(No *raiz);