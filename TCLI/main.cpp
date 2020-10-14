//
//  main.cpp
//  TournalCLI
//
//  Created by Bruno Köppel on 9/24/20.
//

#include "Checklist.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <iomanip>

void clear_cin();
string printHelpMenu();


void verifyLastUser();
string loadPreviousSessionUserName(fstream &inputFromFile);
string loadFileWithPreviousSession(fstream &inputFromFile);
string confirmationOfPreviousSession(string userName);
string switchUserName();
void lookForUsersDatabaseOrCreateNew(string name, fstream &fileManage, Checklist app[]);
void populateDatabaseFromFile(string name, fstream &fileManage, Checklist tempList[]);
void parseItemsOnDatabase(string inputBuffer, int i, Checklist app[]);
void outputToDatabase(string name, fstream &outputToFile);

bool processCommand (string command, Checklist app[]);
string parseCommand(string command);
bool createNewItem(string command, Checklist app[]);
bool displayTodoList(Checklist app[]);

unsigned long splitUserInputCommand(string userInputCommand[]);
unsigned long validateCommand(string command[], bool &validCommand);



using namespace std;

string TCLIversion = "0.0.1";

int main() {
    fstream inputFromFile;
    fstream outputToFile;
    string command = "";
    string userInputCommand[10];
    string userName;
    bool programState = true;
    Checklist app[1000];
    
    cout << "Tournal Command Line Interface (TCLI)" << endl;
    cout << "Current Version: " + TCLIversion << endl;
    
    userName = loadPreviousSessionUserName(inputFromFile);
    lookForUsersDatabaseOrCreateNew(userName, inputFromFile, app);
    outputToDatabase(userName, outputToFile);
    
    
    
    while (programState)
    {
        cout << userName + "@TCLI~" + TCLIversion + "~$ " ;
        getline(cin, command);
        programState = processCommand(command, app);
    }
    
    return 0;
}


// clear cin is just a function to clear the buffer
void clear_cin()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

/**
 This menu prints us the menutes that work for this command line.
 */
string printHelpMenu()
{
    stringstream helpMenu;
    helpMenu << "\"help\" command prints this menu for documentation purposes" << endl;
    helpMenu << "\"exit\" command exits the application" << endl;
    return helpMenu.str();
}


/**
 This funcition will check a file on the database and let us know what's the name of the last user who used the tool.
 
 It will ask for the user to verify if it's them or ask us to enter a new username.
 */
string loadPreviousSessionUserName(fstream &inputFromFile)
{
    string userName = loadFileWithPreviousSession(inputFromFile);
    if (userName == "")
    {
        cout << "Enter your name to start a new database: ";
        getline(cin, userName);
        
    }
    else
    {
        cout << "logging into " << userName << "'s last session"<< endl;
        userName = confirmationOfPreviousSession(userName);
    }
    return userName;
}

/**
 Once the identity has been verified we will load their information using the username they provided
 */
string loadFileWithPreviousSession(fstream &inputFromFile)
{
    string userName;
    inputFromFile.open("lastestUserUsingTheApp.txt", ios::in);
    if (!inputFromFile)
    {
        cout << "Creating New User Profile" << endl;
    }
    else
    {
        getline(inputFromFile, userName);
    }
    inputFromFile.close();
    return userName;
}

/**
 This function will ask us to confirm if we are said user.
 */
string confirmationOfPreviousSession(string userName)
{
    char confirmation;
    bool runLoop = true;
    do {
        cout << "Enter Y/N to confirm: ";
        cin >> confirmation;
        if (confirmation == 'n' or confirmation == 'N')
        {
            userName = switchUserName();
            runLoop = false;
        }
        else if (confirmation == 'y' or confirmation == 'Y')
        {
            runLoop = false;
            clear_cin();
        }
        else
        {
            cout << "you did not enter the right command." << endl;
            clear_cin();
        }
        
    } while (runLoop);
    return userName;
}

string switchUserName()
{
    clear_cin();
    string userName;
    cout << "Enter your Name to fetch or start a new database: ";
    getline(cin, userName);
    return userName;
}

