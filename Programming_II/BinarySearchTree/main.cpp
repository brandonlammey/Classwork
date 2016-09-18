/*
 * File Name: main.cpp
 * Author: Brandon Lammey
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu
 * Homework: Lab 10
 * Description: Program will take in a dictionary file and create DictionaryEntry objects which it will place
 * into a Binary Seach tree. The user will then be given a set of options to query the dictionary: search for a word,
 * create a copy of the dictionary, add a word to the copy, delete a word from the copy, save the chosen dictionary in 
 * selected order, and test. The menu will loop until user quits.
 */

#include <algorithm>
#include <string>
#include <cctype>
#include <stdio.h>
#include <ctype.h>

#include <iostream>
#include <fstream>
#include <istream>



#include "BinarySearchTree.h"
#include "DictionaryEntry.h"
#include "BinaryNode.h"

//function turns all letters in a string to lowercase
void makeLowercase(std::string& input);

//function to print a dictionary entry 
void printEntry(DictionaryEntry entry);

//function to save an entry
void save(DictionaryEntry entry);

//function to print query options
void printMenu();

//output file
std::ofstream output;

/*
Pass in the original dictionary
Prompts the user for a word to remove
Prints the remaining tree to the screen in in-order
*/
void testAdds(BinarySearchTree<DictionaryEntry, std::string> dictionary);

/*
Pass in the original dictionary
Prompts the user for a word and definition to add (seperate prompts)
Prints the remaining tree to the screen in in-order
*/
void testRemoves(BinarySearchTree<DictionaryEntry, std::string> dictionary); 

/*
Pass in the original dictionary
Prompt the user for an output file name
Writes the contents of the dictionary to the file in in-order
*/
void testWriteToFile(BinarySearchTree<DictionaryEntry, std::string> dictionary);


