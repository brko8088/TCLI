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
    int ID;
    string name;
    int priority;
    bool isItDone;
    string dueDate;
    
public:
    Checklist(){
        name = "";
        priority = 0;
        isItDone = false;
        dueDate = "";
    }
    
    Checklist(string newName, int newPriority, bool newCondition, string newDate){
        setName(newName);
        setPriority(newPriority);
        setItemFinished(newCondition);
        setDueDate(newDate);
    }
    
    
    void setName(string name)
    {
        name = name;
    };
    
    void setPriority(int number)
    {
        priority = number;
    };
    
    void setItemFinished(bool condition)
    {
        isItDone = condition;
    };
    
    void setDueDate(string date)
    {
        dueDate = date;
    };
    
    
    
    string getName()
    {
        return name;
    }
    
    int getPriority()
    {
        return priority;
        
    }
    
    bool getState()
    {
        return isItDone;
    }
    
    string getDueDate()
    {
        return dueDate;
    }
    
    
    string printState();
    string printPriority();
    string displayItem(int i);
};

#endif /* Checklist_hpp */

