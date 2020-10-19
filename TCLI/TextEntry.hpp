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
static int paragraphAmount = 0;

class TextEntry {
    
    private:
    
    string title;
    vector<string> paragraph;
    vector<time_t> timeStamp;
    
    public:
    
    TextEntry(){
        setTitle("");
        setParagraph("");
        setTimeStamp(paragraphAmount);
        paragraphAmount++;
    }
    
    TextEntry(string newTitle){
        setTitle(newTitle);
        setParagraph("");
        setTimeStamp(paragraphAmount);
        paragraphAmount++;
    }
    
    TextEntry(string newTitle, string newParagraph){
        setTitle(newTitle);
        setParagraph(newParagraph);
        setTimeStamp(paragraphAmount);
        paragraphAmount++;
    }
    
    
    void setTitle(string title)
    {
        this->title = title;
    };
    
    void setParagraph(string paragraph)
    {
        this->paragraph.push_back(paragraph);
    };
    
    void setTimeStamp(int paragraphNumber)
    {
        auto currentTime = std::chrono::system_clock::now();
        this->timeStamp.push_back(std::chrono::system_clock::to_time_t(currentTime));
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
