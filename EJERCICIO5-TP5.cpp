#include <iostream>
using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
	int dato;
	pnodo siguiente;
};

void crearnodo(pnodo &nuevo);
void iniciarlista(pnodo &lista);
void agregarinicio(pnodo &lista, pnodo nuevo);
void agregarfinal(pnodo &lista, pnodo nuevo);
void agregarordenado(pnodo &lista, pnodo nuevo);
pnodo eliminarfinal(pnodo &lista);
pnodo eliminarinicio(pnodo &lista);
pnodo eliminar_nodo(pnodo &lista, int valor);
void mostrar(pnodo lista);
bool buscarnodo(pnodo lista, int valor);
void ordenarseleccion(pnodo &lista);
void combinarSinOrden(pnodo &lista1, pnodo lista2);
pnodo combinarConOrden(pnodo lista1, pnodo lista2) ;

int main() {
	pnodo lista;
	iniciarlista(lista);
	int opcion;
	do {
		cout << "=== MENU DE LISTA SIMPLE ==="<<endl;
		cout << "1. Agregar al inicio"<<endl;
		cout << "2. Agregar al final"<<endl;
		cout << "3. Agregar ordenado"<< endl;
		cout << "4. Eliminar del inicio" << endl;
		cout << "5. Eliminar del final"<< endl;
		cout << "6. Eliminar por valor" << endl;
		cout << "7. Mostrar lista" << endl ;
		cout << "8. Buscar valor"<< endl;
		cout << "9. Ordenar lista por selección" << endl;
		cout << "10. Combinar con otra lista (sin orden)" << endl;
		cout << "11. Combinar dos listas ordenadas" << endl;
		cout << "0. Salir" << endl ;
		cout << "Ingrese opción: " << endl;
		cin >> opcion;
		
		pnodo nuevo, borrado;
		int valor;
		
		switch(opcion) {
		case 1:
			crearnodo(nuevo);
			agregarinicio(lista, nuevo);
			break;
		case 2:
			crearnodo(nuevo);
			agregarfinal(lista, nuevo);
			break;
		case 3:
			crearnodo(nuevo);
			agregarordenado(lista, nuevo);
			break;
		case 4:
			borrado = eliminarinicio(lista);
			if (borrado != NULL) {
				cout << "Eliminado: " << borrado->dato << endl;
				delete borrado;
			} else {
				cout << "Lista vacía.\n";
			}
			break;
		case 5:
			borrado = eliminarfinal(lista);
			if (borrado != NULL) {
				cout << "Eliminado: " << borrado->dato << endl;
				delete borrado;
			} else {
				cout << "Lista vacía.\n";
			}
			break;
		case 6:
			cout << "Ingrese valor a eliminar: ";
			cin >> valor;
			borrado = eliminar_nodo(lista, valor);
			if (borrado != NULL) {
				cout << "Eliminado: " << borrado->dato << endl;
				delete borrado;
			} else {
				cout << "No encontrado o lista vacía.\n";
			}
			break;
		case 7:
			mostrar(lista);
			break;
		case 8:
			cout << "Ingrese valor a buscar: ";
			cin >> valor;
			if (buscarnodo(lista, valor))
				cout << "Valor encontrado.\n";
			else
				cout << "No encontrado.\n";
			break;
		case 9:
			cout << "Ordenando lista por selección..." << endl;
			ordenarseleccion(lista);
			break;
		case 10: {
			cout << "Creando otra lista para combinar sin orden... ( se combina con la lista ya creada)" << endl;
			pnodo otraLista;
			iniciarlista(otraLista);
			cout << "Ingrese 3 valores para la otra lista:\n";
			for (int i = 0; i < 3; i++) {
				crearnodo(nuevo);
				agregarfinal(otraLista, nuevo);
			}
			combinarSinOrden(lista, otraLista);
			cout << "Listas combinadas sin orden." << endl;
			break;
		}
		case 11: {
			cout << "Creando dos listas ordenadas para combinación ordenada... (son listas nuevas)" << endl;
			pnodo lista1, lista2, listaFinal;
			iniciarlista(lista1);
			iniciarlista(lista2);
			cout << "Ingrese 3 valores para la lista 1:"<<endl;
			for (int i = 0; i < 3; i++) {
				crearnodo(nuevo);
				agregarordenado(lista1, nuevo);
			}
			cout << "Ingrese 3 valores para la lista 2:" << endl;
			for (int i = 0; i < 3; i++) {
				crearnodo(nuevo);
				agregarordenado(lista2, nuevo);
			}
			listaFinal = combinarConOrden(lista1, lista2);
			cout << "Lista combinada ordenada:" << endl;
			mostrar(listaFinal);
			break;
		}
		
		case 0:
			cout << "Saliendo del programa...\n";
			break;
		default:
			cout << "Opción inválida.\n";
		}
		system("Pause");
		system ("cls");
	} while (opcion != 0);
	
	return 0;
}
void crearnodo(pnodo &nuevo){
	nuevo= new tnodo;
	if(nuevo != NULL)
	{
		cout<<"Ingrese valor:";
		
		cin >> nuevo -> dato;
		nuevo -> siguiente= NULL;
	}
	else{
		cout<< "Memoria insuficiente"<< endl; 
	}
}
	
	void iniciarlista(pnodo &lista)
	{
		lista = NULL;
	}
	
	void agregarinicio(pnodo &lista, pnodo nuevo)
	{
		nuevo-> siguiente = lista;
		lista = nuevo;
	}
	void agregarfinal(pnodo &lista, pnodo nuevo)
	{
		pnodo aux;
		
		if (lista == NULL)
		{
			lista= nuevo;
		}
		else {
			for (aux = lista; aux ->siguiente !=NULL; aux=aux->siguiente);
			aux->siguiente = nuevo;
		}
	}
	void agregarordenado (pnodo &lista, pnodo nuevo)
	{
		pnodo aux;
		if (lista == NULL)
		{
			lista=nuevo;
		}
		else {
			if (nuevo-> dato < lista->dato)
			{
				nuevo -> siguiente =lista;
				lista = nuevo;
			}
			else{
				for (aux = lista; aux ->siguiente != NULL && nuevo->dato > (aux->siguiente)->dato; aux=aux->siguiente);
				nuevo->siguiente = aux ->siguiente;
				aux->siguiente = nuevo;
			}
		}
	}
	pnodo eliminarfinal(pnodo &lista){
		pnodo borrado, aux;
		if( lista == NULL)
		{
			borrado = NULL;
		}
		else {
			if(lista -> siguiente == NULL)
			{
				borrado = lista;
				lista = NULL;
			}
			else {
				for (aux=lista; (aux->siguiente) -> siguiente != NULL;aux = aux->siguiente);
				borrado = aux ->siguiente;
				aux->siguiente = NULL;
			}
		}
		return borrado;
	}
