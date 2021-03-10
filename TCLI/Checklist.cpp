//
//  Checklist.cpp
//  TournalCLI
//
//  Created by Bruno Köppel on 10/3/20.
//

#include "Checklist.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

void Checklist::deleteTodo()
{
    setName("");
    setPriority(0);
    setItemFinished(false);
    setDueDate("");
}

string Checklist::displayItem()
{
    stringstream item;
    item << setw(8)  << left << ;
    item << setw(2) << left << "[";
    item << setw(2) << left << printState();
    item << setw(8) << "]";
    item << setw(8) << left << printPriority();
    item << setw(40) << left << getName();
    item << setw(25) << left << getDueDate();
    return item.str();
}

string Checklist::printPriority()
{
    stringstream text;
    int num = getPriority();
    if (num == 0){text << "";}
    else if (num == 1){text << "!";}
    else if (num == 2){text << "!!";}
    else if (num == 3){text << "!!!";}
    return text.str();
}

string Checklist::printState()
{
    stringstream text;
    bool con = getState();
    if (con)
        text << "x";
    else
        text << " ";
    return text.str();
}
