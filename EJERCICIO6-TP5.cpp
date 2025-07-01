#include <iostream>
using namespace std;

template <typename T>
struct Nodo {
	T dato;
	Nodo<T>* siguiente;
};

template <typename T>
class Lista {
private:
	Nodo<T>* cabeza;
	
public:
	Lista() { cabeza = nullptr; }
	
	void agregarFinal(T valor) {
		Nodo<T>* nuevo = new Nodo<T>;
		nuevo->dato = valor;
		nuevo->siguiente = nullptr;
		
		if (cabeza == nullptr) {
			cabeza = nuevo;
		} else {
			Nodo<T>* aux = cabeza;
			while (aux->siguiente != nullptr) {
				aux = aux->siguiente;
			}
			aux->siguiente = nuevo;
		}
	}
	
	void mostrar() {
		Nodo<T>* aux = cabeza;
		while (aux != nullptr) {
			cout <<" ["<< aux->dato << "] ";
			aux = aux->siguiente;
		}
		cout << endl;
	}
	
	Nodo<T>* getCabeza() { return cabeza; }
};

bool esPrimo(int n) {
	if (n <= 1) return false;
	for (int i = 2; i*i <= n; i++)
		if (n % i == 0) return false;
	return true;
}
int contarPrimos(Lista<int>& lista) {
	int contador = 0;
	Nodo<int>* aux = lista.getCabeza();
	while (aux != nullptr) {
		if (esPrimo(aux->dato)) {
			contador++;
		}
		aux = aux->siguiente;
	}
	return contador;
}



int main() {
	int opcion;
	do {
		cout << "=== MENU ==="<<endl;
		cout << "1. Cargar lista de enteros y contar primos"<< endl;
		cout << "0. Salir"<<endl;
		cout << "Opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case 1: {
			Lista<int> listaEnteros;
			int n, val;
			cout << "¿Cuántos enteros desea ingresar? ";
			cin >> n;
			for (int i = 0; i < n; i++) {
				cout << "Ingrese entero " << i + 1 << ": ";
				cin >> val;
				listaEnteros.agregarFinal(val);
			}
			cout << "Lista ingresada: ";
			listaEnteros.mostrar();
			
			int totalPrimos = contarPrimos(listaEnteros);
			cout << "Cantidad de números primos: " << totalPrimos << endl;
			break;
		}
		
		case 0:
			cout << "Saliendo..."<<endl;
			break;
		default:
			cout << "Opción inválida."<<endl;
		}
		system("pause");
		system ("cls");
	} while (opcion != 0);
	
	return 0;
}
