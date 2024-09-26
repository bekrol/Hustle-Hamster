#include "includes/all_includes.h"

/* Defines namespace*/
using namespace std;


/**
 * Main -> calls menu
 * Inital Hammy welcome.
 * 
 * @see utils.h main()
 */
int main(){
    /**
     *  Development Process only so that developers
     *  can use MACOS and Windows
     */
    #if defined(_WIN32) || defined(_WINDOWS)
        SetConsoleCP(CP_UTF8);
        SetConsoleOutputCP(CP_UTF8);
    #endif

    TYPE("WELCOME TO HAMSTER HANGOUT");
    delay(stdDelay);
    printHammy();
    TYPE("Hi there!! It's so good to see you <3");
    cout << separator << "\n";

    // have the check here for whether it's the first time
    // so isFirstOpen
    // if true, just print app walkthrough 
    // would need to rework the help methods then to not call helpmenu() at the end, but rather within the helpmenu() loop itself
    // need to wait until the help rework is merged into main...

    menu();
}