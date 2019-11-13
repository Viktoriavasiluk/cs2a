//
//  main.cpp
//  Card
//
//  Created by Andrew Tran on 12/8/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

enum Suit { clubs, diamonds, hearts, spades };

// class Card prototype -----------------------
class Card {
private:
   char value;
   Suit suit;
public:
   Card(char value = 'A', Suit suit = spades);
   string toString();
   bool set(char value = 'A', Suit suit = spades);
   char getVal();
   Suit getSuit();
};  // end of class Card prototype --------------

int main() {
   Card *card1, *card2, *card3;
   card1 = new Card;
   card2 = new Card('5');
   card3 = new Card('9', hearts);

   Card *card4 = new Card('j', clubs), *card5 = new Card('1', diamonds);

   if(! card1->set(2, clubs))
      cout << "incorrect value (2, clubs) passed to card::set()\n\n";
   if(! card1->set('2', clubs))
      cout << "incorrect value ('2', clubs) passed to card::set()\n\n";

   cout << card1->toString() << endl << card2->toString() << endl
      << card3->toString() << endl << card4->toString() << endl
      << card5->toString() << endl << endl;

   *card1 = *card4;
   cout << "after assigning *card4 to *card1:\n";
   cout << card1->toString() << endl << card4->toString() << endl << endl;

   delete card1;  // need this before the next line, else get silent memory leak.
   card1 = card4;
   cout << "after assigning card4 to card1:\n";
   cout << card1->toString() << endl << card4->toString() << endl << endl;

   delete card1;   // actually deleting what was originally card4
   delete card2;
   delete card3;
   // delete card4;  if you don't omit this you'll get a run-time error
   delete card5;
}

// beginning of Card method definitions -------------

// constructor
Card::Card(char value, Suit suit) {
   // if not valid, set to Ace of Spades
   if(!set(value, suit))
      set('A', spades);
}

// stringizer
string Card::toString() {
   string retVal;
   char strVal[2];

   // convert char to a CString
   strVal[0] = value;
   strVal[1] = '\0';

   // convert from CString to s-c string
   retVal = string(strVal);

   if(suit == spades)
      retVal += " of Spades";
   else if(suit == hearts)
      retVal += " of Hearts";
   else if(suit == diamonds)
      retVal += " of Diamonds";
   else if(suit == clubs)
      retVal += " of Clubs";

   return retVal;
}

// mutator
bool Card::set(char value, Suit suit) {
   char upVal;

   // convert to uppercase to simplify
   upVal = toupper((int)value);

   // check for validity
   if(upVal == 'A' || upVal == 'K' || upVal == 'Q' || upVal == 'J'
      || upVal == 'T' || (upVal >= '2' && upVal <= '9')) {
      this->suit = suit;
      this->value = upVal;
      return true;
   }
   else
      return false;
}

// accessors
char Card::getVal() {
   return value;
}
Suit Card::getSuit() {
   return suit;
}
// end of Card method definitions  --------------