pnodo eliminarinicio(pnodo &lista){
			pnodo borrado;
			if( lista == NULL)
			{
				borrado = NULL;
			}
			else {
				borrado= lista;
				lista = lista ->siguiente;
				borrado->siguiente = NULL;
			}
			return borrado;}
pnodo eliminar_nodo(pnodo &lista, int valor){
				pnodo borrado, i;
				if(lista == NULL){
					borrado = NULL;
				}
				else{
					if(lista->dato == valor){
						borrado = lista;
						lista = borrado->siguiente;
						borrado->siguiente = NULL;
					}
					else{
						for(i=lista; i->siguiente != NULL && valor!=(i->siguiente)->dato; i=i->siguiente);
						if(i->siguiente != NULL){
							borrado = i->siguiente;
							i->siguiente = borrado->siguiente;
							borrado->siguiente = NULL;
						}
						else{
							borrado=NULL;
						}
					}
				}
				return borrado;
			}
				
				
void mostrar(pnodo lista){
					pnodo aux;
					if(lista != NULL)
					{
						for(aux = lista; aux != NULL; aux=aux->siguiente){
							cout<<"Nodo : "<< aux->dato<<endl;
						}
					}
					else{
						cout<<"Lista vacia";
					}
				}
					
bool buscarnodo(pnodo lista,int valor){
					
						pnodo aux;
						bool encontrado=false;
						if (lista != NULL)
						{
							for(aux=lista;aux != NULL && encontrado == false;aux = aux->siguiente)
							{if (aux->dato == valor)
							{
								encontrado = true;
							}}
						}
						return encontrado;
					}
void ordenarseleccion(pnodo &lista) {
						pnodo i, j, menor;
						int temp;
						
						for (i = lista; i != NULL && i->siguiente != NULL; i = i->siguiente) {
							menor = i;
							for (j = i->siguiente; j != NULL; j = j->siguiente) {
								if (j->dato < menor->dato) {
									menor = j;
								}
							}
							if (menor != i) {
								temp = i->dato;
								i->dato = menor->dato;
								menor->dato = temp;
							}
						}
					}

void combinarSinOrden(pnodo &lista1, pnodo lista2) {
	pnodo aux = lista2;
	while (aux != NULL) {
		pnodo nuevo = new tnodo;
		nuevo->dato = aux->dato;
		nuevo->siguiente = NULL;
		agregarfinal(lista1, nuevo);
		aux = aux->siguiente;
	}
}


pnodo combinarConOrden(pnodo lista1, pnodo lista2) {
	pnodo resultado = NULL;
	
	while (lista1 != NULL && lista2 != NULL) {
		pnodo nuevo = new tnodo;
		if (lista1->dato <= lista2->dato) {
			nuevo->dato = lista1->dato;
			lista1 = lista1->siguiente;
		} else {
			nuevo->dato = lista2->dato;
			lista2 = lista2->siguiente;
		}
		nuevo->siguiente = NULL;
		agregarfinal(resultado, nuevo);
	}
	while (lista1 != NULL) {
		pnodo nuevo = new tnodo;
		nuevo->dato = lista1->dato;
		nuevo->siguiente = NULL;
		agregarfinal(resultado, nuevo);
		lista1 = lista1->siguiente;
	}
	while (lista2 != NULL) {
		pnodo nuevo = new tnodo;
		nuevo->dato = lista2->dato;
		nuevo->siguiente = NULL;
		agregarfinal(resultado, nuevo);
		lista2 = lista2->siguiente;
	}
	return resultado;
}


