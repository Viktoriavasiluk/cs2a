//
//  main.cpp
//  Galaxy
//
//  Created by Andrew Tran on 11/11/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Galaxy {
private:
   string name;
   double magnitude;
public:
   //static constants
   static const double DEFAULT_MAG;
   static const string DEFAULT_NAME;
   static const double MIN_MAG;
   static const double MAX_MAG;
   static const int MIN_STR_LEN;

   //default constructor
   Galaxy() {
      name = DEFAULT_NAME;
      magnitude = DEFAULT_MAG;
   }

   //2-parameter constructor
   Galaxy(string name, double mag) {
      if(!setName(name)) {
         this->name = DEFAULT_NAME;
      }
      if(!setMagnitude(mag)) {
         this->magnitude = DEFAULT_MAG;
      }
   }

   //mutators and accessors
   bool setMagnitude(double mag);
   bool setName(string name);
   string getName();
   double getMagnitude();
};

//initialize static members of Galaxy
const double Galaxy::DEFAULT_MAG = 0.0;
const string Galaxy::DEFAULT_NAME = "undefined";
const double Galaxy::MIN_MAG = 5;
const double Galaxy::MAX_MAG = 15;
const int Galaxy::MIN_STR_LEN = 2;

int main() {
   Galaxy gal1;

   gal1.setName("X");
   gal1.setMagnitude(100);
   //gal2.setName("Andromeda");
   //gal2.setMagnitude(5);
   Galaxy gal2("Andromeda", 5);

   cout << gal1.getName() << "'s magnitude: " << gal1.getMagnitude() << endl;
   cout << gal2.getName() << "'s magnitude: " << gal2.getMagnitude() << endl;

   return 0;
}

//Galaxy member function definitions
bool Galaxy::setMagnitude(double mag) {
   if(mag < MIN_MAG || mag > MAX_MAG) {
      return false;
   }
   magnitude = mag;
   return true;
}
bool Galaxy::setName(string name) {
   if(name.length() < MIN_STR_LEN) {
      return false;
   }
   this->name = name;
   return true;
}
string Galaxy::getName() {
   return name;
}
double Galaxy::getMagnitude() {
   return magnitude;
}
