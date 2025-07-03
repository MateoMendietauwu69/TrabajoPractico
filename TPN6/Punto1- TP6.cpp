#include <iostream>
using namespace std;

typedef struct tnodo* pnodo;
typedef struct tnodo {
	int dato;
	pnodo sig;
	pnodo ant;
};
void IniciarLista(pnodo& inicio);
void CrearNodo(pnodo& nuevo, int valor);
void AgregarInicio(pnodo& inicio, pnodo nuevo);
void AgregarFinal(pnodo& inicio, pnodo nuevo);
void AgregarOrden(pnodo& inicio, pnodo nuevo);
pnodo QuitarInicio(pnodo& inicio);
pnodo QuitarFinal(pnodo& inicio);
pnodo QuitarNodo(pnodo& inicio, int valor);
pnodo BuscarNodo(pnodo inicio, int valor);
void MostrarLista(pnodo inicio);

int main() {
	pnodo lista;
	IniciarLista(lista);
	int opcion, valor;
	pnodo nuevo, encontrado, extraido;
	
	do {
		cout << "--- MENU LISTA DOBLEMENTE ENLAZADA ---"<<endl;
		cout << "1. Agregar al inicio"<<endl;
		cout << "2. Agregar al final"<<endl;
		cout << "3. Agregar en orden"<<endl;
		cout << "4. Quitar del inicio"<<endl;
		cout << "5. Quitar del final"<<endl;
		cout << "6. Quitar por valor"<<endl;
		cout << "7. Buscar valor"<<endl;
		cout << "8. Mostrar lista"<<endl;
		cout << "0. Salir"<<endl;
		cout << "Seleccione una opcion: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1:
			cout << "Ingrese un valor: ";
			cin >> valor;
			CrearNodo(nuevo, valor);
			AgregarInicio(lista, nuevo);
			break;
		case 2:
			cout << "Ingrese un valor: ";
			cin >> valor;
			CrearNodo(nuevo, valor);
			AgregarFinal(lista, nuevo);
			break;
		case 3:
			cout << "Ingrese un valor: ";
			cin >> valor;
			CrearNodo(nuevo, valor);
			AgregarOrden(lista, nuevo);
			break;
		case 4:
			extraido = QuitarInicio(lista);
			if (extraido != NULL) {
				cout << "Nodo extraido con valor: " << extraido->dato << endl;
				delete extraido;
			} else {
				cout << "Lista vacía."<<endl;
			}
			break;
		case 5:
			extraido = QuitarFinal(lista);
			if (extraido != NULL) {
				cout << "Nodo extraido con valor: " << extraido->dato << endl;
				delete extraido;
			} else {
				cout << "Lista vacía."<<endl;
			}
			break;
		case 6:
			cout << "Ingrese el valor a quitar: ";
			cin >> valor;
			extraido = QuitarNodo(lista, valor);
			if (extraido != NULL) {
				cout << "Nodo con valor " << extraido->dato << " eliminado."<<endl;
				delete extraido;
			} else {
				cout << "Valor no encontrado."<<endl;
			}
			break;
		case 7:
			cout << "Ingrese el valor a buscar: ";
			cin >> valor;
			encontrado = BuscarNodo(lista, valor);
			if (encontrado != NULL) {
				cout << "Valor " << encontrado->dato << " encontrado en la lista."<<endl;
			} else {
				cout << "Valor no encontrado."<<endl;
			}
			break;
		case 8:
			MostrarLista(lista);
			break;
		case 0:
			cout << "Saliendo del programa."<<endl;
			break;
		default:
			cout << "Opcion invalida. Intente de nuevo."<<endl;
		}
		system("pause");
		system("cls");
	} while (opcion != 0);
	return 0;
}





void IniciarLista(pnodo& inicio) {
	inicio = NULL;
}

void CrearNodo(pnodo& nuevo, int valor) {
	nuevo = new tnodo;
	if (nuevo != NULL) {
		nuevo->dato = valor;
		nuevo->sig = NULL;
		nuevo->ant = NULL;
	}
}

void AgregarInicio(pnodo& inicio, pnodo nuevo) {
	if (inicio == NULL) {
		inicio = nuevo;
	}
	else {
		nuevo->sig = inicio;
		inicio->ant = nuevo;
		inicio = nuevo;
	}
}

void AgregarFinal(pnodo& inicio, pnodo nuevo) {
	pnodo i;
	if (inicio == NULL) {
		inicio = nuevo;
	}
	else {
		for (i = inicio; i->sig != NULL; i = i->sig);
		i->sig = nuevo;
		nuevo->ant = i;
	}
}

void AgregarOrden(pnodo& inicio, pnodo nuevo) {
	pnodo i;
	if (inicio == NULL) {
		inicio = nuevo;
	}
	else {
		if (nuevo->dato < inicio->dato) {
			nuevo->sig = inicio;
			inicio->ant = nuevo;
			inicio = nuevo;
		}
		else {
			for (i = inicio; i->sig != NULL && (i->sig)->dato < nuevo->dato; i = i->sig);
			if (i->sig != NULL) {
				nuevo->sig = i->sig;
				nuevo->ant = i;
				(i->sig)->ant = nuevo;
				i->sig = nuevo;
			}
			else {
				i->sig = nuevo;
				nuevo->ant = i;
			}
		}
	}
}

pnodo QuitarInicio(pnodo& inicio) {
	pnodo extraido;
	if (inicio == NULL) {
		extraido = NULL;
	}
	else {
		if (inicio->sig == NULL) {
			extraido = inicio;
			inicio = NULL;
		}
		else {
			extraido = inicio;
			inicio = inicio->sig;
			inicio->ant = NULL;
			extraido->sig = NULL;
		}
	}
	return extraido;
}

pnodo QuitarFinal(pnodo& inicio) {
	pnodo extraido, i;
	if (inicio == NULL) {
		extraido = NULL;
	}
	else {
		for (i = inicio; i->sig != NULL; i = i->sig);
		extraido = i;
		if (i->ant != NULL)
			(i->ant)->sig = NULL;
		else
			inicio = NULL;
		i->ant = NULL;
	}
	return extraido;
}

pnodo QuitarNodo(pnodo& inicio, int valor) {
	pnodo extraido, i;
	if (inicio == NULL) {
		return NULL;
	}
	if (inicio->dato == valor) {
		extraido = inicio;
		inicio = inicio->sig;
		if (inicio != NULL) inicio->ant = NULL;
		extraido->sig = NULL;
		return extraido;
	}
	for (i = inicio; i != NULL && i->dato != valor; i = i->sig);
	if (i != NULL) {
		extraido = i;
		if (i->ant != NULL) i->ant->sig = i->sig;
		if (i->sig != NULL) i->sig->ant = i->ant;
		extraido->sig = NULL;
		extraido->ant = NULL;
		return extraido;
	}
	return NULL;
}
pnodo BuscarNodo(pnodo inicio, int valor) {
	pnodo i = inicio;
	while (i != NULL) {
		if (i->dato == valor) return i;
		i = i->sig;
	}
	return NULL;
}

void MostrarLista(pnodo inicio) {
	pnodo i;
	for (i = inicio; i != NULL; i = i->sig) {
		cout << i->dato << " ";
	}
	cout << endl;
}


