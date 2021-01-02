/*
    CS3
    Ch12 Practice Programs
*/

#include <iostream>
#include "DigitalTime.h"

int main()
{
    DigitalTime current(7, 30), previous(7,0);
    int hours, minutes;
    current.intervalSince(previous, hours, minutes);
    cout << "The time interval between " << previous
        << " and " << current << endl
        << "is " << hours << " hours and "
        << minutes << " minutes.\n";
}

namespace Authenticate {
    string username, password;

    bool isValid() {
        if (username.length > 7) {
            return false;
        }
        return true;
    }

    void inputUserName() {
        do
        {
            cout << "Enter your username (8 letters only)" << endl;
            cin >> username;
        } while (!isValid());
    }
    string getUserName()
    {
        return username;
    }

    void inputPassword()
    {
        do
        {
            cout << "Enter your password (at least 8 characters " <<
                "and at least one nonletter)" << endl;
            cin >> password;
        } while (!isValid());
    }
    string getPassword()
    {
        return password;
    }
}