int main(int argc, char* argv[])
{	
	
	if(argc == 2) //check for proper arguments 
    {
        std::string dictionaryName;
        dictionaryName = argv[1];
		
		
		std::ifstream input(dictionaryName); //open file
		//if file is open then take in dictionary entry and populate BST
		if (input.is_open())
		{	
			BinarySearchTree<DictionaryEntry, std::string> bst; //create an empty binary search tree
			
			//take in a word and its definition
			//create a dictionary entry
			//put entry into BinarySearchTree
			//loop until file is completely read
			while(!input.eof())
			{
				std::string entry; 
				std::getline(input, entry);
				if(entry.length() > 2)
				{
					std::string word;
					std::string definition;
					
					int i = 0;
					while(!(entry.at(i) == ' ' && entry.at(i+1) == ' '))
					{
						word = word + entry.at(i); 
						i++;
					}
					i=i+2;
					
					for(i; i<entry.length(); i++)
					{
						definition = definition + entry.at(i);
					}
					makeLowercase(word);
					makeLowercase(definition);
					
					if(word != "" && definition != "" && !bst.contains(word)) 
					{
      					bst.add(DictionaryEntry(word, definition));
					}
				}
				
			}
			input.close();//close file

			
			int query = 0; //determines user choice
			bool copy = false; //determines when a copy is made
			BinarySearchTree<DictionaryEntry, std::string> bstCopy(bst); //copied tree
			
			//Allowe user to query until they quit
			while(query!=7)
			{
				printMenu();
				std::cin >> query;
				
				if(query == 1)//search option
				{
					if(copy == true)
					{
						int choice = 0; 
						
						std::cout << "Choose a dictionary to search." <<'\n';
						std::cout << "1. Original" <<'\n';
						std::cout << "2. Copy" <<'\n';
						std::cin >> choice; 
						
						while(choice != 1 && choice != 2)
						{
							std::cout << "Invalid Selection. Please choose option 1 or 2: ";
							std::cin >> choice;
						}
						
							std::string search;
							std::cout << "Search for a word: ";
							std::cin.ignore(1, '\n');
							std::getline (std::cin, search);
							makeLowercase(search);
						
						if(choice == 1)
						{
							if(bst.contains(search))//word is in dictionay
							{
								printEntry(bst.getEntry(search));
							}
							else
							{
								std::cout << "This word is not in the dictionary." << '\n';
							}							
						}
						else//choice 2
						{
							if(bstCopy.contains(search))//word is in dictionay
							{
								printEntry(bstCopy.getEntry(search));
							}
							else
							{
								std::cout << "This word is not in the dictionary." << '\n';
							}							
						}						
					}
					else
					{	
						std::string search;
						std::cout << "Search for a word: ";
						std::cin.ignore(1, '\n');
						std::getline (std::cin, search);

						makeLowercase(search);

						if(bst.contains(search))//word is in dictionay
						{
							printEntry(bst.getEntry(search));
						}
						else
						{
							std::cout << "This word is not in the dictionary." << '\n';
						}
					}
					std::cout << '\n' << '\n' << '\n';
				}
				else if(query == 2)//creates copy
				{
					copy = true;
					std::cout << "**********  A copy of the dictionary has been made.  **********" << '\n';
					std::cout << '\n' << '\n' << '\n';
				}
				else if(query == 3)//adds entry to copy
				{
					if(copy == true)//precondition: copy has been made
					{
						std::string word;
        				std::string definition;
						
						std::cout << "Word to be added: ";
						std::cin.ignore(1, '\n');
						std::getline (std::cin,word);
						
						
						std::cout << "Definition of " << word << ": ";
						//std::cin.ignore(1, '\n');
						std::getline (std::cin,definition);
						
						makeLowercase(word);
						makeLowercase(definition);
						
						if(bstCopy.contains(word))//precondition: word is not currently in dictionary
						{
							std::cout << "Dictionary currently contains " << word << "." << '\n'; 
							std::cout << word << " not added" <<'\n'; 
						}
						else
						{
							bstCopy.add(DictionaryEntry(word, definition));
							std::cout << "**********  Entry added to dictionary.  **********" << '\n';
						}
						
					}
					else
					{
						std::cout << "Additions cannot be made to original Dictionary. Make a Copy first." << '\n';
					}
					std::cout << '\n' << '\n' << '\n';
				}
				else if(query == 4)//deletes entry from copy
				{
					if(copy == true)//precondition: copy has been made
					{
						std::string word;
						
						std::cout << "Word to be removed: ";
						std::cin.ignore(1, '\n');
						std::getline (std::cin,word);
						
						
						makeLowercase(word);
						
						if(!bstCopy.contains(word))//precondition: word is currently in dictionary
						{
							std::cout << "Dictionary does not contain " << word << "." << '\n';
						}
						else
						{
							bstCopy.remove(word);
							std::cout << "**********  Entry removed from dictionary.  **********" << '\n';
						}
						
					}
					else
					{
						std::cout << "Deletions cannot be made to original Dictionary. Make a Copy first." << '\n';
					}
					std::cout << '\n' << '\n' << '\n';
				}
				else if(query == 5)//Save
				{
					std::string outputFile;
					int dictionary = 0;
					int traversal = 0;

					std::cout << "Output file name: ";
					std::cin >> outputFile;
					
					output.open(outputFile);
					
					std::cout << "Choose which dictionary to save." << '\n';
					std::cout << "1. Original" << '\n';
					std::cout << "2. Copy" << '\n';
					std::cin >> dictionary;
					std::cout << '\n';
					
					while((dictionary != 1) && (dictionary != 2))
					{
						std::cout << "Invalid selection. Please select option 1 or 2: ";
						std::cin >> dictionary;
					}
					
					std::cout << "Choose a traversal." << '\n';
					std::cout << "1. Inorder" <<'\n';
					std::cout << "2. Preorder" <<'\n';
					std::cout << "3. Postorder" <<'\n';
					std::cin >> traversal;
					std::cout << '\n';
					
					while(traversal != 1 && traversal != 2 && traversal != 3)
					{
						std::cout << "Invalid selection. Please select option 1, 2, or 3: ";
						std::cin >> traversal;
					}
					
					//save each dictionary entry 
					//based on chosen dictionary and traversal type
					if(dictionary == 1) 
					{
						if(traversal == 1)
						{
							bst.inorderTraverse(save);
						}
						if(traversal == 2)
						{
							bst.preorderTraverse(save);
						}
						if(traversal == 3)
						{
							bst.postorderTraverse(save);
						}
      				}
	  				else 
					{
						if(traversal == 1)
						{
							bstCopy.inorderTraverse(save);
						}
						if(traversal == 2)
						{
							bstCopy.preorderTraverse(save);
						}
						if(traversal == 3)
						{
							bstCopy.postorderTraverse(save);
						}
					}
					std::cout << "Dictionary has been saved." <<'\n';
					std::cout << '\n' << '\n' << '\n';
					output.close();

				}
				else if(query == 6)//Test
				{
					int test = 0;
					
					std::cout << "Choose a test." << '\n';
					std::cout << "1. Test Add " << '\n';
					std::cout << "2. Test Remove " << '\n';
					std::cout << "3. Test Write to New File" << '\n';
					std::cin >> test;
					
										
					while(test != 1 && test != 2 && test != 3)
					{
						std::cout << "Invalid selection. Please select option 1, 2, or 3: ";
						std::cin >> test;
					}
					
					if(test == 1)
					{
						testAdds(bst);
					}
					else if(test == 2)
					{
						testRemoves(bst);
					}
					else
					{
						testWriteToFile(bst);
					}
					
					std::cout << '\n' << '\n' << '\n';
					std::cout << "**********  Test has been performed.  **********" << '\n'; 
					std::cout << '\n' << '\n' << '\n';
				}
				else if(query == 7)//Quits
				{	
				}
				else //invalid selection
				{
					std::cout << "**********  INVALID SELECTION.  **********" << '\n' << '\n';
				}			

			}
			
		}
		else
		{
			std::cout << "Dictionary Does Not Exist!" << '\n';
		}
    }
	else
    {
        std::cout<<"Improper arguments" << '\n';  
    }
	
	return 0;
}

