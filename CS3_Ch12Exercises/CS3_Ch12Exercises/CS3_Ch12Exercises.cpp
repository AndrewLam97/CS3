/*
    CS3
    Ch12 Exercises
*/

#include <iostream>
using namespace std;
namespace sally
{
    void message();
}
namespace
{
    void message();
}
int main()
{
    {
        message();
            using sally::message;
        message();
    }
    message();
    return 0;
} namespace sally
{
    void message()
    {
        cout << "Hello from Sally.\n";
    }
} namespace
{
    void message()
    {
        cout << "Hello from unnamed.\n";
    }
}
/*
1.  Interface = a,b,c
    Implmentation = d,e,f,g,h
    Application = main
2. .h
3. Implementation only
4. Interface file does not need to be recompiled along with modification of the implementation file.
5. Replace member unnecessary member variables with minutes. Update member function definitions in implementation file
6. An ADT is a class using separate compilation.
7. No
8. Yes because of function overloading
9. Yes
10. void wow(speedway::speed s1, indy500::speed s2);
11. void input(std::istream& ins);
    void output(std::ostream& outs) const;
12. No difference
13. Hello from unnamed.
    Hello from Sally. 
    Hello from unnamed.
14. Yes, one can remove the grouping for the helping function declarations if the function definitions
    are placed before their first use.
*/
