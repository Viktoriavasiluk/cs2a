//
//  main.cpp
//  Project_4
//
//  Created by Andrew Tran on 11/26/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Greetings {
private:
   string recipient, sender, message, occasion;

public:
   static int count;
   static const int MIN_CHAR = 1;
   static const string DEFAULT_RECIP;
   static const string DEFAULT_SEND;
   static const string DEFAULT_MSG;
   static const string DEFAULT_OCC;

   Greetings();
   Greetings(string recip, string send, string msg, string occ);

   bool setRecipient(string recip);
   bool setSender(string send);
   bool setMessage(string msg);
   bool setOccasion(string occ);
   string getRecipient();
   string getSender();
   string getMessage();
   string getOccasion();
};

int Greetings::count = 0;
const string Greetings::DEFAULT_RECIP = "You";
const string Greetings::DEFAULT_SEND = "Anonymous";
const string Greetings::DEFAULT_MSG = "Happy holidays from our family to yours!";
const string Greetings::DEFAULT_OCC = "day";

int main() {
   Greetings christmas;
   Greetings birthday;
   string userInput;

   //user input for card #1
   cout << "Who is receiving the first card? ";
   getline(cin, userInput);
   christmas.setRecipient(userInput);
   cout << "Who is sending the first card? ";
   getline(cin, userInput);
   christmas.setSender(userInput);
   cout << "Enter message: ";
   getline(cin, userInput);
   christmas.setMessage(userInput);
   cout << "What is the special occasion? ";
   getline(cin, userInput);
   christmas.setOccasion(userInput);

   //user input for card #2
   cout << "\nWho is receiving the second card? ";
   getline(cin, userInput);
   birthday.setRecipient(userInput);
   cout << "Who is sending the second card? ";
   getline(cin, userInput);
   birthday.setSender(userInput);
   cout << "Enter message: ";
   getline(cin, userInput);
   birthday.setMessage(userInput);
   cout << "What is the special occasion? ";
   getline(cin, userInput);
   birthday.setOccasion(userInput);

   cout << "- - - - - - - - - - - - - - - - - - - - - - - -";
   cout << "\nCard #1\nTo: " << christmas.getRecipient() << "\nFrom: "
      << christmas.getSender() << "\n\"" << christmas.getMessage()
      << "\"\nHave a wonderful " << christmas.getOccasion() << "!" << endl;
   cout << "\nCard #2\nTo: " << birthday.getRecipient() << "\nFrom: "
   << birthday.getSender() << "\n\"" << birthday.getMessage()
   << "\"\nHave a wonderful " << birthday.getOccasion() << "!" << endl;

   return 0;
}

//initialize constructors
Greetings::Greetings() {
   recipient = DEFAULT_RECIP;
   sender = DEFAULT_SEND;
   message = DEFAULT_MSG;
   occasion = DEFAULT_OCC;
   count++;
}
Greetings::Greetings(string recip, string send, string msg, string occ) {
   if(!setRecipient(recip)) {
      recipient = DEFAULT_RECIP;
   }
   if(!setSender(send)) {
      sender = DEFAULT_SEND;
   }
   if(!setMessage(msg)) {
      message = DEFAULT_MSG;
   }
   if(!setOccasion(occ)) {
      occasion = DEFAULT_OCC;
   }
   count++;
}

//class accessors
string Greetings::getRecipient() {
   return recipient;
}
string Greetings::getSender() {
   return sender;
}
string Greetings::getMessage() {
   return message;
}
string Greetings::getOccasion() {
   return occasion;
}

//class mutators
bool Greetings::setRecipient(string recip) {
   if(recip.length() < MIN_CHAR) {
      return false;
   }
   recipient = recip;
   return true;
}
bool Greetings::setSender(string send) {
   if(send.length() < MIN_CHAR) {
      return false;
   }
   sender = send;
   return true;
}
bool Greetings::setMessage(string msg) {
   if(msg.length() < MIN_CHAR) {
      return false;
   }
   message = msg;
   return true;
}
bool Greetings::setOccasion(string occ) {
   if(occ.length() < MIN_CHAR) {
      return false;
   }
   occasion = occ;
   return true;
}
