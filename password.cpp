//
//  main.cpp
//  Password
//
//  Created by Andrew Tran on 11/11/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
   string password;
   bool validated;
   char letter;
   int length;
   const int MIN_LENGTH = 6;
   const int MAX_LENGTH = 15;

   // Get password candidate from console, until it passes our tests
   validated = false;
   while(!validated) {
      // get the password candidate from user
      cout << "\nEnter a password, whose length is between "
         << MIN_LENGTH << " and " << MAX_LENGTH
         << " characters, inclusive.\nOnly letters and numbers allowed.\n"
         "First letter must be non-numeral.\n"
         "Your new password (or 'q' to quit): ";
      getline(cin, password);

      length = (int) password.length();

      // test for quit first
      if(length == 1 && (password[0] == 'q' || password[0] == 'Q')) {
         cout << "No password defined.\n";
         break;  // from loop
      }

      // test for reasonable length
      if(length < MIN_LENGTH || length > MAX_LENGTH) {
         cout << "Password must be between " << MIN_LENGTH << " and "
         << MAX_LENGTH << " characters in length.\n";
         continue;
      }

      validated = true;   // assume innocent entering loop
                          // allow only letters and numbers
      for(int k = 0; k < length; k++) {
         // store in local variable so we can reuse
         letter = password[k];
         if(isalnum(letter)) {
            continue;
         } else {
            //  this letter is not one of the three legal types
            cout << "Use only A-Z, a-z or 0-9, please.\n";
            validated = false;
            break;   // from the for loop leaving validated as false
         }
      }

      // if the above loop yielded an error, we try again
      if(!validated) {
         continue;
      }

      // if we made it here, it is the proper length and has legal chars
      // but is the first character a letter?
      letter = password[0];
      if(!isalpha(letter)) {
         cout << "First character must be a letter (non-numeric).\n";
         validated = false;
         continue;
      } else {
         // they passed the final test
         cout << "\nYour password '" + password + "' has been accepted.\n";
         // no need for break since good while() condition
      }
   }

   cout << "\nGood bye.\n\n";
}

/* ----------- Output ----------------

 Enter a password, whose length is between 6 and 15 characters, inclusive.
 Only letters and numbers allowed.
 First letter must be non-numeral.
 Your new password (or 'q' to quit): A99z
 Password must be between 6 and 15 characters in length.

 Enter a password, whose length is between 6 and 15 characters, inclusive.
 Only letters and numbers allowed.
 First letter must be non-numeral.
 Your new password (or 'q' to quit): aLonger39Password
 Password must be between 6 and 15 characters in length.

 Enter a password, whose length is between 6 and 15 characters, inclusive.
 Only letters and numbers allowed.
 First letter must be non-numeral.
 Your new password (or 'q' to quit): okay try this
 Use only A-Z, a-z or 0-9, please.

 Enter a password, whose length is between 6 and 15 characters, inclusive.
 Only letters and numbers allowed.
 First letter must be non-numeral.
 Your new password (or 'q' to quit): 99isThis better?
 Password must be between 6 and 15 characters in length.

 Enter a password, whose length is between 6 and 15 characters, inclusive.
 Only letters and numbers allowed.
 First letter must be non-numeral.
 Your new password (or 'q' to quit): 99Better_now?
 Use only A-Z, a-z or 0-9, please.

 Enter a password, whose length is between 6 and 15 characters, inclusive.
 Only letters and numbers allowed.
 First letter must be non-numeral.
 Your new password (or 'q' to quit): 99tryThis
 First character must be a letter (non-numeric).

 Enter a password, whose length is between 6 and 15 characters, inclusive.
 Only letters and numbers allowed.
 First letter must be non-numeral.
 Your new password (or 'q' to quit): CS_144_xyz
 Use only A-Z, a-z or 0-9, please.

 Enter a password, whose length is between 6 and 15 characters, inclusive.
 Only letters and numbers allowed.
 First letter must be non-numeral.
 Your new password (or 'q' to quit): CS144xya

 Your password 'CS144xya' has been accepted.

 Good bye.

 Press any key to continue . . .

 ------------------------------------- */
