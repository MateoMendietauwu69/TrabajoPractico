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
pnodo extraerminimo(pnodo &lista);

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
		cout << "9. Extraer el mínimo" << endl;
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
			borrado = extraerminimo(lista);
			if (borrado != NULL) {
				cout << "Mínimo extraído: " << borrado->dato << endl;
				delete borrado;
			} else {
				cout << "Lista vacía.\n";
			}
			break;
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
					
bool buscarnodo(pnodo lista,int valor)
					{
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
					
pnodo extraerminimo(pnodo &lista){
						if (lista == NULL) {
							return NULL;
						}
						
						pnodo menor = lista;            
						pnodo anteriorMenor = NULL;   
						pnodo actual = lista;
						pnodo anterior = NULL;
						
						while (actual != NULL) {
							if (actual->dato < menor->dato) {
								menor = actual;
								anteriorMenor = anterior;
							}
							anterior = actual;
							actual = actual->siguiente;
						}
						
						if (menor == lista) {
							lista = lista->siguiente;
						} else {
							anteriorMenor->siguiente = menor->siguiente;
						}
						
						menor->siguiente = NULL;
						return menor;
					}
