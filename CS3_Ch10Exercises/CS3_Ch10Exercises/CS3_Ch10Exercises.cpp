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
*/