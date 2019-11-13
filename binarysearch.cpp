//
//  main.cpp
//  BinarySearch
//
//  Created by Andrew Tran on 12/8/18.
//  Copyright © 2018 Andrew Tran. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// class Student prototype -----------------------
class Student {
private:
   string lastName;
   int totalPoints;

public:
   static const string DEFAULT_NAME;
   static const int DEFAULT_POINTS = 0;
   static const int MAX_POINTS = 1000;

public:
   Student(string lst, int pts);

   // accessors and mutators
   string getLastName() { return lastName; }
   int getTotalPoints() { return totalPoints; }

   bool setLastName(string last);
   bool setPoints(int pts);

   static int compareTwoStudents(Student firstStud, Student secondStud);
   string toString();

private:
   static bool validString( string testStr );
   static bool validPoints( int testPoints );
};  // end of class Student prototype --------------

// class StudentArrayUtilities prototype -----------------------
class StudentArrayUtilities {
public:
   static void printArray(string title, Student data[], int arraySize);
   static void arraySort(Student array[], int arraySize);
   static int arraySearch( Student array[], string keyLast, int arraySize );
   static int binarySearch(Student array[], string keyLast,
                           int firstIndex, int lastIndex);

private:
   static bool floatLargestToTop(Student data[], int top);
   static void mySwap(Student &a, Student &b);
};

// static initializations that can't be done in-line
const string Student::DEFAULT_NAME = "zz-error";

int main() {
   string last;
   int found;
   Student myClass[] = { Student("smith", 95),
      Student("bauer", 123),
      Student("jacobs", 195),  Student("renquist", 148),
      Student("3ackson", 108),  Student("perry", 225),
      Student("loceff", 44),  Student("stollings", 452),
      Student("charters", 295),  Student("cassar", 321)
   };
   int arraySize = sizeof(myClass) / sizeof(myClass[0]);

   StudentArrayUtilities::arraySort(myClass, arraySize);
   StudentArrayUtilities::printArray("Sorted array to be searched: ",
                                     myClass, arraySize);

   last = "stollings";
   found = StudentArrayUtilities::binarySearch(myClass, last, 0, arraySize - 1 );
   if(found >= 0)
      cout <<  last + " IS in list at position " << found;
   else
      cout << last + " is NOT in list.";
   cout << endl;

   last = "jacobs";
   found = StudentArrayUtilities::binarySearch(myClass, last, 0, arraySize - 1 );
   if (found >= 0)
      cout << last + " IS in list at position " << found;
   else
      cout << last + " is NOT in list.";
   cout << endl;

   last = "gunderman";
   found = StudentArrayUtilities::binarySearch(myClass, last, 0, arraySize - 1 );
   if (found >= 0)
      cout << last + " IS in list at position " << found;
   else
      cout << last + " is NOT in list.";
   cout << endl << endl;
}

// beginning of Student method definitions -------------

// constructor requires parameters - no default supplied
Student::Student(string last, int points) {
   if(!setLastName(last))
      lastName = DEFAULT_NAME;
   if(!setPoints(points))
      totalPoints = DEFAULT_POINTS;
}

bool Student::setLastName(string last) {
   if(!validString(last))
      return false;
   lastName = last;
   return true;
}

bool Student::setPoints(int pts) {
   if (!validPoints(pts))
      return false;
   totalPoints = pts;
   return true;
}

// could be an instance method and, if so, would take one parameter
int Student::compareTwoStudents(Student firstStud, Student secondStud) {
   int result;

   // this particular version based on last name only (case insensitive)
   result = firstStud.lastName.compare(secondStud.lastName);

   return result;
}

string Student::toString() {
   string resultString;
   ostringstream cnvrtLast, cnvrtPoints;

   cnvrtLast << lastName;
   cnvrtPoints << totalPoints;

   resultString = " " + cnvrtLast.str() + " points: " + cnvrtPoints.str() + "\n";
   return resultString;
}

bool Student::validString(string testStr) {
   if(testStr.length() > 0 && isalpha(testStr[0]))
      return true;
   return false;
}

bool Student::validPoints(int testPoints) {
   if(testPoints >= 0 && testPoints <= MAX_POINTS)
      return true;
   return false;
}
// end of Student method definitions  --------------

// beginning of StudentArrayUtilities method definitions -------------

// print the array with string as a title for the message box
// this is somewhat controversial - we may or may not want an I/O
// methods in this class.  we'll accept it today
void StudentArrayUtilities::printArray(string title, Student data[], int arraySize) {
   string output = "";

   cout << title << endl;

   // build the output string from the individual Students:
   for(int k = 0; k < arraySize; k++)
      output += " " + data[k].toString();

   cout << output << endl;
}

void StudentArrayUtilities::arraySort(Student array[], int arraySize) {
   for(int k = 0; k < arraySize; k++)
      // compare with method def to see where inner loop stops
      if(!floatLargestToTop(array, arraySize - 1 - k))
         return;
}

// returns true if a modification was made to the array
bool StudentArrayUtilities::floatLargestToTop(Student data[], int top) {
   bool changed = false;

   // compare with client call to see where the loop stops
   for(int k =0; k < top; k++)
      if(Student::compareTwoStudents(data[k], data[k + 1]) > 0 ) {
         mySwap(data[k], data[k + 1]);
         changed = true;
      }
   return changed;
}

void StudentArrayUtilities::mySwap(Student &a, Student &b) {
   Student temp("", 0);

   temp = a;
   a = b;
   b = temp;
}

int StudentArrayUtilities::arraySearch(Student array[], string keyLast,
                                       int arraySize) {
   for(int k = 0; k < arraySize; k++)
      if(array[k].getLastName() == keyLast)
         return k;  // found match, return index

   return -1;   // fell through - no match
}

int StudentArrayUtilities::binarySearch(Student array[], string keyLast,
                                        int firstIndex, int lastIndex) {
   int middleIndex, result;

   if(firstIndex > lastIndex)
      return -1;
   middleIndex = (firstIndex + lastIndex) / 2;
   result = keyLast.compare(array[middleIndex].getLastName());

   if(result == 0)
      return middleIndex;   //found him!
   else if(result < 0)
      return binarySearch(array, keyLast, firstIndex, middleIndex-1);
   else
      return binarySearch(array, keyLast, middleIndex+1, lastIndex);
}

// end of StudentArrayUtilities method definitions  --------------
