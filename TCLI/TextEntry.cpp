//
//  TextEntry.cpp
//  TCLI
//
//  Created by Bruno Köppel on 10/17/20.
//

#include "TextEntry.hpp"

void TextEntry::displayTextEntry()
{
    cout << "Titled: " + getTitle() << endl;
    for (int index = 0; index < this->textLine.size() ; index++)
    {
        cout << textLine[index] << endl;
    }
//        cout << "Time written: " + getTimeStamp() << endl;
}