void makeLowercase(std::string& input)
{
	for(int l=0; l<input.length(); l++)
	{
		input[l] = tolower(input[l]);
	}
	//std::transform(input.begin(), input.end(), input.begin(), ::tolower());
	//return(input);
}

void printMenu()
{
	std::cout << "**************************" << '\n';	
	std::cout << "Select a Query Option" << '\n';
	std::cout << "**************************" << '\n';	
	std::cout << "1. Search" << '\n';
	std::cout << "2. Copy" << '\n';
	std::cout << "3. Add Entry" << '\n';
	std::cout << "4. Remove Entry" << '\n';
	std::cout << "5. Save" << '\n';
	std::cout << "6. Test" << '\n';
	std::cout << "7. Quit" << '\n';
	std::cout << "Selection: ";
}

void printEntry(DictionaryEntry entry) 
{
  std::cout << entry.getWord() << "  " << entry.getDefinition() << '\n';
}

void save(DictionaryEntry entry) 
{
  output << entry.getWord() << "  " << entry.getDefinition() << '\n';
}

void testAdds(BinarySearchTree<DictionaryEntry, std::string> dictionary)
{
	std::string word;
	std::string definition;
						
	std::cout << "Word to be added: ";
	std::cin.ignore(1, '\n');
	std::getline (std::cin,word);
						
						
	std::cout << "Definition of " << word << ":";
	std::cin.ignore(1, '\n');
	std::getline (std::cin,definition);
		
	makeLowercase(word);
	makeLowercase(definition);
	
	if(dictionary.contains(word))//precondition: word is not currently in dictionary
	{
		std::cout << "Dictionary currently contains " << word << "." << '\n'; 
		std::cout << word << " not added" <<'\n'; 
	}
	else
	{
		dictionary.add(DictionaryEntry(word, definition));
	}
	
	std::cout << '\n' << '\n' << '\n';
	std::cout << "**************************" <<'\n';
	std::cout << "Current Dictionary" <<'\n';
	std::cout << "**************************" <<'\n';
	dictionary.inorderTraverse(printEntry);

}

void testRemoves(BinarySearchTree<DictionaryEntry, std::string> dictionary) 
{
	std::string word;
						
	std::cout << "Word to be removed: ";
	std::cin.ignore(1, '\n');
	std::getline (std::cin,word);

	makeLowercase(word);
						
	if(!dictionary.contains(word))//precondition: word is currently in dictionary
	{
		std::cout << "Dictionary does not contain " << word << "." << '\n';
	}
	else
	{
		dictionary.remove(word);
	}
	
	std::cout << '\n' << '\n' << '\n';
	std::cout << "**************************" <<'\n';
	std::cout << "Current Dictionary" <<'\n';
	std::cout << "**************************" <<'\n';
	dictionary.inorderTraverse(printEntry);

}

void testWriteToFile(BinarySearchTree<DictionaryEntry, std::string> dictionary) 
{
	std::string outputFile;
  
	std::cout << "Output file name: ";
	std::cin >> outputFile;
	
	output.open(outputFile);
	dictionary.inorderTraverse(save);
	output.close();
}

