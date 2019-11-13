//
//  main.cpp
//  Username
//
//  Created by Andrew Tran on 11/11/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Username {
private:
   string first;
   string last;
public:
   Username();
   void getName();
   void displayUsernames();
};

int main() {
   Username u;
   u.getName();
   u.displayUsernames();
   return 0;
}

Username::Username() {
   first = "";
   last = "";
}
void Username::getName() {
   cout << "Enter your first name: ";
   cin >> first;
   cout << "Enter your last name: ";
   cin >> last;
}
void Username::displayUsernames() {
   cout << "These usernames are available for use:" << endl;
   cout << first << last << endl;
   cout << last << first << endl;
   cout << first << "_" << last << endl;
   cout << last << "-" << first << endl;
}
