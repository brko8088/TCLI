//
//  Checklist.hpp
//  TournalCLI
//
//  Created by Bruno Köppel on 10/3/20.
//

#ifndef Checklist_hpp
#define Checklist_hpp

#include <stdio.h>
#include <string>
#include <iomanip>

using namespace std;

class Checklist
{
private:
    int ID = 0;
    string todoName;
    int priority;
    bool isItDone;
    string dueDate;
    
public:
    Checklist(){
        setName("");
        setPriority(0);
        setItemFinished(false);
        setDueDate("");
    }
    
    Checklist(string newName){
        setName(newName);
        setPriority(1);
        setItemFinished(false);
        setDueDate("No Date");
    }
    
    Checklist(string newName, int newPriority, bool newCondition, string newDate){
        setName(newName);
        setPriority(newPriority);
        setItemFinished(newCondition);
        setDueDate(newDate);
        
    }
    
    
    /*
     Setters
     */
    void setID(int newID)
    {
        this->ID = newID;
    }
    
    void setName(string name)
    {
        this->todoName = name;
    };
    
    void setPriority(int number)
    {
        this->priority = number;
    };
    
    void setItemFinished(bool condition)
    {
        this->isItDone = condition;
    };
    
    void setDueDate(string date)
    {
        this->dueDate = date;
    };
    
    
    /*
     Getters
     */
    int getID()
    {
        return this->ID;
        
    }
    
    string getName()
    {
        return this->todoName;
    }
    
    int getPriority()
    {
        return this->priority;
        
    }
    
    bool getState()
    {
        return this->isItDone;
    }
    
    string getDueDate()
    {
        return this->dueDate;
    }
    
    void deleteTodo();
    string printState();
    string printPriority();
    string displayItem(int i);
};

#endif /* Checklist_hpp */

