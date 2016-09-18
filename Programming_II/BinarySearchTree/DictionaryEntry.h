/*
 * File Name: DictionaryEntry.h
 * Author: Brandon Lammey
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu
 * Homework: Lab 10
 * Description: This object will hold a dictionary entry with two strings: word and its defition. In addition operator overloads are included 
 */


#ifndef DICTIONARY_ENTRY
#define DICTIONARY_ENTRY

#include "BinaryNode.h"
#include "BinarySearchTree.h"


class DictionaryEntry
{
private:
	std::string m_word;
	std::string m_defn;
public:
	//constructor
	DictionaryEntry(std::string w, std::string d);
	
	//get methods
	std::string getDefinition();
	std::string getWord() const;
	
	//operator overloads for comparison
	bool operator<(const DictionaryEntry& rightSide) const;
	bool operator>(const DictionaryEntry& rightSide) const;
	bool operator==(const DictionaryEntry& rightSide) const;
	
	bool operator<(const std::string& rightSide) const;
	bool operator>(const std::string& rightSide) const;
	bool operator==(const std::string& rightSide) const;
};

#endif

