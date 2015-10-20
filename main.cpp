#include <iostream>
#include <stack>
#include <queue>

using namespace std;

#include "nodeT.h"
#include "BST.h"

int main(){
    BST miArbol;
    miArbol.add(12);
    miArbol.add(13);
    miArbol.add(89);
    miArbol.add(2);
    miArbol.add(3);
    miArbol.add(21);

    cout << miArbol.wherelevelIam(3);
    return 0;
}
