#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};
void InitStack(pnodo &pila) {
	pila = NULL;
}

void PushStack(pnodo &pila, int valor) {
	pnodo nuevo = new tnodo;
	nuevo->dato = valor;
	nuevo->siguiente = pila;
	pila = nuevo;
}

int PopStack(pnodo &pila) {
	if (pila == NULL) {
		cout << "Pila vacía." << endl;
		return -1;
	}
	pnodo borrado = pila;
	int valor = borrado->dato;
	pila = pila->siguiente;
	delete borrado;
	return valor;
}

bool IsEmptyStack(pnodo pila) {
	return (pila == NULL);
}

int TopStack(pnodo pila) {
	if (pila == NULL) {
		cout << "Pila vacía." << endl;
		return -1;
	}
	return pila->dato;
}

void ShowStack(pnodo pila) {
	cout << "Pila (Top -> Bottom): ";
	while (pila != NULL) {
		cout << pila->dato << " ";
		pila = pila->siguiente;
	}
	cout << endl;
}
void InitQueue(pnodo &frente, pnodo &final, int &contador) {
	frente = final = NULL;
	contador = 0;
}

void PushQueue(pnodo &frente, pnodo &final, int valor, int &contador) {
	pnodo nuevo = new tnodo;
	nuevo->dato = valor;
	nuevo->siguiente = NULL;
	
	if (frente == NULL) {
		frente = final = nuevo;
	} else {
		final->siguiente = nuevo;
		final = nuevo;
	}
	contador++;
}

int PopQueue(pnodo &frente, pnodo &final, int &contador) {
	if (frente == NULL) {
		cout << "Cola vacía." << endl;
		return -1;
	}
	pnodo borrado = frente;
	int valor = borrado->dato;
	frente = frente->siguiente;
	if (frente == NULL) final = NULL;
	delete borrado;
	contador--;
	return valor;
}

bool IsEmptyQueue(pnodo frente) {
	return (frente == NULL);
}

int TopQueue(pnodo frente) {
	if (frente == NULL) {
		cout << "Cola vacía." << endl;
		return -1;
	}
	return frente->dato;
}

int BottomQueue(pnodo final) {
	if (final == NULL) {
		cout << "Cola vacía." << endl;
		return -1;
	}
	return final->dato;
}

void ShowQueue(pnodo frente) {
	cout << "Cola (Front -> Rear): ";
	while (frente != NULL) {
		cout << frente->dato << " ";
		frente = frente->siguiente;
	}
	cout << endl;
}

int main() {
	pnodo pila;
	InitStack(pila);
	
	cout << ">>> PROBANDO PILA <<<" << endl;
	PushStack(pila, 10);
	PushStack(pila, 20);
	PushStack(pila, 30);
	ShowStack(pila);
	cout << "Top de la pila: " << TopStack(pila) << endl;
	cout << "Pop: " << PopStack(pila) << endl;
	ShowStack(pila);
	cout << "¿Pila vacía? " << (IsEmptyStack(pila) ? "Sí" : "No") << endl;
	cout << endl;
	
	pnodo frente, final;
	int contador;
	InitQueue(frente, final, contador);
	
	cout << ">>> PROBANDO COLA <<<" << endl;
	PushQueue(frente, final, 100, contador);
	PushQueue(frente, final, 200, contador);
	PushQueue(frente, final, 300, contador);
	ShowQueue(frente);
	cout << "Frente de la cola: " << TopQueue(frente) << endl;
	cout << "Final de la cola: " << BottomQueue(final) << endl;
	cout << "Pop: " << PopQueue(frente, final, contador) << endl;
	ShowQueue(frente);
	cout << "¿Cola vacía? " << (IsEmptyQueue(frente) ? "Sí" : "No") << endl;
	
	return 0;
}

