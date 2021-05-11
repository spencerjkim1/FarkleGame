#include "mbed.h"
#include "MMA8452.h"
 #include "uLCD_4DGL.h"
 #include "PinDetect.h"
 #include "Speaker.h"
 //#include "farkle.cpp"
// #include "farkle.hpp"
 
uLCD_4DGL uLCD(p9, p10, p11); // serial tx, serial rx, reset pin; 
Serial pc(USBTX,USBRX); //not used in this program
Speaker mySpeaker(p25);
PinDetect pb1(p21);
PinDetect pb2(p22);



class FarkleGame{
public:
    FarkleGame();
    void rollDice();
    void displayDice();

private:
    int turnScore;
    int rollScore;
    int calcRoll();
    int pairCounter;
    int tripCounter;
    int numDice;
    int arrDice[6];
    int sortedArrDice[7];
    bool shake;
    bool endTurn;
    bool diceChange;
    //bool continue;
};


void FarkleGame::rollDice(){
    numDice=6;
    for (int i=0; i<numDice; i++){
        int dice=rand()% 6 +1;
        arrDice[i]=dice; 
    }

}
void FarkleGame::displayDice(){
    //CODE to display arrDice
    //if (shake==True){
    for (int i=0; i<numDice; i++){
        if (i==0){
            if (arrDice[i]==1){
            //print one
                uLCD.filled_circle(27,27,3,WHITE);
            }
            if (arrDice[i]==2){
             //print two
                uLCD.filled_circle(15,15,3,WHITE);
                uLCD.filled_circle(40,40,3,WHITE);
            }
            if (arrDice[i]==3){
                uLCD.filled_circle(15,15,3,WHITE);
                uLCD.filled_circle(40,40,3,WHITE);
                uLCD.filled_circle(27,27,3,WHITE);
            }
            if (arrDice[i]==4){
                uLCD.filled_circle(15,15,3,WHITE);
                uLCD.filled_circle(40,15,3,WHITE);
                uLCD.filled_circle(15,40,3,WHITE);
                uLCD.filled_circle(40,40,3,WHITE);
            }
            if (arrDice[i]==5){
                uLCD.filled_circle(15,15,3,WHITE);
                uLCD.filled_circle(40,15,3,WHITE);
                uLCD.filled_circle(15,40,3,WHITE);
                uLCD.filled_circle(40,40,3,WHITE);
                uLCD.filled_circle(27,27,3,WHITE);
            }
            if (arrDice[i]==6){
                uLCD.filled_circle(15,15,3,WHITE);
                uLCD.filled_circle(40,15,3,WHITE);
                uLCD.filled_circle(15,40,3,WHITE);
                uLCD.filled_circle(40,40,3,WHITE);
                uLCD.filled_circle(15,27,3,WHITE);
                uLCD.filled_circle(40,27,3,WHITE);
            }
        }
        if (i==1){
            if (arrDice[i]==1){
            uLCD.filled_circle(27,27+35,3,WHITE);
            }
            if (arrDice[i]==2){
             uLCD.filled_circle(15,15+35,3,WHITE);
            uLCD.filled_circle(40,40+35,3,WHITE);
            }
            if (arrDice[i]==3){
            uLCD.filled_circle(15,15+35,3,WHITE);
                uLCD.filled_circle(40,40+35,3,WHITE);
                uLCD.filled_circle(27,27+35,3,WHITE);
            }
            if (arrDice[i]==4){
                uLCD.filled_circle(15,15,3,WHITE);
                uLCD.filled_circle(40,15+35,3,WHITE);
                uLCD.filled_circle(15,40+35,3,WHITE);
                uLCD.filled_circle(40,40+35,3,WHITE);
            }
            if (arrDice[i]==5){
                uLCD.filled_circle(15,15+35,3,WHITE);
                uLCD.filled_circle(40,15+35,3,WHITE);
                uLCD.filled_circle(15,40+35,3,WHITE);
                uLCD.filled_circle(40,40+35,3,WHITE);
                uLCD.filled_circle(27,27+35,3,WHITE);
            }
            if (arrDice[i]==6){
                uLCD.filled_circle(15,15+35,3,WHITE);
                uLCD.filled_circle(40,15+35,3,WHITE);
                uLCD.filled_circle(15,40+35,3,WHITE);
                uLCD.filled_circle(40,40+35,3,WHITE);
                uLCD.filled_circle(15,27+35,3,WHITE);
                uLCD.filled_circle(40,27+35,3,WHITE);
            }
        }
        if (i==2){
            if (arrDice[i]==1){
                uLCD.filled_circle(27,27+2*35,3,WHITE);
            }
            if (arrDice[i]==2){
                uLCD.filled_circle(15,15+2*35,3,WHITE);
                uLCD.filled_circle(40,40+2*35,3,WHITE);
            }
            if (arrDice[i]==3){
                uLCD.filled_circle(15,15+2*35,3,WHITE);
                uLCD.filled_circle(40,40+2*35,3,WHITE);
                uLCD.filled_circle(27,27+2*35,3,WHITE);
            }
            if (arrDice[i]==4){
                uLCD.filled_circle(15,15,3,WHITE);
                uLCD.filled_circle(40,15+2*35,3,WHITE);
                uLCD.filled_circle(15,40+2*35,3,WHITE);
                uLCD.filled_circle(40,40+2*35,3,WHITE);
            }
            if (arrDice[i]==5){
            uLCD.filled_circle(15,15+35,3,WHITE);
                uLCD.filled_circle(40,15+2*35,3,WHITE);
                uLCD.filled_circle(15,40+2*35,3,WHITE);
                uLCD.filled_circle(40,40+2*35,3,WHITE);
                uLCD.filled_circle(27,27+2*35,3,WHITE);
            }
            if (arrDice[i]==6){
                uLCD.filled_circle(15,15+2*35,3,WHITE);
                uLCD.filled_circle(40,15+2*35,3,WHITE);
                uLCD.filled_circle(15,40+2*35,3,WHITE);
                uLCD.filled_circle(40,40+2*35,3,WHITE);
                uLCD.filled_circle(15,27+2*35,3,WHITE);
                uLCD.filled_circle(40,27+2*35,3,WHITE);
            }
        }
        if (i==3){
            if (arrDice[i]==1){
            //print one
                uLCD.filled_circle(27+35,27,3,WHITE);
            }
            if (arrDice[i]==2){
             //print two
                uLCD.filled_circle(15+35,15,3,WHITE);
                uLCD.filled_circle(40+35,40,3,WHITE);
            }
            if (arrDice[i]==3){
                uLCD.filled_circle(15+35,15,3,WHITE);
                uLCD.filled_circle(40+35,40,3,WHITE);
                uLCD.filled_circle(27+35,27,3,WHITE);
            }
            if (arrDice[i]==4){
                uLCD.filled_circle(15+35,15,3,WHITE);
                uLCD.filled_circle(40+35,15,3,WHITE);
                uLCD.filled_circle(15+35,40,3,WHITE);
                uLCD.filled_circle(40+35,40,3,WHITE);
            }
            if (arrDice[i]==5){
                uLCD.filled_circle(15+35,15,3,WHITE);
                uLCD.filled_circle(40+35,15,3,WHITE);
                uLCD.filled_circle(15+35,40,3,WHITE);
                uLCD.filled_circle(40+35,40,3,WHITE);
                uLCD.filled_circle(27+35,27,3,WHITE);
            }
            if (arrDice[i]==6){
                uLCD.filled_circle(15+35,15,3,WHITE);
                uLCD.filled_circle(40+35,15,3,WHITE);
                uLCD.filled_circle(15+35,40,3,WHITE);
                uLCD.filled_circle(40+35,40,3,WHITE);
                uLCD.filled_circle(15+35,27,3,WHITE);
                uLCD.filled_circle(40+35,27,3,WHITE);
            }
        }
        if (i==4){
            if (arrDice[i]==1){
                uLCD.filled_circle(27+35,27+35,3,WHITE);
            }
            if (arrDice[i]==2){
                uLCD.filled_circle(15+35,15+35,3,WHITE);
                uLCD.filled_circle(40+35,40+35,3,WHITE);
            }
            if (arrDice[i]==3){
                uLCD.filled_circle(15+35,15+35,3,WHITE);
                uLCD.filled_circle(40+35,40+35,3,WHITE);
                uLCD.filled_circle(27+35,27+35,3,WHITE);
            }
            if (arrDice[i]==4){
        uLCD.filled_circle(15+35,15,3,WHITE);
                uLCD.filled_circle(40+35,15+35,3,WHITE);
                uLCD.filled_circle(15+35,40+35,3,WHITE);
                uLCD.filled_circle(40+35,40+35,3,WHITE);
            }
            if (arrDice[i]==5){
            uLCD.filled_circle(15+35,15+35,3,WHITE);
                uLCD.filled_circle(40+35,15+35,3,WHITE);
                uLCD.filled_circle(15+35,40+35,3,WHITE);
                uLCD.filled_circle(40+35,40+35,3,WHITE);
                uLCD.filled_circle(27+35,27+35,3,WHITE);
            }
            if (arrDice[i]==6){
                uLCD.filled_circle(15+35,15+35,3,WHITE);
                uLCD.filled_circle(40+35,15+35,3,WHITE);
                uLCD.filled_circle(15+35,40+35,3,WHITE);
                uLCD.filled_circle(40+35,40+35,3,WHITE);
                uLCD.filled_circle(15+35,27+35,3,WHITE);
                uLCD.filled_circle(40+35,27+35,3,WHITE);
            }
        }
        if (i==5){
            if (arrDice[i]==1){
            uLCD.filled_circle(27+35,27+2*35,3,WHITE);
            }
            if (arrDice[i]==2){
             uLCD.filled_circle(15+35,15+2*35,3,WHITE);
            uLCD.filled_circle(40+35,40+2*35,3,WHITE);
            }
            if (arrDice[i]==3){
            uLCD.filled_circle(15+35,15+2*35,3,WHITE);
                uLCD.filled_circle(40+35,40+2*35,3,WHITE);
                uLCD.filled_circle(27+35,27+2*35,3,WHITE);
            }
            if (arrDice[i]==4){
        uLCD.filled_circle(15+35,15,3,WHITE);
                uLCD.filled_circle(40+35,15+2*35,3,WHITE);
                uLCD.filled_circle(15+35,40+2*35,3,WHITE);
                uLCD.filled_circle(40+35,40+2*35,3,WHITE);
            }
            if (arrDice[i]==5){
            uLCD.filled_circle(15+35,15+35,3,WHITE);
                uLCD.filled_circle(40+35,15+2*35,3,WHITE);
                uLCD.filled_circle(15+35,40+2*35,3,WHITE);
                uLCD.filled_circle(40+35,40+2*35,3,WHITE);
                uLCD.filled_circle(27+35,27+2*35,3,WHITE);
            }
            if (arrDice[i]==6){
                uLCD.filled_circle(15+35,15+2*35,3,WHITE);
                uLCD.filled_circle(40+35,15+2*35,3,WHITE);
                uLCD.filled_circle(15+35,40+2*35,3,WHITE);
                uLCD.filled_circle(40+35,40+2*35,3,WHITE);
                uLCD.filled_circle(15+35,27+2*35,3,WHITE);
                uLCD.filled_circle(40+35,27+2*35,3,WHITE);
            }
        }
    }//end for loop
}//if shake statement
/*
if (rollScore==0){
    uLCD.printf("FARKLE");
    turnScore=0;
}
else{
    uLCD.printf("This roll = "+ rollScore + "\n");
       uLCD.printf("This turn = "+ turnScore);
    
}
}//end displayDice

int FarkleGame::calcRoll(){
    for (int j=1; j<=6;j++){
        for (int p= 0; p<numDice; p++){
            if (arrDice[p]==j){
                sortedArrDice[j]+=1;
            }
        }
    }
    if (sortedArrDice[5]==1){
        rollScore+=50;
    }
    if(sortedArrDice[1]==1){
        rollScore+=100;
    }
    if(sortedArrDice[1]==3){
        rollScore+=1000;
    }
    if(sortedArrDice[2]==3){
        rollScore+=200;
    }
    if(sortedArrDice[3]==3){
        rollScore+=300;
    }
    if(sortedArrDice[4]==3){
        rollScore+=400;
    }
    if(sortedArrDice[5]==3){
        rollScore+=500;
    }
    if(sortedArrDice[6]==3){
        rollScore+=600;
    }
    if(sortedArrDice[1]==1 && sortedArrDice[2]==1 && sortedArrDice[3]==1 && sortedArrDice[4]==1 && sortedArrDice[5]==1 && sortedArrDice[6]==1){
        rollScore+=1500;
    }
    for (int i =1; i<=6; i++){
        if (sortedArrDice[i]==6){
            rollScore+=3000;
        }
        if(sortedArrDice[i]==5){
            rollScore+=2000;
        }
        if(sortedArrDice[i]==4){
            rollScore+=1000;
        }
        if (sortedArrDice[i]==2){
            pairCounter+=1;
        }
        if(sortedArrDice[i]==3){
            tripCounter+=1;
        }
    }
    if(pairCounter==3){
        rollScore+=1500;
    }
    if(tripCounter==2){
        rollScore+=2500;
    }
    //ADD THE 3 FARKLES IN A ROW -1000 Maybe
    turnScore+=rollScore;
    return rollScore;
}
*/

