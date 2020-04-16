#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
//Brian Goodson
//3/14/19
//Program to run 1,000,000 games of craps and print the chances of winning as well as the wins and losses for first roll, second roll,.. etc.
//Used arrays

using namespace std;
//roll die method
int rollDice();
//method to return results
void getResults(int a[], string s);



//main method
int main()
{
  string wordWin = "WON";
  string wordLost = "LOST";
  int gamesBeenWon = 0;
  int gamesBeenLost = 0;
  int totalRolls = 0;
  int gamesWon[1000000];
  int gamesLost[1000000];
  //enumerate these cases
  enum class Status{CONTINUE,WON,LOST};

  srand(static_cast<unsigned int>(time(0)));


  for(int i = 0; i <= 1000000; i++){
    int rollCount = 0;
    int myPoint = 0;
    Status gameStatus;
    int sumOfDice = rollDice();
    rollCount++;

    //switch statement to handle the status of game
    switch(sumOfDice){
      case 7:
      case 11:
        gameStatus = Status::WON;
        break;
      case 2:
      case 3:
      case 12:
        gameStatus = Status::LOST;
        break;
      default:
        gameStatus = Status::CONTINUE;
        myPoint = sumOfDice;
        cout<< "Point is "<< myPoint << endl;
        break;
    }

    while(Status::CONTINUE == gameStatus){
      sumOfDice = rollDice();
      rollCount++;

      if(sumOfDice == myPoint){
        gameStatus = Status::WON;
      }
      else{
        if(sumOfDice == 7){
          gameStatus = Status::LOST;
        }
      }
    }

    //final if statement estabishes the result of the game
    if(Status::WON == gameStatus){
      cout<<"Player wins" << endl;
      gamesWon[i] += rollCount;
      gamesBeenWon++;
      totalRolls++;
    }
    else{
      cout<<"Player loses" << endl;
      gamesLost[i] += rollCount;
      gamesBeenLost++;
      totalRolls++;
    }
  }

  //doubles initiated to calculate chances of winning and losing.
  double averageWins = (gamesBeenWon/1000000.0);
  double averageLosses = (gamesBeenLost/1000000.0);
  double averageLength = (totalRolls/1000000.0);
  cout<<averageLength<<" is the average amount of rolls per game."<<endl;
  cout<<averageWins<<" is the percentage number of wins."<<endl;
  cout<<averageLosses<<" is the percentage number of Losses."<<endl;

  getResults(gamesWon,wordWin);
  getResults(gamesLost,wordLost);

}
//method to print some of the calculations
void getResults(int a[], string s){
  double length;
  int first = 0;
  int second = 0;
  int third = 0;
  int fourth = 0;
  int fifth = 0;
  int sixth = 0;
  int seventh = 0;
  int eighth = 0;
  int ninth = 0;
  int tenth = 0;
  int eleventh = 0;
  int twelfth = 0;
  int thirteenth = 0;
  int fourteenth = 0;
  int fifteenth = 0;
  int sixteenth = 0;
  int seventeenth = 0;
  int eighteenth = 0;
  int nineteenth = 0;
  int twentieth = 0;
  int Over20 = 0;
  for(int i = 0; i < 1000000;i++){
    if(a[i] > 20){
      Over20++;
    }
    if(a[i]==1){
      first++;
    }
    if(a[i]==2){
      second++;
    }
    if(a[i]==3){
      third++;
    }
    if(a[i]==4){
      fourth++;
    }
    if(a[i]==5){
      fifth++;
    }
    if(a[i]==6){
      sixth++;
    }
    if(a[i]==7){
      seventh++;
    }
    if(a[i]==8){
      eighth++;
    }
    if(a[i]==9){
      ninth++;
    }
    if(a[i]==10){
      tenth++;
    }
    if(a[i]==11){
      eleventh;
    }
    if(a[i]==12){
      twelfth++;
    }
    if(a[i]==13){
      thirteenth++;
    }
    if(a[i]==14){
      fourteenth++;
    }
    if(a[i]==15){
      fifteenth++;
    }
    if(a[i]==16){
      sixteenth++;
    }
    if(a[i]==17){
      seventeenth++;
    }
    if(a[i]==18){
      eighteenth++;
    }
    if(a[i]==19){
      nineteenth++;
    }
    if(a[i]==20){
      twentieth++;
    }
  }
  cout<<"Player "<<s<<" "<<first<<" games in one roll."<<endl;
  cout<<"Player "<<s<<" "<<second<<" games in two rolls."<<endl;
  cout<<"Player "<<s<<" "<<third<<" games in three rolls."<<endl;
  cout<<"Player "<<s<<" "<<fourth<<" games in four rolls."<<endl;
  cout<<"Player "<<s<<" "<<fifth<<" games in five rolls."<<endl;
  cout<<"Player "<<s<<" "<<sixth<<" games in six rolls."<<endl;
  cout<<"Player "<<s<<" "<<seventh<<" games in seven rolls."<<endl;
  cout<<"Player "<<s<<" "<<eighth<<" games in eight rolls."<<endl;
  cout<<"Player "<<s<<" "<<ninth<<" games in nine rolls."<<endl;
  cout<<"Player "<<s<<" "<<tenth<<" games in ten rolls."<<endl;
  cout<<"Player "<<s<<" "<<eleventh<<" games in eleven rolls."<<endl;
  cout<<"Player "<<s<<" "<<twelfth<<" games in twelve rolls."<<endl;
  cout<<"Player "<<s<<" "<<thirteenth<<" games in thirteen rolls."<<endl;
  cout<<"Player "<<s<<" "<<fourteenth<<" games in fourteen rolls."<<endl;
  cout<<"Player "<<s<<" "<<fifteenth<<" games in fifteen rolls."<<endl;
  cout<<"Player "<<s<<" "<<sixteenth<<" games in sixteen rolls."<<endl;
  cout<<"Player "<<s<<" "<<seventeenth<<" games in seventeen rolls."<<endl;
  cout<<"Player "<<s<<" "<<eighteenth<<" games in eighteen rolls."<<endl;
  cout<<"Player "<<s<<" "<<nineteenth<<" gamse in nineteen rolls."<<endl;
  cout<<"Player "<<s<<" "<<twentieth<<" games in twenty rolls."<<endl;
}


// dice rolling function
int rollDice()
{
   int die1 = (1 + rand() % 6);
   int die2 = (1 + rand() % 6);
   int sum = (die1 + die2);//sum of die values

   cout<<"Player rolled "<<die1<<" + "<<die2<<" = "<<sum<<endl;
   return sum;

} // end function rollDice
