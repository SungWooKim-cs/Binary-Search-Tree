//-----------------------------------------------------------
//  Purpose:    Implementation of BST(BinarySearchTree) class.
//  Author:     SungWoo Kim
//-----------------------------------------------------------
#include "BST.h"
#include <stdlib.h>

//-----------------------------------------------------------
// Constructor function.
//-----------------------------------------------------------
BST::BST()
{
   Root = NULL;
}

//-----------------------------------------------------------
// Destructor function helper function.
//-----------------------------------------------------------
void BST::DestroyHelper(Node * Tree)
{
   // Delete node and it's children
   if (Tree != NULL)
   {
      DestroyHelper(Tree->Left);
      DestroyHelper(Tree->Right);
      delete Tree;
   }
}

//-----------------------------------------------------------
// Destructor function.
//-----------------------------------------------------------
BST::~BST()
{
   // Call tree destroy function
   DestroyHelper(Root);
}

//-----------------------------------------------------------
// Search helper function.
//-----------------------------------------------------------
bool BST::SearchHelper(string Name, Node * Tree)
{
   // Data value not found 
   if (Tree == NULL)
      return false;

   // Data value found 
   else if (Tree->Name == Name)
      return true;

   // Recursively search for data value
   else if (Tree->Name > Name)
      return (SearchHelper(Name, Tree->Left));
   else 
      return (SearchHelper(Name, Tree->Right));
}

//-----------------------------------------------------------
// Search for data in the binary tree.
//-----------------------------------------------------------
bool BST::Search(string Name)
{
   
   // Call tree searching function
   return (SearchHelper(Name, Root));
}

//-----------------------------------------------------------
// Insert helper function.
//-----------------------------------------------------------
bool BST::InsertHelper(string Name, Node * &Tree)
{
   int Count;
   float Percentage;
   int Rank;
   // Insert data into the tree
   if (Tree == NULL)
   {
      Tree = new Node;
      Tree->Name = Name;
      Tree->Count = Count;
      Tree->Percentage = Percentage;
      Tree->Rank = Rank;
      Tree->Left = NULL;
      Tree->Right = NULL;
      
      return true;
   }

   // Recursively search for insertion position
   else if (Tree->Name > Name)
      return (InsertHelper(Name, Tree->Left));
   else 
      return (InsertHelper(Name, Tree->Right));
}

//-----------------------------------------------------------
// Insert data into the binary tree.
//-----------------------------------------------------------
bool BST::Insert(string Name)
{
   // Call tree insertion function
   return (InsertHelper(Name, Root));
}

//-----------------------------------------------------------
// Delete a single node from the binary tree.
//-----------------------------------------------------------
bool BST::DeleteNode(Node * &Tree)
{
   Node *Temp = Tree;

   // Node has 0 children
   if ((Tree->Left == NULL) && (Tree->Right == NULL))
      Tree = NULL;

   // Node has 1 child
   else if (Tree->Left == NULL)
      Tree = Tree->Right;
   else if (Tree->Right == NULL)
      Tree = Tree->Left;


   // Node has 2 children
   else
   {
      // Find leftmost node in right subtree
      Node *Parent = Tree;
      Temp = Tree->Right;
      while (Temp->Left != NULL)
      {
    	 Parent = Temp;
    	 Temp = Parent->Left;
      }

      // Replace deleted data with leftmost value
      if (Parent == Tree)
	 Parent->Right = Temp->Right;
      else
	 Parent->Left = Temp->Right;
      Tree->Name = Temp->Name;
   }

   // Delete node
   delete Temp;
   return true;
}

//-----------------------------------------------------------
// Delete helper function.
//-----------------------------------------------------------
bool BST::DeleteHelper(string Name, Node * &Tree)
{
   // Name Data not found
   if (Tree == NULL)
      return false;

   // Name Data found and deleted
   else if (Tree->Name == Name)
      return (DeleteNode(Tree));

   // Recursively search for node to delete
   else if (Tree->Name > Name)
      return (DeleteHelper(Name, Tree->Left));
   else 
      return (DeleteHelper(Name, Tree->Right));
}

//-----------------------------------------------------------
// Delete data from the binary tree.
//-----------------------------------------------------------
bool BST::Delete(string Name)
{
   // Call tree deletion function
   return (DeleteHelper(Name, Root));
}

//-----------------------------------------------------------
// Print helper function.
//-----------------------------------------------------------
void BST::PrintHelper(Node * Tree)
{
   // Check terminating condition
   if (Tree != NULL)
   {
      // Print left subtree
      PrintHelper(Tree->Left);

      // Print node value
      cout << Tree->Name << " " << Tree->Count << " "<<  Tree->Percentage << " " << Tree->Rank << endl;

      // Print right subtree
      PrintHelper(Tree->Right);
   }
}

//-----------------------------------------------------------
// Print all records in the binary tree.
//-----------------------------------------------------------
void BST::Print()
{
   // Call tree printing function
   PrintHelper(Root);
   cout << endl;
}
