// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
//fct care elimina primul elem din v
void eliminaPrimul(int*& v, int& n){
    if (n >= 2 && v != nullptr) {
        //p1.se identifica noua dimensiune
        int n2 = n - 1;

        //p2. se aloca zona memorie pentru noua dimensiune intr un vector suplimentar 
        int* aux = new int[n2];

        //p3. se copiaza in noul vector ce este nevoie
        int k = 0; //pozitia curenta in care copiez in noul vector
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                aux[k++] = v[i];
            }
        }

        //p4 dezalocare zona mem veche
        delete[] v;
        //p5. vechiul vector pointeaza spre noua zm
        // +actualizare dimensiune
        v = aux;
        n = n2;
    }

    else {
        v = nullptr;//pt ca raman fara elem sau nu erau la inceput
    }

}


int main()
{
    int* v = nullptr;
    int n = NULL;

    n = 5;
    v = new int[n];
    for (int i = 0; i < n; i++) {
        cin >> v[i];

    }

    eliminaPrimul(v, n);
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";


    return 0;
    
}
# opp
