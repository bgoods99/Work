#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
 double scores[7];
 int posMinScore, posMaxScore;
 double MinimumScore = 11.0, MaximumScore = 0.0;
 int i;
 double difficulty;
 double finalscore = 0.0;
 //while loop to input difficulty
 while ((difficulty <= 1.2) || (difficulty >= 3.8)) {
  cout << "Degree of difficulty (1.2 to 3.8) ";
  cin >> difficulty;
  }
//for loop to establish the array
 for (i=0; i < 7; ++i) {
  scores[i] = 11.0;
  while ((scores[i] < 0.0) || (scores[i] > 10.0)) {
   cout << "Score " << i + 1 << " (0.0 to 10.0) ";
   cin >> scores[i];
   }
  //if statements to establish min and max scores and positions
  if (scores[i] < MinimumScore) {MinimumScore = scores[i]; posMinScore = i;}
  if (scores[i] > MaximumScore) {MaximumScore = scores[i]; posMaxScore = i;}
  }
 if (posMinScore==posMaxScore) {posMinScore=0; posMaxScore=6;}
 for (i=0; i < 7; ++i) {
   //if statement to make sure the min and max are not calculated in the sum
  if (!((i == posMinScore) || (i == posMaxScore))) finalscore += scores[i];
  }
 finalscore *= difficulty * 0.6;
 cout << "The diver's final score is " << finalscore << endl;
 return 0;
 }
