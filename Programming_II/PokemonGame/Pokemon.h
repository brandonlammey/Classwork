/*
 * File Name: Pokemon.h
 * Author: Brandon Lammey 
 * KUID: 2855296
 * Email Address: archerlammey@ku.edu 
 * Homework: Lab 01
 * Description: This is the header file for a pokemon object that has the variables hp,
 * attackLevel, defenselevel, and name.  
 */

#include <string>
#ifndef POKEMON_H
#define POKEMON_H

class Pokemon
{
 //health, attack, defense, and name of Pokemon 
 private: 
    int m_hp;
    int m_attackLevel;
    int m_defenseLevel;
    std::string m_name;
 
 public:
    //constructor
    //initializes all numeric data to 0 and strings to “”
    Pokemon();
 
    //reduces m_hp by amount
    //doesn’t prevent m_hp from becoming negative
    void reduceHP(int amount);
 
    //get methods
    int getHp() const;
 
    int getAttackLevel() const;
 
    int getDefenseLevel() const;
    
    std::string getName() const; 
 
    //set methods 
    void setHp(int h);
 
    void setAttackLevel(int a);
 
    void setDefenseLevel(int d);
 
    void setName(std::string n);
 
 };

#endif
