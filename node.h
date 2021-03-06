#include <utility>
using namespace std;

template <typename T>
class RangeTree;

template <typename T>
struct Node{
    int height;
    Node* left; 
    Node* right;
    pair<T, T> data; 
    RangeTree<T>* treeAssociated;
    
    Node() : left(nullptr), right(nullptr), height(0), treeAssociated(nullptr) {}   
    Node(pair<T,T> value) : data(value), left(nullptr), right(nullptr), height(0), treeAssociated(nullptr) {}   
    Node(pair<T,T> value, int height): data(value), left(nullptr), right(nullptr), height(height), treeAssociated(nullptr) {}

    void killSelf(){
        if(left != nullptr) left->killSelf();
        if(right != nullptr) right->killSelf();
        delete this;
    }
    
    T getDimensionValue(int dimensionNumber){
        if(dimensionNumber == 1) return data.first;
        return data.second;
    }
};
