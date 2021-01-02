/*
    CS3
    Ch10 Exercises
*/

#include <iostream>
using namespace std;

int main()
{
    
}

/*
    1a. double
    1b. double
    1c. int
    1d. N/A
    1e. char
    1f. TermAccount

    2. A$9.99
       A$1.11

    3. Missing the parantheses after struct definition, the
       compiler doesn't know where the struct definition ends

    4. A x = {1,2};

    5a. Initializes dueDate with month 12, day 21, year 0
    5b. Too many initializer values
    5c. //
    5d. Initializes dueDate with month 12, day 21, year 22

    6. struct EmployeeRecord{
          double wage;
          int vacation;
          char status;
       };

    7. void readShoeRecord(ShoeType& newShoe) {
          cout << "Enter style: ";
          cin>>newShoe.style;
          cout << endl << "Enter price: ";
          cin>>newShoe.price;
       }

    8. ShoeType discount(ShoeType oldRecord) {
          ShoeType newRecord;
          newRecord = oldRecord;
          newRecord.price *= 0.9;
          return newRecord;
       }

    9. struct StockRecord{
          ShoeType shoeInfo;
          Date arrivalDate;
       }

    10. StockRecord newStockRecord;
        newStockRecord.arrivalDate.year = 2006;

    11. void DayOfYear::input() {
           cout << "Enter month: ";
           cin >> month;
           cout << endl << "Enter day: ";
           cin >> day;
        }

    12. void DayOfYear::set(double newDegrees, char newScale) {
            this-> degrees = newDegrees;
            this-> scale = newScale;
        }

    13. The dot operator is used with member names to specify
        which class or struct it belongs to. The scope resolution
        operator tells the compiler that the following function is
        part of the class before the scope resolution operator

    14. void DayOfYear::checkDate() {
           if(day<1)||(day>31)||(month<1)||(month>12){
              cout << "Illegal date" << endl;
           }
           if((month==4)||(month==6)||(month==9)||(month==11))
           && (day==31)) {
              cout << "Illegal date" << endl;
           }
           if((month==2) && (day>29)) {
              cout << "Illegal date" << endl;
           }
        }

    15. no, yes, yes, yes, no, no, no, yes

    16. Everything is legal except for the hyundai==jaguar statement

    17. Public and private are access keywords and define whether or not
        the following members are publically accessible using the dot
        operator. It is generally inadvisable to set everything to public
        because then anyone outside the program can modify any of the values
        at any time. They can also set illegal values. It is much better practice
        to use practice encapsulation and use accessors and mutators.

    18a. one
    18b. none
    18c. private
    18d. public

    19. double difference(BankAccount account1, BankAccount account2){
            double diff = account1.getBalance() - account2.getBalance();
            return diff;
        }

    20. void doubleUpdate(BankAccount& theAccount){
            theAccount.update();
            theAccouht.update();
        }

    21. BankAccount newAccount(BankAccount oldAccount) {
            BankAccount temp;
            temp.set(0, oldAccount.getRate());
            return temp;
        }

    22. yes, yes, no, yes, yes, no

    23. class DayOfYear {
        public:
            DayOfYear(int theMonth, int theDay);
            DayOfYear();
            void input();
            void output();
            int getMonth();
            int getDay();
        private:
            void checkDate();
            int month;
            int day;
        };

        DayOfYear::DayOfYear(int theMonth, int theDay){
            this->month = theMonth;
            this->day = theDay;
        }

        DayOfYear::DayOfYear(){
            month = 1;
            day = 1;
        }

    24. DayOfYear::DayOfYear(int theMonth, int theDay):month(theMonth), day(theDay){
            checkDate();
        }
        DayOfYear::DayOfYear():month(1), day(1){

        }
        
    25. When defining an ADT as a C++ class, member variables should be private
        and manipulated using accessors and mutators. Member functions can be either
        private or public, depending on their use. Accessor and mutator functions should
        be public while functions that perform internal procedures should be private.

    26. The items that are considered the interface of the ADT are the declarations for member
        variables and public member functions. They are located in the header file. All function
        definitions are part of the implementation.

    27. You only really need to read the interface for the ADT as you are not really concerned 
        with how the class works, just what the class and its members do.

    28. BankAccount::BankAccount ( int dollars, int cents, double rate) : dollarsPart(dollars), centsPart(cents),
        interestRate(fraction(rate)){
            if ((dollars < 0) || (cents < 0) || (rate < 0)){
                cout << "Illegal numbers inputted" << endl;
            }
        }
        BankAccount::BankAccount(int dollars, double rate): dollarsPart(dollars), centsPart(0),
        interestRate(fraction(rate)){
            if ((dollars < 0) || (rate < 0) {
                cout << "Illegal numbers inputted" << endl;
            }
        }

    29. The derived class can access any functions and data in the parent class. This eliminates redundant code
        and streamlines the maintenance process. Instead of updating the same code in multiple locations, the
        developer only has to update the parent class.

    30. Directly no, but it can use an accessor.

    31. Yes
*/