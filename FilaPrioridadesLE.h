#define RESET "\033[0m"
#define BOLD "\033[1m"
#define RED "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define WHITE "\033[37m"

struct no {
    int info;
    int prior;
    no *link;
};

no *inicializaFP(no *L)
{
    L = NULL;
    return L;
}

no *insereFP(no *L, int valor, int prior)
{
    no *N, *P, *ANT;

    N = new no;
    N->info = valor;
    N->prior = prior;

    if (L == NULL) {
        L = N;
        N->link = NULL;
    }
    else {
        P = L;

        while ((P != NULL) && (prior >= P->prior)) {
            ANT = P;
            P = P->link;
        }
        if (P == L) {
            N->link = L;
            L = N;
        }
        else {
            ANT->link = N;
            N->link = P;
        }
    }
    return L;
}

no *removeFP(no *L, int *n, int * prior) {
	no *AUX;

	if (L != NULL) {
		*n = L->info;
		*prior = L->prior; 
		AUX = L;
		L = L->link;
		delete AUX;
	}
	return L;
}

int verificaSeVazia(no *L) {
	if (L == NULL)
		return 1;
	else
		return 0;
}

void exibe(no *L)
{
    no *P = L;
    cout << " ";
    while (P != NULL) {
		//cout << BOLD << "VOO " << P->info << " (Prioridade: " << P->prior << ")" << " | " << RESET;
        cout << BOLD << "VOO " << P->info;

        if(P->prior == 1) {
            cout << RED;
        }
        else if(P->prior == 2) {
            cout << BLUE;
        }
        else {
            cout << MAGENTA;
        }

        cout << " (Prioridade: " << P->prior << ")" << RESET << BOLD << " | " << RESET;

        P = P->link;
    }
    cout << '\n' << endl;
}

no* insereFilaChegada(no *L, int data, int prior) {
	no *P, *N;

	N = (no *) malloc (sizeof(no)); 
	N->info = data; 
	N->prior = prior; 
	N->link = NULL; 
	 
	if (L == NULL){ 
		L = N;
	}
	else { 
		P = L;	
	
		while(P->link != NULL) {
			P = P->link;
		}
		P->link = N;
	} 
	return L;
}