//
//  main.cpp
//  StudentArray
//
//  Created by Andrew Tran on 12/8/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// constants
#define MAX_SIZE 20

int main() {
   int value = 0;
   string newName, strValue;
   string student[MAX_SIZE];

   // initialize the array
   for(int k = 0; k < MAX_SIZE; k++)
      student[k] = "undefined";

   // infinite loop until user enters q or cancels
   while(true) {
      // get string from user
      cout << "\n\nChoose a student to edit from 0 to " << MAX_SIZE-1
         << "\n('q' to end program): ";
      getline(cin, strValue);

      // see if user wanted to exit
      if(strValue[0] == 'q')
         return 0;

      // convert to number
      istringstream(strValue) >> value; // week 4 lesson A.2
      if(value < 0 || value > MAX_SIZE-1)
         continue;

      // get new name for this student
      cout << "\n\nEditing student " << value << ": '" << student[value]
         << "'\nEnter new name: ";
      getline(cin, newName);

      student[value] = newName;
   }

   return 0;
}
