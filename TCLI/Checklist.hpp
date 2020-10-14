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
    
    
    void setName(string name)
    {
        todoName = name;
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
        return todoName;
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

