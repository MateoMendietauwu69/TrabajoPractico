#include<iostream>
using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
	int dato;
	pnodo sig;
	pnodo ant;
};
typedef struct tlista{
	pnodo inicio;
	pnodo fin;
};

void IniciarLista(tlista &lista)
{
	lista.inicio = NULL;
	lista.fin = NULL;
}

void CrearNodo(pnodo &nuevo, int valor)
{
	nuevo = new tnodo;
	if(nuevo != NULL)
	{
		nuevo -> dato = valor;
		nuevo -> sig = NULL;
		nuevo -> ant = NULL;
	}
}

void AgregarInicio(tlista &lista, pnodo nuevo)
{
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.fin = nuevo;
	}
	else{
		nuevo->sig = lista.inicio;
		lista.inicio->ant = nuevo;
		lista.inicio = nuevo;
	}
}

void AgregarFinal(tlista &lista, pnodo nuevo){
	if(lista.inicio == NULL){
		lista.inicio = nuevo;
		lista.fin = nuevo;
	}
	else{
		lista.fin->sig = nuevo;
		nuevo->ant = lista.fin;
		lista.fin = nuevo;
	}
}
	
	pnodo QuitarInicio(tlista &lista) {
		pnodo extraido;
		if (lista.inicio == NULL) {
			extraido = NULL;
		} else if (lista.inicio == lista.fin) {
			extraido = lista.inicio;
			lista.inicio = NULL;
			lista.fin = NULL;
		} else {
			extraido = lista.inicio;
			lista.inicio = lista.inicio->sig;
			lista.inicio->ant = NULL;
			extraido->sig = NULL;
		}
		return extraido;
	}
	
	
	
	pnodo QuitarFinal(tlista &lista) {
		pnodo extraido;
		if (lista.fin == NULL) {
			extraido = NULL;
		} else if (lista.inicio == lista.fin) {
			extraido = lista.fin;
			lista.inicio = NULL;
			lista.fin = NULL;
		} else {
			extraido = lista.fin;
			lista.fin = lista.fin->ant;
			lista.fin->sig = NULL;
			extraido->ant = NULL;
		}
		return extraido;
	}
	
	void DecimalABinario(int numero, tlista &lista) {
		IniciarLista(lista); 
		pnodo nuevo;
		
		if (numero == 0) {
			CrearNodo(nuevo, 0);
			AgregarInicio(lista, nuevo);
			return;
		}
		
		while (numero > 0) {
			int bit = numero % 2;
			CrearNodo(nuevo, bit);
			AgregarInicio(lista, nuevo);
			numero = numero / 2;
		}
	}
	
	void MostrarLista(tlista lista) {
		pnodo i = lista.inicio;
		if (i == NULL) {
			cout << "La lista está vacía."<<endl;
		} else {
			cout << "Contenido de la lista:"<<endl;
			while (i != NULL) {
				cout <<" ["<< i->dato << "] ";
				i = i->sig;
			}
			cout << endl;
		}
	}
	void DecimalBinario(int numero, tlista &lista) {
		IniciarLista(lista); 
		pnodo nuevo;
		
		if (numero == 0) {
			CrearNodo(nuevo, 0);
			AgregarInicio(lista, nuevo);
			return;
		}
		
		while (numero > 0) {
			int bit = numero % 2;
			CrearNodo(nuevo, bit);
			AgregarInicio(lista, nuevo); 
			numero = numero / 2;
		}
	}
	
	void MostrarBinario(tlista lista) {
		pnodo actual = lista.inicio;
		cout << "Número en binario: ";
		while (actual != NULL) {
			cout << actual->dato;
			actual = actual->sig;
		}
		cout << endl;
	}
	
	void MostrarMayorMenor(tlista lista) {
		if (lista.inicio == NULL) {
			cout << "La lista está vacía." << endl;
			return;
		}
		
		int mayor = lista.inicio->dato;
		int menor = lista.inicio->dato;
		
		pnodo actual = lista.inicio->sig;
		
		while (actual != NULL) {
			if (actual->dato > mayor)
				mayor = actual->dato;
			if (actual->dato < menor)
				menor = actual->dato;
			actual = actual->sig;
		}
		
		cout << "Valor mayor en la lista: " << mayor << endl;
		cout << "Valor menor en la lista: " << menor << endl;
	}
	void EliminarMultiplosDeTres(tlista &lista) {
		pnodo actual = lista.inicio;
		pnodo temp;
		
		while (actual != NULL) {
			if (actual->dato % 3 == 0) {
				temp = actual;
				actual = actual->sig;
				
				if (temp->ant != NULL) 
					temp->ant->sig = temp->sig;
				else 
					lista.inicio = temp->sig;
				
				if (temp->sig != NULL) 
					temp->sig->ant = temp->ant;
				else 
					lista.fin = temp->ant;
				
				delete temp;
			} else {
				actual = actual->sig;
			}
		}
		
		cout << "Lista actualizada (sin múltiplos de 3):"<<endl;
		MostrarLista(lista);
	}
	int main() {
		tlista lista;
		IniciarLista(lista);
		int opcion, valor;
		pnodo nodoExtraido, nuevo;
		
		do {
			cout << "--- MENU LISTA DOBLEMENTE ENLAZADA ---"<<endl;
			cout << "1. Agregar al inicio"<<endl;
			cout << "2. Agregar al final"<<endl;
			cout << "3. Quitar del inicio"<<endl;
			cout << "4. Quitar del final"<<endl;
			cout << "5. Mostrar lista"<<endl;
			cout << "6. Numero decimal a Numero Binario (punto3)"<< endl; 
			cout << "7. Mostrar mayor y menor valor (punto4)"<<endl;
			cout << "8. Eliminar Multiplos de 3 (punto5)" << endl;
			cout << "0. Salir"<<endl;
			cout << "Seleccione una opción: ";
			cin >> opcion;
			
			switch (opcion) {
			case 1:
				cout << "Ingrese valor: ";
				cin >> valor;
				CrearNodo(nuevo, valor);
				AgregarInicio(lista, nuevo);
				break;
			case 2:
				cout << "Ingrese valor: ";
				cin >> valor;
				CrearNodo(nuevo, valor);
				AgregarFinal(lista, nuevo);
				break;
			case 3:
				nodoExtraido = QuitarInicio(lista);
				if (nodoExtraido != NULL) {
					cout << "Nodo extraído del inicio: " << nodoExtraido->dato << endl;
					delete nodoExtraido;
				} else {
					cout << "Lista vacía, nada que quitar."<<endl;
				}
				break;
			case 4:
				nodoExtraido = QuitarFinal(lista);
				if (nodoExtraido != NULL) {
					cout << "Nodo extraído del final: " << nodoExtraido->dato << endl;
					delete nodoExtraido;
				} else {
					cout << "Lista vacía, nada que quitar."<<endl;
				}
				break;
			case 5:
				MostrarLista(lista);
				break;
			case 6:
				cout << "Ingrese número decimal: ";
				cin >> valor;
				DecimalBinario(valor, lista);
				MostrarBinario(lista);
				break;
			case 7:
				MostrarMayorMenor(lista);
				break;
			case 8:
				EliminarMultiplosDeTres(lista);
				break;
			case 0:
				cout << "Saliendo del programa..."<<endl;
				break;
			default:
				cout << "Opción inválida."<<endl;
			}
			system ("pause");
			system("cls");
		} while (opcion != 0);
		
		return 0;
	}
