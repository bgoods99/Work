#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;
//Brian Goodson
//This Program computes the amount of people added into a room until a pair shares the same bday.

int birthdayCoincidenceAverage(int numberOfTrials) {
  //random time to set values correctly
  srand(time(0));
  int storedValues[366];
  int averagePeopleEntered, peopleEntered = 0;
  //for loops to iterate through arrays
  for (int i = 0; i < numberOfTrials; i++) {
    for (int j = 0; j < 366; j++) {
      storedValues[j] = (1 + rand() % 365);
      for (int k = 0; k < j; k++) {
        if (storedValues[j] == storedValues[k]) {
          peopleEntered = peopleEntered + (j - 1);
          k = 999;
          j = 999;
        }
      }
    }
  }
  averagePeopleEntered = peopleEntered / numberOfTrials;
  return averagePeopleEntered;
}

int main() {
  int numberOfTrials;
  cout<<"How many times do you want to run the program?\n";
  cin>>numberOfTrials;
  cout<<birthdayCoincidenceAverage(numberOfTrials);
}
