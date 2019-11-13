//
//  main.cpp
//  Gork
//
//  Created by Andrew Tran on 10/17/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
   int mainMenu, numPersonnel, selection, numSurvived = 4, numLost = 0;

   cout << "Welcome to Gork v1.0!\n"
      "What would you like to do?\n"
      "1. Play Gork\n"
      "2. Exit\n"
      "> ";
   cin >> mainMenu;

   switch(mainMenu) {
      case 1:
         //run game
         cout << "You are in charge of a top secret military mission "
            "when your space ship makes an emergency landing "
            "on the largest moon of planet Gork. The space ship is damaged. "
            "Oxygen levels in the space ship begin to drop." << endl;
         cout << "How many military personnel are on your ship? ";
         cin >> numPersonnel;
         cout << "Choose one:\n"
            "1. Attempt repairs on the ship.\n"
            "2. Request an emergency rescue from mission command.\n"
            "3. Break protocol and reveal the top secret space ship's location "
            "to the Russians on a nearby moon to ask for their assistance.\n"
            "> ";
         cin >> selection;

         switch(selection) {
            case 1:
               cout << "Toxic material on the moon has corroded the launch gear "
                  "and the launch exploded." << endl;
               break;
            case 2:
               cout << "Oxygen depleted before the rescue team arrived." << endl;
               if(numPersonnel <= 4) {
                  numSurvived = numPersonnel;
               } else {
                  numLost = numPersonnel - numSurvived;
               }
               cout << numSurvived << " people were rescued. " << numLost
                  << " people were lost." << endl;
               break;
            case 3:
               cout << "The Russians agree to send a rescue ship but secretly "
                  "attempt to hack into the ship's systems remotely, which "
                  "triggers an automatic shut down of all communications "
                  "systems and locks all mission critical storage units, "
                  "including one of the storage units that holds "
                  "emergency oxygen tanks." << endl;
               numLost = numPersonnel/4;
               numSurvived = numPersonnel - numLost;
               cout << numSurvived << " people survived. " << numLost
                  << " people were lost." << endl;
               break;
            default:
               cout << "You have been eaten by a Grue." << endl;
         }
         break;
      case 2:
         //exit game
         cout << "We hope to see you again!" << endl;
         break;
      default:
         cout << "Invalid choice." << endl;
   }
   return 0;
}
