/*
 * Negotiating a consumer loan is not always straightforward. One form of loan is the discount installment loan, which
 * works as follows. Suppose a loan has a face value of $1,000, the interest rate is 15%, and the duration is 18 months.
 * The interest is computed by multiplying the face value of $1,000 by 0.15, to yield $150. That figure is then
 * multiplied by the loan period of 1.5 years to yield $225 as the total interest owed. That amount is immediately
 * deducted from the face value, leaving the consumer with only $775. Repayment is made in equal monthly installments
 * based on the face value. So the monthly loan payment will be $1,000 divided by 18, which is $55.56. This method of
 * calculation may not be too bad if the consumer needs $775 dollars, but the calculation is a bit more complicated if
 * the consumer needs $1,000. Write a program that will take three inputs: the amount the consumer needs to receive,
 * the interest rate, and the duration of the loan in months. The program should then calculate the face value required
 * in order for the consumer to receive the amount needed. It should also calculate the monthly payment. Your program
 * should allow the calculations to be repeated as often as the user wishes.
 */

#include <iostream>
using namespace std;

void introMessage();
double trueLoanValue(double interestRate, double totalYears, double loanAmount);
double totalInterest(double interestRate, double totalYears, double loanAmount);
double monthlyPayment(double interestRate, double totalYears, double loanAmount);

int main(){

char userAnswer;
double loanAmount = 0, yearlyInterestRate = 0, totalYears = 0;
int numberOfMonths = 0;


do{
   introMessage();
   cout << endl;

   cout << "Please enter the total loan amount: ";
   cin >> loanAmount;
   while(loanAmount <= 0){
       cout << "Please enter a valid amount: ";
       cin >> loanAmount;
   }
   cout << "Please enter the yearly interest rate: ";
   cin >> yearlyInterestRate;
   while(yearlyInterestRate < 0){
       cout << "Please enter a valid yearly interest rate: ";
       cin >> yearlyInterestRate;
   }
   yearlyInterestRate /= 100.0;

   cout << "Please enter the number of months to repay the loan: ";
   cin >> numberOfMonths;
   while(numberOfMonths <= 0){
       cout << "Please enter a valid number: ";
       cin >> numberOfMonths;
   }
   totalYears = (numberOfMonths / 12.0);

   cout << "Although you borrowed " << loanAmount << " dollars" << " after you make your final loan payment"
   << " after " << numberOfMonths << " months you will have truly paid: ";
  cout << trueLoanValue(yearlyInterestRate, totalYears, loanAmount);

  cout << endl << "After " << numberOfMonths << " months the total interest owed on the loan will be: ";
  cout << totalInterest(yearlyInterestRate, totalYears, loanAmount) << endl;

  cout << "Your monthly payment will be: " << monthlyPayment(yearlyInterestRate, totalYears, loanAmount) << endl;

  cin >> userAnswer;

}while(userAnswer == 'y');

return 0;
}

void introMessage(){
    cout << "This is a special message from Capital One Bank we have developed a special way for our costumers " <<
         "to calculate the total amount of interest owned on a particular loan as well as the total monthly payment\n"
         << endl;

    cout << "Press enter to continue: ";
    cin.ignore();
}

double trueLoanValue(double interestRate, double totalYears, double loanAmount){
    double interestToBePaid =  (interestRate * loanAmount) * totalYears;
    return interestToBePaid + loanAmount;
}

double totalInterest(double interestRate, double totalYears, double loanAmount){
    return (interestRate * loanAmount) * totalYears;
}

double monthlyPayment(double interestRate, double totalYears, double loanAmount){
    int numberOfMonths = (totalYears * 12);
    double totalInterest = (interestRate * loanAmount) * totalYears;
    return (totalInterest + loanAmount) / numberOfMonths;
}
