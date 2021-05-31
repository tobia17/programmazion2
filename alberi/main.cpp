#include <iostream>
#include "BST.h"
#include "NodoBST.h"

using namespace std;

int main(){

    BST<int> tree1;

    tree1.insert(7);
    tree1.insert(10);
    tree1.insert(8);
    tree1.insert(11);
    tree1.insert(2);
    tree1.insert(1);
    tree1.insert(3);

    tree1.printASC();
    cout << endl;
    //tree1.printDESC();

    cout << "massimo: " << *tree1.massimo() << endl;
    cout << "minimo: " << *tree1.minimo() << endl;

    cout << endl << "Nodo trovato con valure 2: " << *tree1.search(2) << endl;

    return 0;
}