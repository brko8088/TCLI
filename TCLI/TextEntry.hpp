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

using namespace std;
static int paragraphAmount = 0;

class TextEntry {
    
    private:
    
    string title;
    string paragraph[1];
    time_t timeStamp[1];
    
    public:
    
    TextEntry(){
        setTitle("");
        setParagraph(0);
        paragraphAmount++;
    }
    
    TextEntry(string newTitle){
        setTitle(newTitle);
        paragraphAmount++;
    }
    
    TextEntry(string newTitle, int newPriority, bool newCondition, string newDate){
        setTitle(newTitle);
        paragraphAmount++;
    }
    
    
    void setTitle(string title)
    {
        this->title = title;
    };
    
    void setParagraph(int paragraphNumber)
    {
        this->paragraph[paragraphAmount] = paragraphNumber;
    };
    
    void setTimeStamp(int paragraphNumber)
    {
        auto currentTime = std::chrono::system_clock::now();
        this->timeStamp[paragraphNumber] = std::chrono::system_clock::to_time_t(currentTime);
    };
    
    string getTitle()
    {
        return title;
    }
    
    string getparagraph (int index)
    {
        return paragraph[index];
    }
    
    time_t getTimeStamp (int index)
    {
        return timeStamp[index];
    }
    
    string displayTextEntry();
};

#endif /* TextEntry_hpp */
