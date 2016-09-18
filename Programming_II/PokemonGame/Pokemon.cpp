
/*
 * File Name: Pokemon.cpp
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 01
 * Description: This is the implementation file for the pokemon object.  
 */

#include "Pokemon.h"

using namespace std; 
 
Pokemon::Pokemon()
{
	m_hp = 0;
	m_attackLevel = 0;
	m_defenseLevel = 0;

	m_name = "";
}
 
void Pokemon::reduceHP(int amount)
{
	m_hp = m_hp - amount; 
}
 
int Pokemon::getHp() const
{
	return(m_hp);
}
 
int Pokemon::getAttackLevel() const
{
	return(m_attackLevel);
}
 
int Pokemon::getDefenseLevel() const
{
	return(m_defenseLevel);
}
 
string Pokemon::getName() const
{
	return(m_name);
}
 
void Pokemon::setHp(int h)
{
	m_hp = h;
}
 
void Pokemon::setAttackLevel(int a)
{
	m_attackLevel = a;
}
 
void Pokemon::setDefenseLevel(int d)
{
	m_defenseLevel = d;
}
 
void Pokemon::setName(std::string n)
{
	m_name = "";
}
 
