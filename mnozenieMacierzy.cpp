#include<iostream>
#include<cstdlib>

using namespace std;

char KOMENDA_MAZANIA_KONSOLI[] = "cls";
int n,x, y, **mac1, **mac2, **macierzWynikowa;
void rysujTablice(int, int, int**);
void inicjalizacjaMacierzy();
void zmazKonsole();
void wczytanieMacierzy();
void mnozenieMacierzy();
void pokazanieWyniku();
int main() {
	inicjalizacjaMacierzy();
	wczytanieMacierzy();
	mnozenieMacierzy();
	pokazanieWyniku();
	return 0;
}
void mnozenieMacierzy() {
	macierzWynikowa = new int*[n];
	int z;
	for (x = 0 ; x < n ; ++x)
		macierzWynikowa[x] = new int[n];
	cout<<"Macierz wynikowa: "<<endl;
	for (y = 0 ; y < n ; ++y)
		for (x = 0; x < n ; ++x) {
			macierzWynikowa[x][y] = 0;
			for (z = 0 ; z < n ; ++z) {
				macierzWynikowa[x][y] += mac1[z][y] * mac2[x][z];
			}
	}
}
void pokazanieWyniku() {
	for (y = 0 ; y < n ; ++y) {
		for (x = 0 ; x < n ; ++x)
			cout<<macierzWynikowa[x][y]<<' ';
		cout<<'\n';
	}
}
void wczytanieMacierzy() {
	cout<<"Macierz pierwsza:"<<endl;
	for (y = 0 ; y < n ; ++y) {
			for (x = 0 ; x < n ; ++x) {
				cin>>mac1[x][y];
				rysujTablice(x, y, mac1);
			}
			cout<<'\n';
	}
	cout<<"Macierz druga:"<<endl;
	for (y = 0 ; y < n ; ++y) {
				for (x = 0 ; x < n ; ++x) {
					cin>>mac2[x][y];
					rysujTablice(x, y, mac2);
				}
				cout<<'\n';
	}
}
void inicjalizacjaMacierzy() {
	n = 0;
	while (n < 1) {
		cout<<"Podaj rozmiar macierzy"<<endl;
		cin>>n;
		if (n < 1)
			cout<<"Podany nieprawidlowy rozmiar macierzy."<<endl;
	}
	zmazKonsole();
	mac1 = new int*[n];
	mac2 = new int*[n];
	for (y = 0 ; y < n ; ++y) {
			mac1[y] = new int[n];
			mac2[y] = new int[n];
	}
}
void zmazKonsole() {
	system(KOMENDA_MAZANIA_KONSOLI);
}
void rysujTablice(int x, int y, int**tab) {
	zmazKonsole();
	int a, b;
	for (a = 0 ; a < y + 1; ++a) {
		if (a < y)
			for (b = 0 ; b < n; ++b)
				cout<<tab[b][a]<<"  ";
		else
			for (b = 0 ; b < x + 1 ; ++b)
				cout<<tab[b][a]<<"  ";
		cout<<'\n';
	}

}
