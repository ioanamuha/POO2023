#include <iostream>
#include "TreeNode.h"

using namespace std;

bool equal(int a, int b)
{
    return a == b;
}

int main()
{

    TreeNode<int> tree(20);
    tree.add_node(8);
    tree.add_node(20, tree.get_node());
    
    tree.insert(tree.get_node(), 1, 15);
    tree.insert(tree.get_node(), 2, 50);


    tree.add_node(24, tree.get_node(0, tree.get_node()));
    tree.insert(tree.get_node(0, tree.get_node()),2,17);
    tree.insert(tree.get_node(0, tree.get_node()),2,25);
   
    tree.delete_node(tree.get_node(11,(tree.get_node(0, tree.get_node()))));
    
    tree.delete_node(tree.find(15));
   
    tree.sort(tree.get_node());
    tree.print();
    cout << "Numarul de copii al radacinii este:" << tree.count(tree.get_node()) << endl;

    return 0;
}