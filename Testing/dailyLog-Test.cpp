#include "testing.h"
#include "../Hustle-Hamster/dailyLog.h"
#include "../Hustle-Hamster/Journal.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <limits>

void testDailyRating(Journal &journal, int input, int expectedOutput)
{
    std::stringstream inputStream;
    std::stringstream outputStream;
    
    std::streambuf *cinBackup = std::cin.rdbuf();
    std::streambuf *coutBackup = std::cout.rdbuf();

    std::cin.rdbuf(inputStream.rdbuf());
    std::cout.rdbuf(outputStream.rdbuf());

    inputStream <<input <<std::endl;

    dailyRating(journal);

    int rating = journal.getDayRating();
    assert(rating == expectedOutput);

    std::cin.rdbuf(cinBackup);
    std::cout.rdbuf(coutBackup);
}

void testSleepRating(Journal &journal)
{
    std::istringstream input("3\n");         // Simulating correct user input "3"

    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    // Test sleepRating function with mock input
    sleepRating(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    // Get sleep rating and check it is correct
    int rating = journal.getSleepRating();
    assert(rating == 3);
}

void testMoodRating(Journal &journal)
{
    std::istringstream input("Happy\n");    // Simulating correct user input "Happy"

    std::streambuf *cinbuf = std::cin.rdbuf(); // Save original buffer
    std::cin.rdbuf(input.rdbuf());             // Redirect std::cin to read from input

    // Test moodRating function with mock input
    moodRating(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    std::string mood = journal.getMood();
    assert(mood == "Happy");
}

void testLongAnswer(Journal &journal)
{
    std::istringstream input("This is a long answer\n"); // Simulating user input "This is a long answer"
    std::streambuf *cinbuf = std::cin.rdbuf();          // Save original buffer
    std::cin.rdbuf(input.rdbuf());                      // Redirect std::cin to read from input

    // Test longAnswer function with mock input
    longAnswer(journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    std::string answer = journal.getTextEntry();
    std::cerr << "Actual output:" << answer << std::endl;
    assert(answer == "This is a long answer");
}

void testDidActivity(Journal &journal)
{
    std::istringstream input("y\n");             // Simulating correct user input "y"

    std::streambuf *cinbuf = std::cin.rdbuf();    // Save original buffer
    std::cin.rdbuf(input.rdbuf());                // Redirect std::cin to read from input

    string activity = "Activity 1";

    // Test didActivity function with mock input
    didActivity(activity, journal);

    // Restore cin buffer.
    std::cin.rdbuf(cinbuf);

    std::istringstream input2("n\n");             // Simulating user input "n"
    std::cin.rdbuf(input2.rdbuf());               // Redirect std::cin to read from input
    
    string activity2 = "Activity 2";
    didActivity(activity2, journal);

    std::cin.rdbuf(cinbuf);                        // Restore cin buffer.

    std::vector<std::string> activities = journal.getActivities();
    assert(activities.size() == 1);
    assert(activities[0] == "Activity 1");
}

int main()
{   
    // Set up Journal object
    Journal journal = Journal();

    // Run tests
    testDailyRating(journal, 3, 3);
    //testSleepRating(journal);
    //testMoodRating(journal);
    //testLongAnswer(journal);
    //testDidActivity(journal);

    // Delete the journal object
    journal.~Journal();

    std::cout << "All tests passed!" << std::endl;

    return 0;
}
