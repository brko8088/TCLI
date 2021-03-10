//
//  TextEntry.hpp
//  TCLI
//
//  Created by Bruno Köppel on 10/17/20.
//

#ifndef TextEntry_hpp
#define TextEntry_hpp

#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <chrono>
#include <ctime>
#include <vector>

using namespace std;
static int textEntryNumber = 0;

class TextEntry {
    
    private:
    
    string title;
    vector<string> textLine;
    time_t timeStamp;
    
    public:
    
    TextEntry(){
        setTimeStamp(textEntryNumber);
        textEntryNumber++;
    }
    
    TextEntry(string newTitle){
        setTitle(newTitle);
        setTimeStamp(textEntryNumber);
        textEntryNumber++;
    }
    
    TextEntry(string newTitle, vector<string> textLine){
        setTitle(newTitle);
        setTextLine(textLine);
        setTimeStamp(textEntryNumber);
        
        displayTextEntry();
        
        textEntryNumber++;
    }
    
    
    void setTitle(string title)
    {
        this->title = title;
    };
    
    void setTextLine(vector<string> textLine)
    {
        this->textLine = textLine;
    };
    
    void setTimeStamp(int paragraphNumber)
    {
        auto currentTime = std::chrono::system_clock::now();
        timeStamp = std::chrono::system_clock::to_time_t(currentTime);
    };
    
    string getTitle()
    {
        return title;
    }
    
    string getTextLine (int index)
    {
        return textLine[index];
    }
    
    time_t getTimeStamp()
    {
        return timeStamp;
    }
    
    void displayTextEntry();
};

#endif /* TextEntry_hpp */
