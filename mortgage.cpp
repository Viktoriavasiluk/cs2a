//
//  main.cpp
//  MortgageCalculator
//
//  Created by Andrew Tran on 11/25/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

//global variables shared by more than one method
//will change -- omit line below
//double dblPrincipal, dblRate, dblYears;

class MortgageData {
private:
   double dblPrincipal;
   double dblRate;
   double dblYears;

public:
   //class constants
   static const double MIN_LOAN;
   static const double MAX_LOAN;
   static const double MIN_RATE;
   static const double MAX_RATE;
   static const double MIN_YRS;
   static const double MAX_YRS;

   //constructors
   MortgageData();
   MortgageData(double principal, double rate, double yr);

   //methods
   bool setPrincipal(double principal);
   double getPrincipal();
   bool setRate(double rate);
   double getRate();
   bool setYears(double yrs);
   double getYears();
};

//static member initialization
double const MortgageData::MIN_LOAN = 1.;
double const MortgageData::MAX_LOAN = 100000000.;
double const MortgageData::MIN_RATE = 0.00001;
double const MortgageData::MAX_RATE = 25.;
double const MortgageData::MIN_YRS = 1.;
double const MortgageData::MAX_YRS = 100.;

//ordinary method prototypes
void statePurpose();
void getInput(MortgageData &loan);
double computeMonthlyPayment(MortgageData loan);
void reportResults(double result);

//define the main method - - - - - - - - - -
int main() {
   double answer;
   MortgageData loan;

   statePurpose();
   getInput(loan);
   answer = computeMonthlyPayment(loan);
   reportResults(answer);

   return 0;
}

//give an overview to user
void statePurpose() {
   string instructions;
   instructions = "\nThe following program will calculate the monthly payment "
      "required for a loan of D dollars over a period of Y years at an "
      "annual interest rate of R%.\n";
   cout << instructions;
}

/*
void getInput() {
   string prompt;

   //get principal
   prompt = "\nEnter the amount of the loan. (Only use numbers, please, no "
      "commas or characters like '$')\nYour loan amount: ";
   cout << prompt;
   cin >> dblPrincipal;

   //get interest
   prompt = "\nNow enter the interest rate. (Enter the quoted rate without "
      "the % symbol)\nYour annual interest rate: ";
   cout << prompt;
   cin >> dblRate;

   //get length of loan
   prompt = "\nEnter the term of the loan (in years): ";
   cout << prompt;
   cin >> dblYears;
}
*/
//get input
void getInput(MortgageData &userData) {
   double dblResponse;
   cout.setf(ios::fixed);
   cout.precision(2);

   //get principal
   do {
      cout << "\nEnter the amount of the loan. (Only use numbers, please, no "
         "commas or characters like '$')\nAmount must be between $"
         << MortgageData::MIN_LOAN << " and $" << MortgageData::MAX_LOAN
         << ".\nYour loan amount: ";
      cin >> dblResponse;
   } while(!userData.setPrincipal(dblResponse));


   //get interest
   do {
      cout << "\nNow enter the interest rate. (Enter the quoted rate without "
         "the % symbol)\nRate must be between " << MortgageData::MIN_RATE
         << "% and " << MortgageData::MAX_RATE << "%.\nYour annual interest rate: ";
      cin >> dblResponse;
   } while(!userData.setRate(dblResponse));


   //get length of loan
   do {
      cout << "\nEnter the term of the loan (in years).\nTerm must be between "
         << MortgageData::MIN_YRS << " years and " << MortgageData::MAX_YRS
         << " years.\nYour term: ";
      cin >> dblResponse;
   } while(!userData.setRate(dblResponse));
}

/*
double computeMonthlyPayment() {
   double dblTemp, dblPmt, dblMort, dblMonths;

   //convert years to months
   dblMonths = dblYears * 12;

   //convert rate to a decimal and months
   dblMort = dblRate / (100 * 12);

   //use formula to get result
   dblTemp = pow(1 + dblMort, dblMonths);
   dblPmt = dblPrincipal * dblMort * dblTemp / (dblTemp - 1);

   return dblPmt;
}
 */
//compute and return answer
double computeMonthlyPayment(MortgageData loan) {
   //only local variables needed in this method
   double dblTemp, dblPmt, dblMonths, dblMort;

   //convert years to months
   dblMonths = loan.getYears() * 12;

   //convert rate to a decimal and months
   dblMort = loan.getRate() / (100 * 12);

   //use formula to get result
   dblTemp = pow(1 + dblMort, dblMonths);
   dblPmt = loan.getPrincipal() * dblMort * dblTemp / (dblTemp - 1);

   return dblPmt;
}

//display results and sign off
void reportResults(double result) {
   string signoff;
   signoff = "\nThanks for using Andrew's Mortgage Calculator.\n"
      "We hope to see you again!\n\n";

   cout.setf(ios::fixed);
   cout.precision(2);
   cout << "Your monthly payment: " << result << endl;
   cout << signoff;
}

//initialize constructors
MortgageData::MortgageData() {
   //default values (best done via mutators if they exist)
   dblPrincipal = MIN_LOAN;
   dblRate = MIN_RATE;
   dblYears = MIN_YRS;
}
MortgageData::MortgageData(double principal, double rate, double yr) {
   if(!setPrincipal(principal)) {
      dblPrincipal = MIN_LOAN;
   }
   if(!setRate(rate)) {
      dblRate = MIN_RATE;
   }
   if(!setYears(yr)) {
      dblYears = MIN_YRS;
   }
}

//mutators
bool MortgageData::setPrincipal(double principal) {
   if(principal < MIN_LOAN || principal > MAX_LOAN) {
      return false;
   }
   dblPrincipal = principal;
   return true;
}
bool MortgageData::setRate(double rate) {
   if(rate < MIN_RATE || rate > MAX_RATE) {
      return false;
   }
   dblRate = rate;
   return true;
}
bool MortgageData::setYears(double yrs) {
   if(yrs < MIN_YRS || yrs > MAX_YRS) {
      return false;
   }
   dblYears = yrs;
   return true;
}

//accessors
double MortgageData::getPrincipal() {
   return dblPrincipal;
}
double MortgageData::getRate() {
   return dblRate;
}
double MortgageData::getYears() {
   return dblYears;
}
