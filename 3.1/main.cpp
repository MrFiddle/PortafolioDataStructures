#include <iostream>
#include "BinarySearchTree.h"

int main(){
    
    BinarySearchTree<int> myBST;

    myBST.insert(10);
    myBST.insert(20);
    myBST.insert(30);
    myBST.insert(15);
    myBST.insert(5);
    myBST.insert(115);
    myBST.insert(3);

    /*
                    10
            5               20          
        3             15          30
                                      115                           
  */

    std::cout << "--Recorridos--" << std::endl;
    int input;
    std::cout << "1.Preorder\n2.Inorder\n3.Postorder\n4.Level by level" << std::endl;
    std::cin >> input; 
    myBST.visit(input);


    std::cout << "--Calculando altura del BST--" << std::endl;
    std::cout << myBST.height(myBST.root) << std::endl;

    std::cout << "--Buscando el nivel donde se encuentra el valor 30 en el BST--" << std::endl;
    std::cout << myBST.whatLevelAmI(30) << std::endl;;

    std::cout << "--Buscando el nivel donde se encuentra el valor 10 en el BST--" << std::endl;
    std::cout << myBST.whatLevelAmI(10) << std::endl;;

    std::cout << "--Buscando el nivel donde se encuentra el valor 69 en el BST--" << std::endl;
    std::cout << myBST.whatLevelAmI(69) << "(No se encontro el valor en el BST)" << std::endl;

    std::cout << "-- Buscando los ancestros de 15 --" << std::endl;
    myBST.ancestors(myBST.root, 15);

    myBST.callLevelByLevel();

}