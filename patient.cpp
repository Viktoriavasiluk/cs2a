//
//  main.cpp
//  Patient
//
//  Created by Andrew Tran on 11/11/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Patient {
private:
   string name;
   int id;
   double temperature;
public:
   static const int MIN_LEN = 2;
   static const int MAX_LEN = 40;
   static const int MIN_ID = 0;
   static const int MAX_ID = 9999;
   static const double MIN_TEMP;
   static const double MAX_TEMP;
   static const double ALARM_TEMP;
   static const string DEFAULT_NAME;
   static const int DEFAULT_ID = 0;
   static const double DEFAULT_TEMP;

   Patient();
   Patient(string name, int id, double temp);

   bool setName(string name);
   bool setID(int id);
   bool setTemp(double temp);
   void display();
};

const double Patient::MIN_TEMP = 88.0;
const double Patient::MAX_TEMP = 111.0;
const double Patient::ALARM_TEMP = 103.5;
const string Patient::DEFAULT_NAME = "N/A";
const double Patient::DEFAULT_TEMP = 98.6;

string getPatientName();
int getPatientID();
double getPatientTemp();

int main() {
/*
   Patient a;
   a.setName("Fred");
   a.setID(1234);
   a.setTemp(100.3);

   Patient b("Janis", 5555, 103.7);
*/
   Patient a;
   a.setName(getPatientName());
   a.setID(getPatientID());
   a.setTemp(getPatientTemp());
   a.display();
   //b.display();i
   return 0;
}

string getPatientName() {
   string userInput;
   cout << "What is the patient's name? ";
   getline(cin, userInput);
   return userInput;
}
int getPatientID() {
   int id;
   string userInput;
   cout << "What is the patient's ID? ";
   getline(cin , userInput);
   istringstream(userInput) >> id;
   return id;
}
double getPatientTemp() {
   double temp;
   string userInput;
   cout << "What is the patient's temperature? ";
   getline(cin, userInput);
   istringstream(userInput) >> temp;
   return temp;
}

Patient::Patient() {
   name = DEFAULT_NAME;
   id = DEFAULT_ID;
   temperature = DEFAULT_TEMP;
}
Patient::Patient(string name, int id, double temp) {
   if(!setName(name)) {
      setName(DEFAULT_NAME);
   }
   if(!setID(id)) {
      setID(DEFAULT_ID);
   }
   if(!setTemp(temp)) {
      setTemp(DEFAULT_TEMP);
   }
}
void Patient::display() {
   cout << "Name: " << name << endl;
   cout << "ID: " << id << endl;
   cout << "Temperature: " << temperature << endl;
   if(temperature > ALARM_TEMP) {
      cout << "\n*** URGENT: Attend immediately! ***" << endl;
   }
}
bool Patient::setName(string name) {
   if(name.length() < MIN_LEN || name.length() > MAX_LEN) {
      return false;
   }
   this->name = name;
   return true;
}
bool Patient::setID(int id) {
   if(id < MIN_ID || id > MAX_ID) {
      return false;
   }
   this->id = id;
   return true;
}
bool Patient::setTemp(double temp) {
   if(temp < MIN_TEMP || temp > MAX_TEMP) {
      return false;
   }
   this->temperature= temp;
   return true;
}
