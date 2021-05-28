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
    tree1.printDESC();

    return 0;
}