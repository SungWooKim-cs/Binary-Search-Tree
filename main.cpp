#include "BST.h"
//-----------------------------------------------------------
// Main program tests the BinaryTree class.
//-----------------------------------------------------------
int main()
{
   // Create tree
   BST Tree;

    // Open ASCII input file
    ifstream din;
    din.open("last.txt");
    if (din.fail())
    {
        cout << "Error: Could not open " << endl;
        return 0;
    }
    
    // Read words 
    string Name = "";
    int Count = 0;
    float Percentage = 0.0;
    int Rank = 0;
    
    //Test binary tree insert
    while (!din.eof())
    {
        din >> Name >> Count >> Percentage >> Rank;
        Tree.Insert(Name);
        //Tree.Print();   
    }
    din.close();
    
    // Test binary tree search
    
    
    while (Name != "QUIT") 
   {
      cout << "Insert last-name to search\n" << "QUIT to exit\n";
      cin >> Name; 
      if (Name == "QUIT")
        {Tree.Print();
        return 0;}
        
      if (Tree.Search(Name))
	    cout << "Search " << Name <<" "<< Count <<" "<< Percentage <<" "<< Rank << " found\n";

      else
	    cout << "Search " << Name << " not found\n";
   }
   
   return 0;
}
