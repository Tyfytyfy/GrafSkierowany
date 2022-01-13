#include <iostream>

using namespace std;

const int MAX_N = 100; // maksymalna ilość wierzchołków w grafie

void sasiedzi(int iloscWierzcholkow, char A[MAX_N][MAX_N]) {
    //jeżeli wierzchołek ma sąsiada to znaczy że jest połączony w sposób np. 1 3 to znaczy że wierzchołek 1 ma sąsiada wierzchołek 3
    int i, j;
    for (i = 0; i < iloscWierzcholkow; i++) {
        cout << endl;
        cout << "Sasiadzi dla :" << i + 1 << " to ";
        for (j = 0; j < iloscWierzcholkow; j++) {
            if ((int) A[i][j] == 1) {//jeżeli A[i][j] równa sie jeden to znaczy że ten wierzchołek jest sąsiadem
                cout << j + 1 << "\t"; //wypisujemy je
            }

        }
    }
}
void sasiadKazdego(int iloscWierzcholkow, char A[MAX_N][MAX_N]) {
    int i, j, l = 0;
    for (i = 0; i < iloscWierzcholkow; i++) {
        for (j = 0; j < iloscWierzcholkow; j++) {
            if ((int) A[i][j] == 1) {
                l++; //jeżeli wierzchołek ma sąsiada to zwiększamy zmienną l o jeden

                if (l == iloscWierzcholkow - 1) { // żeby stwierdzić że wierzchołek jest sąsiadem każdego wierzchołka to należy porównać zmienną l do liczby wierzchołków - 1
                    cout << "Wierzochlek ktory jest sasaidem kazdego wierzcholka to: " << i + 1 << endl; // wypisujemy ten wierzchołek
                }
            }
        }
        l = 0; // zerujemy zmienną l jeżeli byłby inny taki wierzochłek
    }
}
void stopnieWychodzace(int iloscWierzcholkow, char A[MAX_N][MAX_N]) {
    int i, j, suma = 0;
    for (i = 0; i < iloscWierzcholkow; i++) {

        for (j = 0; j < iloscWierzcholkow; j++) {
            if ((int) A[i][j] == 1) {
                suma = suma + 1; //zliczamy stopień zwiększając go o jeden
            }
        }
        cout << "Stopien wychodzacy wierzcholka o indexie: " << i + 1 << " to: " << suma << endl; // wypisujemy wierzchołek oraz stopień
        suma = 0;
    }
}
void stopnieWchodzace(int iloscWierzcholkow, char A[MAX_N][MAX_N]) {
    int i, j, suma = 0;
    for (j = 0; j < iloscWierzcholkow; j++) {

        for (i = 0; i < iloscWierzcholkow; i++) {
            if ((int) A[i][j] == 1) {
                suma = suma + 1;//zliczamy stopień zwiększając go o jeden
            }
        }
        cout << "Stopien wchodzacy wierzcholka o indexie: " << j + 1 << " to: " << suma << endl;// wypisujemy wierzchołek oraz stopień
        suma = 0;//zerujemy sumę żeby znaleść stopień dla kolejnego wierzchołka
    }
}
void krawedzieDwukierunkowe(int iloscWierzcholkow, char A[MAX_N][MAX_N]) {
    int i, j;
    for (j = 0; j < iloscWierzcholkow; j++) {

        for (i = 0; i < iloscWierzcholkow; i++) {
            if ((int) A[i][j] == 1 && (int) A[j][i] == 1) { //sprawdzamy czy komórki A[i,j] i A[j,i] mają warotść 1
                if (i != j)
                    cout << "Krawedz dwukierunkowa to: " << i + 1 << " " << j + 1 << endl; // wypisujemy je
            }
        }

    }
}
void znajdzPetle(int iloscWierzcholkow, char A[MAX_N][MAX_N]) {
    int i, j;
    for (i = 0; i < iloscWierzcholkow; i++) {
        if ((int) A[i][i] == 1) {// jeżeli komórka
            cout << "Petla znajduje sie w wierzcholku: " << i + 1 << endl;
        }
    }
}
void wierzcholkiIzolowane(int iloscWierzcholkow, char A[MAX_N][MAX_N]) {
    int i, j, k = 0, l = 0, c = 0;
    for (i = iloscWierzcholkow - 1; i >= 0; i--) {
        for (j = iloscWierzcholkow - 1; j >= 0; j--) {

            if ((int) A[i][j] == 0) {
                k++; // jeżeli w wierszu i-tym występuje 0 to zwiększamy k o jeden

            }
            if ((int) A[j][i] == 0)
                l++; // jeżeli w kolumnie i-tej występuje 0 to zwiększamy l o jeden

        }

        if(l == iloscWierzcholkow && k == iloscWierzcholkow){ // jeżeli k i l są równe ilości wierzchołku to ten i jest wierzchołkiem izolowanym
            cout<<"Wierzcholek izolowany to: "<<i+1<<endl;
        }
        l = 0;
        k = 0;
    }

}
main() {
    int i, j, wmax, n, x, y;
    char A[MAX_N][MAX_N]; // macierz s¹siedztwa
    char wierzcholki[MAX_N];

    for (i = 0; i < MAX_N; i++)
        for (j = 0; j < MAX_N; j++) A[i][j] = 0; // wypełniamy macierz zerami
    wmax = 0;
    cout << "Podaj ilosc krawedzi: ";
    cin >> n; // odczytujemy ilość krawędzi
    for (i = 0; i < n; i++) {
        cin >> x >> y; // odczytujemy krawędź

        wmax = (x > wmax) ? x : wmax; // zliczamy ile jest unikalnych wierzchołków
        wmax = (y > wmax) ? y : wmax;
        A[x - 1][y - 1] = 1; //zamieniamy 0 na 1 w macierzy dla danej krawędzi
    }

    cout << endl;
    for (i = 0; i < wmax; i++) {
        for (j = 0; j < wmax; j++) cout << (int) A[i][j] << " "; //odczytujemy macierz(tablice)
        cout << endl;

    }

    sasiedzi(wmax, A);
    cout << endl << endl;
    sasiadKazdego(wmax, A);
    cout << endl << endl;
    stopnieWychodzace(wmax, A);
    cout << endl << endl;
    stopnieWchodzace(wmax, A);
    cout << endl << endl;
    krawedzieDwukierunkowe(wmax, A);
    cout << endl << endl;
    znajdzPetle(wmax, A);
    cout << endl << endl;
    wierzcholkiIzolowane(wmax, A);
    char s[1];
    cin.getline(s, 1);
    cin.getline(s, 1);
}
