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
		cout <<"["<< pila->dato << "] ";
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
		cout << " ["<<frente->dato << "] ";
		frente = frente->siguiente;
	}
	cout << endl;
}

int main() {
	pnodo pila, frente, final;
	int contador;
	int opcion, valor;
	
	InitStack(pila);
	InitQueue(frente, final, contador);
	
	do {
		cout << "-------- MENU --------" << endl << endl;
		cout << "----> PILA <----"<<endl; 
		cout << "1. Push a la Pila" << endl;
		cout << "2. Pop de la Pila" << endl;
		cout << "3. Mostrar Pila" << endl;
		cout << "4. Ver Top de la Pila" << endl;
		cout << "------> COLA <------"<< endl;
		cout << "5. Push a la Cola" << endl;
		cout << "6. Pop de la Cola" << endl;
		cout << "7. Mostrar Cola" << endl;
		cout << "8. Ver Frente de la Cola" << endl;
		cout << "9. Ver Final de la Cola" << endl;
		cout << "0. Salir" << endl;
		cout << "Opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Ingrese valor para la pila: ";
			cin >> valor;
			PushStack(pila, valor);
			break;
		case 2:
			cout << "Pop Pila: " << PopStack(pila) << endl;
			break;
		case 3:
			ShowStack(pila);
			break;
		case 4:
			cout << "Top Pila: " << TopStack(pila) << endl;
			break;
		case 5:
			cout << "Ingrese valor para la cola: ";
			cin >> valor;
			PushQueue(frente, final, valor, contador);
			break;
		case 6:
			cout << "Pop Cola: " << PopQueue(frente, final, contador) << endl;
			break;
		case 7:
			ShowQueue(frente);
			break;
		case 8:
			cout << "Frente Cola: " << TopQueue(frente) << endl;
			break;
		case 9:
			cout << "Final Cola: " << BottomQueue(final) << endl;
			break;
		case 0:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opción inválida." << endl;
		}
		system("pause");
		system("cls");
	} while (opcion != 0);
	
	return 0;
}

