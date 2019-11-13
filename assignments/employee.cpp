//
//  main.cpp
//  Employee
//
//  Created by Andrew Tran on 12/8/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

#define MAX_SIZE 20

class Employee {
private:
   string ssn;
   string name;
   double payRate;

public:
   static const int MIN_LEN = 2;
   static const int MAX_LEN = 40;
   static const string DEFAULT_SSN;
   static const string DEFAULT_NAME;
   static const double DEFAULT_RATE;

   Employee();
   Employee(string ssn, string name, double payRate);

   string getSSN() { return ssn; }
   string getName() { return name; }
   double getPayRate() { return payRate; }
   bool setSSN(string ssn);
   bool setName(string name);
   bool setPayRate(double payRate);

private:
   bool validSSN(string ssn);
};

class Company {
private:
   Employee employees[MAX_SIZE];
   short arraySize;

public:
   static const double RAISE_AMT;

   Company();

   void hire(string ssn, string name, double payRate);
   void report(string title);
   void raise();

private:
   void update(Employee &a, string ssn, string name, double payRate);
   void sortArray(Employee data[]);
   bool alphabetize(Employee data[], int end);
   void swap(Employee &a, Employee &b);
   void printArray(string title, Employee data[]);
   bool isDefault(Employee a);
};

//initialize const variables
const string Employee::DEFAULT_SSN = "000000000";
const string Employee::DEFAULT_NAME = "unknown";
const double Employee::DEFAULT_RATE = 7.25; //federal minimum wage
const double Company::RAISE_AMT = 1.1;

int main() {
   Company c;
   //fred, jack, carrie, abe, trevor, fred, fred, pamela, rodney, john, andrew
   c.hire("123456789", "Fred", 100000);
   c.hire("234567890", "Jack", 200000);
   c.hire("345678901", "Carrie", 300000);
   c.hire("456789012", "Abe", 400000);
   c.hire("567890123", "Trevor", 500000);
   c.hire("678901234", "Fred", 600000);
   c.hire("789012345", "Fred", 700000);
   c.hire("890123456", "Pamela", 800000);
   c.hire("901234567", "Rodney", 900000);
   c.hire("012345678", "John", 7.25);
   c.hire("123456789", "Andrew", 9999999);
   c.hire("000000000", "TEST", -1);

   c.report("Before raise: ");
   c.raise();
   c.report("After raise: ");

   return 0;
}

//Employee constructors
Employee::Employee() {
   ssn = DEFAULT_SSN;
   name = DEFAULT_NAME;
   payRate = DEFAULT_RATE;
}
Employee::Employee(string ssn, string name, double payRate) {
   if(!setSSN(ssn)) {
      ssn = DEFAULT_SSN;
   }
   if(!setName(name)) {
      name = DEFAULT_NAME;
   }
   if(!setPayRate(payRate)) {
      payRate = DEFAULT_RATE;
   }
}

//Employee mutators
bool Employee::setSSN(string ssn) {
   if(!validSSN(ssn)) {
      return false;
   }
   this->ssn = ssn;
   return true;
}
bool Employee::setName(string name) {
   if(name.length() < MIN_LEN || name.length() > MAX_LEN || !isalpha(name[0])) {
      return false;
   }
   this->name = name;
   return true;
}
bool Employee::setPayRate(double payRate) {
   if(payRate < DEFAULT_RATE) {
      return false;
   }
   this-> payRate = payRate;
   return true;
}

//Employee helper method
bool Employee::validSSN(string ssn) {
   if(ssn.length() == DEFAULT_SSN.length()) {
      for(int i = 0; i < ssn.length(); i++) {
         if(!isdigit(ssn[i])) {
            return false;
         }
      }
      return true;
   }
   return false;
}

//Company constructor
Company::Company() {
   arraySize = sizeof(employees)/sizeof(employees[0]);
   for(int i = 0; i < arraySize; i++) {
      employees[i] = Employee();
   }
}

//Company public methods
void Company::hire(string ssn, string name, double payRate) {
   Employee newEmployee(ssn, name, payRate);
   for(int i = 0; i < arraySize; i++) {
      if(employees[i].getSSN().compare(ssn) == 0 || isDefault(employees[i])) {
         update(employees[i], ssn, name, payRate);
         return;
      }
   }
}
void Company::report(string title) {
   sortArray(employees);
   printArray(title, employees);
}
void Company::raise() {
   for(int i = 0; i < arraySize; i++) {
      if(!isDefault(employees[i])) {
         double currentRate = employees[i].getPayRate();
         employees[i].setPayRate(currentRate * RAISE_AMT);
      }
   }
}

//Company helper methods
void Company::update(Employee &a, string ssn, string name, double payRate) {
   a.setSSN(ssn);
   a.setName(name);
   a.setPayRate(payRate);
}
void Company::sortArray(Employee data[]) {
   for(int i = 0; i < arraySize; i++) {
      if(!alphabetize(data, arraySize-1-i)) {
         return;
      }
   }
}
bool Company::alphabetize(Employee data[], int end) {
   bool change = false;
   for(int i = 0; i < end; i++) {
      if(data[i].getName().compare(data[i+1].getName()) > 0) {
         swap(data[i], data[i+1]);
         change = true;
      }
   }
   return change;
}
void Company::swap(Employee &a, Employee &b) {
   Employee temp("", "", 0);
   temp = a;
   a = b;
   b = temp;
}
void Company::printArray(string title, Employee data[]) {
   cout << title << endl;
   cout.setf(ios::fixed);
   cout.precision(2);
   for(int i = 0; i < arraySize; i++) {
      if(!isDefault(data[i])) {
         cout << "Employee #" << i+1 << "\nName: " << data[i].getName()
         << "\nPay rate: $" << data[i].getPayRate() << "\nSSN: "
         << data[i].getSSN() << endl << endl;
      }
   }
   cout << endl;
}
bool Company::isDefault(Employee a) {
   return(a.getSSN().compare(Employee::DEFAULT_SSN) == 0
      && a.getName().compare(Employee::DEFAULT_NAME) == 0
      && a.getPayRate() == Employee::DEFAULT_RATE);
}
