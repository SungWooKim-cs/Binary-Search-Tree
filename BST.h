//-----------------------------------------------------------
//  Purpose:    Header file for the BST(BinarySearchTree) class.
//  Author:     SungWoo Kim 
//-----------------------------------------------------------

#include <iostream>
#include <fstream>
using namespace std;

//-----------------------------------------------------------
// BinaryTree data node definition
//-----------------------------------------------------------
class Node
{
 public:
   string Name;
   int Count;
   float Percentage;
   int Rank;
   Node *Left;
   Node *Right;
};

//-----------------------------------------------------------
// Define the BST(BinarySearchTree) class interface 
//-----------------------------------------------------------
class BST
{
 public:
   // Constructor functions
   BST();
   ~BST();

   // General binary tree operations
   bool Search(string name);
   bool Insert(string name);
   bool Delete(string name);
   void Print();

 private:
   // Helper functions
   void DestroyHelper(Node * Tree);
   bool SearchHelper(string Name, Node * Tree);
   bool InsertHelper(string Name, Node * &Tree);
   bool DeleteNode(Node * &Tree);
   bool DeleteHelper(string Name, Node * &Tree);
   void PrintHelper(Node * Tree);

   // Tree pointer
   Node *Root;
};