void lookForUsersDatabaseOrCreateNew(string name, fstream &inputFromFile, Checklist app[])
{
    inputFromFile.open(name + ".txt", ios::in);
    
    if (!inputFromFile)
    {
        cout << "New Database created under the name \"" << name << "\"" << endl;
    }
    else
    {
        populateDatabaseFromFile(name, inputFromFile, app);
        cout << "database loaded" << endl;
    }
    inputFromFile.close();
}


void populateDatabaseFromFile(string name, fstream &inputFromFile, Checklist app[])
{
    string inputBuffer;
    int todoIndex = 0;
    cout << "\n\n";
    cout << setw(8) << left << "ITEM ID" <<
            setw(10)<< left << "finished?" <<
            setw(10)<< left << "Priority" <<
            setw(40)<< left << "Activity to do" <<
    setw(25)<< left << "Date that is due" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    while(getline(inputFromFile, inputBuffer))
    {
        parseItemsOnDatabase(inputBuffer, todoIndex, app);
        todoIndex++;
    }
    
    cout << "\n\n";
}

void parseItemsOnDatabase(string inputBuffer, int todoIndex, Checklist app[])
{
    
    size_t delimeterPos = inputBuffer.find('/');
    string name = inputBuffer.substr(0, delimeterPos);
    inputBuffer = inputBuffer.substr(delimeterPos + 1);
    delimeterPos = inputBuffer.find('/');
    int conditionNumber = inputBuffer[0] - 48;
    delimeterPos = inputBuffer.find('/');
    inputBuffer = inputBuffer.substr(delimeterPos + 1);
    int priority = inputBuffer[0] - 48;
    delimeterPos = inputBuffer.find('/');
    inputBuffer = inputBuffer.substr(delimeterPos + 1);
    string date = inputBuffer.substr(0);
    bool condition;
    
    if (conditionNumber == 1)
    {
        condition = true;
    }
    else
    {
        condition = false;
    }
    
    app[todoIndex] = Checklist(name, priority, condition, date);
    cout << app[todoIndex].displayItem(todoIndex) << endl;
    
}

void outputToDatabase(string name, fstream &outputToFile)
{
    outputToFile.open(name, ios::out);
}






bool processCommand (string command, Checklist app[])
{
    size_t delimeterPos = command.find(' ');
    string action = command.substr(0, delimeterPos);
    
    while (action == "")
    {
        command = command.substr(delimeterPos + 1);
        delimeterPos = command.find(' ');
        action = command.substr(0, delimeterPos);
    }
    
    command = command.substr(delimeterPos + 1);
    
    if (action == "create")
    {
        return createNewItem(command, app);
    }
    else if (action == "display")
    {
        return displayTodoList(app);
    }
    else if (action == "delete")
    {
        return true;
    }
    else if (action == "modify")
    {
        return true;
    }
    else if (action == "duplicate")
    {
        return true;
    }
    else if (action == "exit")
    {
        return false;
    }
    else {
        cout << "Command not recognized." << endl;
        return true;
    }
    return true;
}

string parseCommand(string command){
    string item = "";
    return item;
}

bool createNewItem(string command, Checklist app[])
{
    int todoIndex = 0;
    while (app[todoIndex].getName() != ""){
        todoIndex++;
    }
    app[todoIndex] = Checklist(command);
    return true;
}

bool displayTodoList(Checklist app[]){
    
    cout << "\n\n";
    cout << setw(8) << left << "ITEM ID" <<
            setw(10)<< left << "finished?" <<
            setw(10)<< left << "Priority" <<
            setw(40)<< left << "Activity to do" <<
    setw(25)<< left << "Date that is due" << endl;
    cout << "------------------------------------------------------------------------------------" << endl;
    
    for (int todoIndex = 0; todoIndex < 1000; todoIndex++){
        if (app[todoIndex].getName() != "") {
            cout << app[todoIndex].displayItem(todoIndex) << endl;
        }
    }
    
    cout << "\n\n";
    return true;
}








