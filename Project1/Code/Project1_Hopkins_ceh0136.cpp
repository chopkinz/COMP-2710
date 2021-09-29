/* 
* Chase Hopkins (ceh0136@auburn.edu)
* Project File: project1_Hopkins_ceh0136.cpp
*
* Complile: g++ project1_Hopkins_ceh0136.cpp -o p1.out 	
* Run: ./p1.out 
*/

#include <iostream> 
#include <stdlib.h> 
using namespace std; 

int main() {

	// formatting //
   cout.setf(ios::fixed);
   cout.setf(ios::showpoint);
   cout.precision(2);

    // variables // 
   float loan = 0;
   float rate = 0;
   float payment = 0;


    // checks if loan is valid // 
   while (loan <= 0) {
      cout << "Loan Amount: ";
      cin >> loan;
      cin.clear();  
        
      if (loan <= 0 || cin.fail()) {
         cout << "*Error: Invalid loan.*" << endl;

         exit(0); // ends program 
      }
   }

    // checks if rate is valid //
   bool checkRate = false;

   while (checkRate == false) {
      cout << "Interest Rate (% per year): ";
        
      if (cin >> rate) {
            
         if (rate < 0) {  
            checkRate = false;
            cout << "*Error: Invalid interest rate.*" << endl;

            exit(0); // ends program 
         }
            
         else {
            checkRate = true;
         }
      }
        
      else {
         cin.clear();
         cout << "*Error: Invalid interest rate.*" << endl;

         exit(0); // ends program 
      }
   }

     // calculations //
   rate = rate / 100;
   rate = rate / 12;

   float minimum_payment = loan * rate;

   while (payment <= minimum_payment) { // checks for invalid payment 
      cout << "Monthly Payments: ";
      cin >> payment;
      cin.clear();
   
      if (payment <= minimum_payment && payment > 0) {
         cout << "*Error: Insufficient payment.*" << endl;

         exit(0);
      }
        
      else if (payment <= 0) {
         cout << "*Error: Invalid payment.*" << endl; 

         exit(0); // ends program 
      }
   }
    cout << endl;

   // amortization table //
   cout << "*****************************************************************\n"
         << "\tAmortization Table\n"
         << "*****************************************************************\n"
         << "Month\tBalance\t\tPayment\tRate\tInterest\tPrincipal\n";

   // variables 
   float balance = loan;
   float interest = 0;
   float total_interest  = 0;
   float principal = 0;
   int current_month = 0;
   float final_payment = 0;

    // loop that fills table
   while (balance > 0) {
      
        
      if (current_month == 0) {
         cout << current_month << "\t$" << loan;
         cout << "\tN/A\tN/A\tN/A\t\tN/A\n";
      }
      current_month++;
             
      interest = balance * rate;
      total_interest  = total_interest  + interest;
   
      if (payment > balance + interest) {
         principal = balance + interest;
      }
   
      principal = payment - interest;
      balance = balance - principal;

      if (balance < payment && balance > 0) {
         final_payment = balance;
      }

      if (balance < 0) {
         balance = 0;
      }

      if (balance <= 0) {
         principal = final_payment; // final payment 
         cout << current_month << "\t$" << balance << "\t\t$" << final_payment + interest << "\t" << rate * 100 << "\t$" << interest << "\t\t$" << principal << endl;
      }

         else if (balance < 1000) { // if balance is less than 1000, tab over to align 
            cout << current_month << "\t$" << balance << "\t\t$" << payment  << "\t" << rate * 100 << "\t$" << interest << "\t\t$" << principal << endl;
         } 
      
      else { // standard format for the rest of the table 
         cout << current_month << "\t$" << balance << "\t$" << payment << "\t" << rate << "\t$" << balance << "\t$" << principal << endl;
      }
   
  }
   
     
   if (current_month == 1) { // formats output for single month
      cout <<"*****************************************************************\n";
      cout << "\nIt takes " << current_month << " month to pay off "
            <<"the loan. \n"
            <<"Total interest paid is: $" << total_interest ;
      cout << endl << endl;	
   }
        
   else { // prints how long it takes to pay off loan and total interest paid 
      cout <<"*****************************************************************\n";
      cout <<"\nIt takes " << current_month << " months to pay off "
            <<"the loan. \n"
            <<"Total interest paid is: $" << total_interest ;
      cout << endl << endl;
      return 0;
   }
}
