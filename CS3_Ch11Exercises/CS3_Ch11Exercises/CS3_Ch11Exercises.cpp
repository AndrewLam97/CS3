/*
    CS3
    CH11 Exercises
*/


#include <iostream>
#include <string>
using namespace std;

class Person{
    string firstName;
    string lastName;

public:
    Person(string last, string first);

    friend Person operator + (const Person& person1, const Person& person2);
    friend ostream& operator << (ostream& out, const Person& person1);
};


int main()
{
    std::cout << "Hello World!\n";
}







/*
    1. bool before(DayOfYear date1, DayOfYear date2){
        bool isBefore = (date1.getMonth() < date2.getMonth()) || (date1.getMonth() == date2.getMonth() && date1.getDay ( ) < date2.getDay ( ));
        return isBefore;
       }

    2. The two are similar in that they can use member variables and functions, but are accessed differently. Friend functions are defined and used like a normal function
       while member functions are accessed using the dot operator.

    3. class DayOfYear{
        public:
            friend bool equal (DayOfYear date1, DayOfYear date2);
            friend bool after (DayOfYear date1, DayOfYear date2);

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
            
        bool after(DayOfYear date1, DayOfYear date2){
            bool isBefore = (date1.month() > date2.month()) || (date1.month() == date2.month() && date1.day ( ) > date2.day ( ));
            return isBefore;
        }

    4. friend Money subtract (Money amount1, Money amount 2);

        Money subtract (Money amount1, Money amount2){
            Money temp;
            temp.allCents = amount1.allCents - amount2.allCents;
            return temp;
        }

    5. void output();
        
        void Money::output(){ output(cout);}

    6. Order matters since the input function will read the value of the digit1 as -9 and digit2 as 95. When it tries to add them, it comes up with a value of 
        -8.05, not -9.95

    7. int main(){
          int x;
          cin >> x;
          cout << x << endl;
          return 0;
       }

    8. double Money::getValue() const {
        return (allCents * 0.01);
       }

    9. input changes the original object so you can't use const

    10. Both prevent the original value from changing. Call by value uses more memory.

    11. const int prevents the integer from changing. function const will not change the calling object. function(const int& x) will not change the argument

    12.In a function call, the arguments are given in parentheses. If you overload an operator, you must use the keyword operator in the declaration and declaration/

    13. friend bool operator < (const Money& amount1, const Money& amount2);

    14. friend bool operator <= (const Money& amount1, const Money& amount2);

    15. An overloaded operator must have a class type as an argument

    16. Money::Money(double amount){
            allCents = floor(amount * 100);
        }

    17. istream& operator >>(istream& ins, Pairs& second){
            char ch;
            ins >> ch; 
            ins >> second.f;
            ins >> ch; 
            ins >> second.s;
            ins >> ch; 
            return ins;
        }
        ostream& operator <<(ostream& outs, const Pairs& second){
            outs << '(';
            outs << second.f;
            outs << ',';
            outs << second.s;
            outs << ')';
            return outs;
        }
        
    18. istream& operator >>(istream& ins, Percent& theObject){
            char percentSign;
            ins >> theObject.value;
            ins >> percentSign;//Discards the % sign.
            return ins;
        }

        ostream& operator <<(ostream& outs, const Percent& aPercent){
            outs << aPercent.value << '%';
            return outs;
        }

    19. struct Score{
            int homeTeam;
            int opponent;
        };
        Score game[10];

    20. int main(){
            Money amount[5];
            int i;
            cout << "Enter 5 amounts of money:\n";
            for (i = 0; i < 5; i++)
                cin >> amount[i];
            for (i = 0; i < 5; i++)
                amount[i] = amount[i] + amount[i];
            cout << "After doubling, the amounts are:\n";
            for (i = 0; i < 5; i++)
                cout << amount[i] << " ";
            cout << endl;
            return 0;
        }

    21. class TemperatureList {
        public:
            TemperatureList();
            int getSize( ) const;

            void addTemperature(double temperature);
            double getTemperature(int position) const;
            bool full() const;
            friend ostream& operator <<(ostream& outs,
            const TemperatureList& theObject);
        private:
            double list[MAX_LIST_SIZE];
            int size; //number of array positions filled
        };

    22. int TemperatureList::getSize() const {
            return size;
        }
        double TemperatureList::getTemperature (int position) const {
            if ((position >= size) || (position < 0)) {
                cout << "Error:" << " reading an empty list position.\n";
                exit(1);
            }
            else
                return (list[position]);
        }

    23. MyClass and ~MyClass

    24. What is your name?
        Kathryn Janeway
        We are Borg
        We will meet again Kathryn Janeway
        Good-bye cruel world! The short life of
        this dynamic array is about to end.
        Good-bye cruel world! The short life of
        this dynamic array is about to end.
        End of demonstration

    25. StringVar before scope resolution is the class name. The StringVar after the scope resolution is the member function name. The StringVar
        in the parentheses is the parameter type

    26. If using default data types, the copy constructor already knows what to do. The destructor works fine since there was no dynamic memory allocated.
*/