int main() {
   //int numDice=6;
    //uLCD.printf("Shake\nBoard\n------\nTo\nRoll\n "+ numDice + " Dice");
    
   bool MusicOn = false;
   //set the push buttons that control sounds
   pb1.mode(PullUp);
   pb2.mode(PullUp);
   //I will not use interupts like in jazzy tunes
   MMA8452 acc(p28, p27, 40000); //instantiate an acc object!
   //set parameters -- use these and don't change
   acc.setBitDepth(MMA8452::BIT_DEPTH_12);
   acc.setDynamicRange(MMA8452::DYNAMIC_RANGE_4G);
   acc.setDataRate(MMA8452::RATE_100);
   while(1) {
        uLCD.filled_circle(15,15,3,WHITE);
        uLCD.filled_circle(10,0,3,WHITE);
        //uLCD.filled_circle(15,40,3,WHITE);
        //uLCD.filled_circle(40,40,3,WHITE);
       // uLCD.filled_circle(27,27,3,WHITE);
        //uLCD.rectangle(10, 10, 45, 45, WHITE);
      if(!acc.isXYZReady()) 
      {
         wait(0.01);
      }
      else
      { 
      //acc.readXYZGravity(&x,&y,&z); //notice this is passed by reference use pointers
      //uLCD.circle(-1*y*factor+offsety, -1*x*factor+offsetx, radius, WHITE);
      if (MusicOn)
       //    mySpeaker.PlayNote(440.0+x*music_factor,0.25+0.2*y,0.05);
      if (pb1 == false)
           MusicOn = true;    
      if (pb2 == false)
            MusicOn = false;
      } //end else
   } //end infinite while loop
   
}