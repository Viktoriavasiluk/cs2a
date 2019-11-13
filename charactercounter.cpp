//
//  main.cpp
//  CharacterCounter
//
//  Created by Andrew Tran on 12/8/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

// class Frequency prototype -----------------------
class Frequency {
private:
   static const int MAX_SIZE = 100000;
   int count[MAX_SIZE];
   int size;
public:
   Frequency(int size = 26);
   int get(int index);
   void increment(int index);
   void decrement(int index);
};
// end of class Frequency prototype --------------

// class CharacterCounterprototype -----------------------
class CharacterCounter {
private:
   Frequency letters;
   string userString;

public:
   CharacterCounter(string str);
   long getCount(char let);
private:
   void countOccurrences();

};
// end of CharacterCounter method definitions  --------------

int main() {
   string userPhrase;

   cout << "Enter a phrase or sentence: " << endl;
   getline(cin, userPhrase);

   // create a CharacterCounter object for this phrase
   CharacterCounter freq(userPhrase);

   // display whole table
   for(char let = 'A'; let <= 'Z'; let++) {
      // every 5 items, generate a newline
      if ( (let - 'A') % 5 == 0)
         cout << endl;

      cout << let << ": " << freq.getCount(let) << "     ";
   }
}

// beginning of Frequency method definitions -------------
Frequency::Frequency(int size) {
   if(size <= 0 || size > MAX_SIZE)
      size = MAX_SIZE;
   this->size = size;
   for(int k=0; k < size; k++)
      count[k] = 0;
}
int Frequency::get(int index) {
   if(index >= 0 && index < size)
      return count[index];
   else
      return -1;
}
void Frequency::increment(int index) {
   if(index >= 0 && index < size)
      count[index]++;
}

void Frequency::decrement(int index) {
   if(index >= 0 && index < size)
      if(count[index] > 0)
         count[index]--;
}
// end of Frequency method definitions  --------------

// beginning of CharacterCounter  method definitions -------------
CharacterCounter::CharacterCounter(string str) {
   // if string is not good, use empty string
   if(str.length() >= 1)
      userString = str;
   else
      userString = "";
   countOccurrences();
}

void CharacterCounter::countOccurrences() {
   char let;
   int k;

   // letters[] automatically initialized to all 0s
   // scan the string and increment as we go
   for(k = 0; k < userString.length(); k++) {
      let = toupper(userString[k]);
      letters.increment(let - 'A');  // note cute conversion
   }
}

long CharacterCounter::getCount(char let) {
   char upLet;
   upLet = toupper(let);
   return letters.get(upLet - 'A');
}
// end of CharacterCounter method definitions  --------------
