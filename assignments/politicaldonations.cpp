//
//  main.cpp
//  PoliticalDonations
//
//  Created by Andrew Tran on 10/29/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

//returns the refund amount for a specific donation
double getRefund(double donation) {
   double refund = 0;
   if(donation > 2700) {
      refund = donation-2700;
   }
   return refund;
}

//gathers all individual donations and displays the refund + total
double getDonation() {
   double total = 0;
   double donation = 0;
   double refund = 0;
   cout.setf(ios::fixed);
   cout.precision(2);
   do {
      cout << "How much would you like to donate? (0 to quit)\n" << "$";
      cin >> donation;
      refund = getRefund(donation);
      if(refund > 0) {
         cout << "Refund amount: $" << refund << endl;
         total += 2700;
      } else {
         total += donation;
      }
   } while(donation > 0);
   return total;
}

//displays total of all donations
int main() {
   double total = getDonation();
   cout << "Total donations: $" << total << endl;
   return 0;
}
