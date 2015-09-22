#include <iostream>

//using namespace std;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::istream;
using std::ostream;


#include "Huffman.h"

int main(){
    BinaryTree<int> tree;
    int init[10]={3,6,0,2,8,4,9,1,5,7};
    Huffman(init,10,tree);
    cout << tree;
    tree.Destroy();
    return 0;
}
