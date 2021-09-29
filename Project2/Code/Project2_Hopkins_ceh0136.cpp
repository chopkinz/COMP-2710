//=====================================================
// File Name: Project2_Hopkins_ceh0136.cpp
// Author: Chase Hopkins (ceh0136@auburn.edu)
//=====================================================
// Compile: g++ Project2_Hopkins_ceh0136.cpp -o p2.out
// Run: ./p2.out 
//=====================================================

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

// constant variables 
const float aaronHitRate = 0.333333333;
const float bobHitRate = 0.5;
const float charlieHitRate = 1;

// prototypes
bool at_least_two_alive(bool,bool,bool);
void Aaron_shoots1(bool&,bool&);
void Bob_shoots(bool&,bool&);
void Charlie_shoots(bool&,bool&);
void Aaron_shoots2(bool&,bool&);

// function for at least 2 alive 
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
   if ((A_alive && B_alive) || (A_alive && C_alive) || (B_alive && C_alive)) {
      return true;
   }
   else {
      return false;
   }
}

// first strategy for Aaron 
void Aaron_shoots1(bool& B_alive, bool& C_alive) {
   bool hitTarget = false;
   int shoot_target_result = rand() % 100;

   if (shoot_target_result < (aaronHitRate * 100)) {
      hitTarget = true;
   }

   if (C_alive == true && hitTarget == true) {
      C_alive = false;
   }
   else if (B_alive == true && hitTarget == true) {
      B_alive = false;
   }
}

// first test for Aaron shoots
void test_Aaron_shoots1(void)
{
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
   bool bob_a = true;
   bool charlie_a = true;

   cout << "\tCase 1: Bob alive, Charlie alive \n"
      << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots1(bob_a, charlie_a);
   assert(true == bob_a);

   bob_a = false;
   charlie_a = true;
   cout << "\tCase 2: Bob dead, Charlie alive \n"
      << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots1(bob_a, charlie_a);
   assert(false == bob_a);

   bob_a = true;
   charlie_a = false;
   cout << "\tCase 3: Bob alive, Charlie dead \n"
      << "\t\tAaron is shooting at Bob\n";
   Aaron_shoots1(bob_a, charlie_a);
   assert(false == charlie_a);
}

// test prototypes 
void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);

// function for Bob shoots 
void Bob_shoots(bool& A_alive, bool& C_alive) {
   bool hitTarget = false;
   int shoot_target_result = rand() % 100;

   if (shoot_target_result < (bobHitRate * 100)) {
      hitTarget = true;
   }

   if (C_alive == true && hitTarget == true) {
      C_alive = false;
   }
   else if (A_alive == true && hitTarget == true) {
      A_alive = false;
   }
}

// test for Bob shoots  
void test_Bob_shoots(void) {
   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";
   bool aaron_a = true;
   bool charlie_a = true;
   cout << "\tCase 1: Aaron alive, Charlie alive \n"
      << "\t\tBob is shooting at Charlie\n";
   Bob_shoots(aaron_a, charlie_a);
   assert(true == aaron_a);

   aaron_a = false;
   charlie_a = true;
   cout << "\tCase 2: Aaron dead, Charlie alive \n"
      << "\t\tBob is shooting at Charlie\n";
   Bob_shoots(aaron_a, charlie_a);
   assert(false == aaron_a);

   aaron_a = true;
   charlie_a = false;
   cout << "\tCase 3: Aaron alive, Charlie dead \n"
      << "\t\tBob is shooting at Aaron\n";
   Bob_shoots(aaron_a, charlie_a);
   assert(false == charlie_a);
}

// function for Charlie shoots 
void Charlie_shoots(bool& A_alive, bool& B_alive) {
   bool hitTarget = false;
   int shoot_target_result = rand() % 100;

   if (shoot_target_result < (charlieHitRate*100)) {
      hitTarget = true;
   }

   if (B_alive == true && hitTarget == true) {
      B_alive = false;
   }
   else if (A_alive == true && hitTarget == true) {
      A_alive = false;
   }
}

// test for Charlie shoots
void test_Charlie_shoots(void) {
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";
   bool aaron_a = true;
   bool bob_a = true;
   cout << "\tCase 1: Aaron alive, Bob alive \n"
      << "\t\tCharlie is shooting at Bob\n";
   Charlie_shoots(aaron_a, bob_a);
   assert(true == aaron_a);

   aaron_a = false;
   bob_a = true;
   cout << "\tCase 2: Aaron dead, Bob alive \n"
      << "\t\tCharlie is shooting at Bob\n";
   Charlie_shoots(aaron_a, bob_a);
   assert(false == aaron_a);

   aaron_a = true;
   bob_a = false;

   cout << "\tCase 3: Aaron alive, Bob dead \n"
      << "\t\tCharlie is shooting at Aaron\n";
   Charlie_shoots(aaron_a, bob_a);
   assert(false == bob_a);
}

// strategy 2 for Aaron - misses if both are alive 
void Aaron_shoots2(bool& B_alive, bool& C_alive) {
   bool hitTarget = false;
   int shoot_target_result = rand() % 100;

   if (shoot_target_result < (aaronHitRate * 100)) {
      hitTarget = true;
   }

   if (B_alive == true && C_alive == true) {
      return;
   }
   else {
      if (C_alive == true && hitTarget == true) {
         C_alive = false;
      }
      else if (B_alive == true && hitTarget == true) {
         B_alive = false;
      }
   }
}

