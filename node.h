typedef struct Node {
  int valor;
  struct Node *anterior;
  struct Node *proximo;

} Node;


void insereInicio(int valor);

void insereFim(int valor);

void removeInicio();

void removeFim();

void removeNumero(int valor);

int tamanho();

int buscar(int valor);
