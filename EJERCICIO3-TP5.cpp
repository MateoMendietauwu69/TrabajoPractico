#include <iostream>
using namespace std;

typedef struct tnodo* pnodo;

typedef struct tnodo {
	int dato;
	pnodo siguiente;
};

typedef struct tlista {
	pnodo inicio;
	pnodo final;
	int contador; 
};

void iniciar_lista(tlista &lista);
void crearnodo(pnodo &nuevo);
void agregar_final(tlista &lista, pnodo nuevo);
void mostrar(tlista lista);
void agregar_inicio(tlista &lista, pnodo nuevo);
int cantidad_elementos(tlista lista); 
pnodo eliminar_inicio(tlista &lista);
int buscar_indice(tlista lista, int valor);
pnodo buscar_por_indice(tlista lista, int indice);

int main() {
	tlista lista;
	pnodo nuevo, eliminado;
	iniciar_lista(lista);
	
	int opcion;
	do {
		cout << "--- MENU ---"<<endl;
		cout << "1. Agregar nodo al final"<<endl;
		cout << "2. Eliminar nodo del inicio"<<endl;
		cout << "3. Mostrar lista"<<endl ;
		cout << "4. Cantidad de elementos"<<endl ;
		cout << "5. Agregar nodo al inicio"<<endl;
		cout << "6. Buscar índice de un valor" << endl;
		cout << "7. Buscar nodo por índice" << endl;
		cout << "0. Salir" << endl;
		cout << "Opción: " << endl;
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			crearnodo(nuevo);
			agregar_final(lista, nuevo);
			break;
		case 2:
			eliminado = eliminar_inicio(lista);
			if (eliminado != NULL) {
				cout << "Eliminado: " << eliminado->dato << endl;
				delete eliminado;
			} else {
				cout << "Lista vacía, no se pudo eliminar." << endl;
			}
			break;
		case 3:
			mostrar(lista);
			break;
		case 4:
			cout << "Cantidad de elementos: " << cantidad_elementos(lista) << endl;
			break;
		case 5:
			crearnodo(nuevo);
			agregar_inicio(lista, nuevo);
			break;
		case 6: {
			int valor;
			cout << "Ingrese valor a buscar: ";
			cin >> valor;
			int indice = buscar_indice(lista, valor);
			if (indice != -1)
				cout << "Valor encontrado en posición: " << indice << endl;
			else
				cout << "Valor no encontrado." << endl;
			break;
		}
		case 7: {
			int idx;
			cout << "Ingrese índice: ";
			cin >> idx;
			pnodo buscado = buscar_por_indice(lista, idx);
			if (buscado != NULL)
				cout << "Valor en índice " << idx << " es: " << buscado->dato << endl;
			else
				cout << "Indice fuera de rango." << endl;
			break;
		}
		
		case 0:
			cout << "Saliendo..." << endl;
			break;
		default:
			cout << "Opción inválida." << endl;
		}
		system("pause");
		system ("cls");
	} while (opcion != 0);
	
	return 0;
}


void iniciar_lista(tlista &lista) {
	lista.inicio = NULL;
	lista.final = NULL;
	lista.contador = 0; 
}

void crearnodo(pnodo &nuevo) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		cout << "Ingrese valor: ";
		cin >> nuevo->dato;
		nuevo->siguiente = NULL;
	} else {
		cout << "Memoria insuficiente" << endl;
	}
}

void agregar_final(tlista &lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.final = nuevo;
	} else {
		lista.final->siguiente = nuevo;
		lista.final = nuevo;
	}
	lista.contador++; 
}

pnodo eliminar_inicio(tlista &lista) {
	pnodo borrado;
	if (lista.inicio == NULL) {
		borrado = NULL;
	} else {
		borrado = lista.inicio;
		lista.inicio = lista.inicio->siguiente;
		if (lista.inicio == NULL) {
			lista.final = NULL;
		}
		borrado->siguiente = NULL;
		lista.contador--; 
	}
	return borrado;
}

void mostrar(tlista lista) {
	pnodo aux = lista.inicio;
	if (aux == NULL) {
		cout << "Lista vacía" << endl;
	} else {
		while (aux != NULL) {
			cout << aux->dato << " -> ";
			aux = aux->siguiente;
		}
		cout << "NULL" << endl;
	}
}

int cantidad_elementos(tlista lista) {
	return lista.contador;
}
void agregar_inicio(tlista &lista, pnodo nuevo) {
	if (lista.inicio == NULL) {
		lista.inicio = nuevo;
		lista.final = nuevo;
	} else {
		nuevo->siguiente = lista.inicio;
		lista.inicio = nuevo;
	}
	lista.contador++; 
}


int buscar_indice(tlista lista, int valor) {
	pnodo actual = lista.inicio;
	int indice = 0;
	
	while (actual != NULL) {
		if (actual->dato == valor) {
			return indice;
		}
		actual = actual->siguiente;
		indice++;
	}
	return -1; 
}

pnodo buscar_por_indice(tlista lista, int indice) {
	if (indice < 0 || indice >= lista.contador) {
		return NULL; 
	}
	
	pnodo actual = lista.inicio;
	int posicion = 0;
	
	while (actual != NULL && posicion < indice) {
		actual = actual->siguiente;
		posicion++;
	}
	
	return actual; 
}
