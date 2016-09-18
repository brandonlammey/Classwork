/*
 * File Name: DictionaryEntry.cpp
 * Author: Brandon Lammey
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu
 * Homework: Lab 10
 * Description: Implementation of dictionary entry 
 */

#include<iostream>
#include<string>
#include "DictionaryEntry.h"


DictionaryEntry::DictionaryEntry(std::string w, std::string d): m_word(w), m_defn(d)
{
	m_word = w;
    m_defn = d;
}

std::string DictionaryEntry::getDefinition()
{
    return (m_defn);
}

std::string DictionaryEntry::getWord() const
{
    return(m_word);
}

bool DictionaryEntry::operator<(const DictionaryEntry& rightSide) const
{
    std::string str1 = this->getWord();
    std::string str2 = rightSide.getWord();
    
    if(str1.compare(str2) < 0)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

bool DictionaryEntry::operator>(const DictionaryEntry& rightSide) const
{
    std::string str1 = this->getWord();
    std::string str2 = rightSide.getWord();
    
    if(str1.compare(str2) > 0)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

bool DictionaryEntry::operator==(const DictionaryEntry& rightSide) const
{
    std::string str1 = this->getWord();
    std::string str2 = rightSide.getWord();

    if(str1.compare(str2) == 0)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}


bool DictionaryEntry::operator<(const std::string& rightSide) const
{
    std::string str1 = this->getWord();
    std::string str2 = rightSide;
    
    if(str1.compare(str2) < 0)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

bool DictionaryEntry::operator>(const std::string& rightSide) const
{
    std::string str1 = this->getWord();
    std::string str2 = rightSide;
    
    if(str1.compare(str2) > 0)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

bool DictionaryEntry::operator==(const std::string& rightSide) const
{
    std::string str1 = this->getWord();
    std::string str2 = rightSide;

    if(str1.compare(str2) == 0)
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