// second test for Aaron shoots
void test_Aaron_shoots2(void) {
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
   bool bob_a = true;
   bool charlie_a = true;
   cout << "\tCase 1: Bob alive, Charlie alive \n"
      << "\t\tAaron intentionally misses his first shot\n"
      << "\t\tBoth Bob and Charlie are alive.\n";
   Aaron_shoots2(bob_a, charlie_a);
   assert(true == bob_a && charlie_a);

   bob_a = false;
   charlie_a = true;
   cout << "\tCase 2: Bob dead, Charlie alive \n"
      << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots2(bob_a, charlie_a);
   assert(false == bob_a);

   bob_a = true;
   charlie_a = false;
   cout << "\tCase 3: Bob alive, Charlie dead \n"
      << "\t\tAaron is shooting at Bob\n";
   Aaron_shoots2(bob_a, charlie_a);
   assert(false == charlie_a);
}

// pause function  
void Press_any_key(void);

// main method 
int main() {
   // opening message
   cout << "*** Welcome to Chases's Duel Simulator ***\n";

   // initialize random number generator
   srand(time(0));

   // call prototype testers 
   test_at_least_two_alive();
   Press_any_key();
   test_Aaron_shoots1();
   Press_any_key();
   test_Bob_shoots();
   Press_any_key();
   test_Charlie_shoots();
   Press_any_key();
   test_Aaron_shoots2();
   Press_any_key();

   // variable for total runs (10000) 
   const int TOTAL_RUNS = 10000;

   // strategy 1
   cout << "Ready to test strategy 1 (run " << TOTAL_RUNS << " times):\n";

   Press_any_key();

   bool aaronAlive;
   bool bobAlive;
   bool charlieAlive;

   int aaronWins1 = 0;
   int bobWins1 = 0;
   int charlieWins1 = 0;

   for (int i = 0; i < TOTAL_RUNS; i++) {
   
      aaronAlive = true;
      bobAlive = true;
      charlieAlive = true;
   
      // duel
      while (at_least_two_alive (aaronAlive, bobAlive, charlieAlive)) {
         if (aaronAlive) {
            Aaron_shoots1(bobAlive, charlieAlive);
         }
         if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
         }
         if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive);
         }
      }
   
      // count the wins 
      if (aaronAlive) {
         aaronWins1++;
      }
      if (bobAlive) {
         bobWins1++;
      }
      if (charlieAlive) {
         charlieWins1++;
      }
   }

   // results for strategy 1
   cout << "Aaron won "<< aaronWins1 << "/"<< TOTAL_RUNS << " duels or " << static_cast<double>(aaronWins1) / TOTAL_RUNS * 100 << "%\n";
   cout << "Bob won "<< bobWins1 << "/" << TOTAL_RUNS << " duels or " << static_cast<double>(bobWins1) / TOTAL_RUNS * 100 << "%\n";
   cout << "Charlie won "<< charlieWins1 << "/" << TOTAL_RUNS << " duels or " << static_cast<double>(charlieWins1) / TOTAL_RUNS * 100 << "%\n\n";

   // strategy 2
   cout << "Ready to test strategy 2 (run " << TOTAL_RUNS << " times):\n";

   Press_any_key();

   int aWins2 = 0; 
   int bWins2 = 0;
   int cWins2 = 0;

   for (int i = 0; i < TOTAL_RUNS; i++) {
   
      aaronAlive = true;
      bobAlive = true;
      charlieAlive = true;
   
      // battle
      while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
         if (aaronAlive) {
            Aaron_shoots2(bobAlive, charlieAlive);
         }
         if (bobAlive) {
            Bob_shoots(aaronAlive, charlieAlive);
         }
         if (charlieAlive) {
            Charlie_shoots(aaronAlive, bobAlive);
         }
      }
   
      // counts wins 
      if (aaronAlive) {
         aWins2++;
      } 
      if (bobAlive) {
         bWins2++;
      }
      if (charlieAlive) {
         cWins2++;
      }
   }

   // results for strategy 2 
   cout<< "Aaron won " << aWins2 << "/10000 duels or " << static_cast<double> (aWins2) / TOTAL_RUNS * 100 << "%\n";
   cout<< "Bob won " << bWins2 << "/10000 duels or " << static_cast<double> (bWins2) / TOTAL_RUNS * 100 << "%\n";
   cout<< "Charlie won "<< cWins2 << "/10000 duels or " << static_cast<double> (cWins2) / TOTAL_RUNS * 100 << "%\n\n";

   // compares and determines the better strategy, prints results 
   if (aWins2 < aaronWins1) {
      cout << "Strategy 1 is better than Strategy 2.\n";
   }
   else {
      cout << "Strategy 2 is better than Strategy 1.\n";
   }

   return 0;
}

// test for 2 alive  
void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true,true,false));
   cout << "\tCase passed ...\n";

   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false,false,true));
   cout << "\tCase passed ...\n";

   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false,true,false));
   cout << "\tCase passed ...\n";

   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true,false,false));
   cout << "\tCase passed ...\n";

   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false,false,false));
   cout << "\tCase passed ...\n";
}

// pause function 
void Press_any_key(void) {
   cout << "Press any key to continue...\n";
   cin.get();
}

