
// Number 1

#include <iostream> 
using namespace std; 

int main() { 
    // declare all the variables 
    int temperature; 

    // prompt the user & get their input 
    cout << "What is the temperature?" << endl; 
    cin >> temperature; 

    // input validation: temperature must be positive 
    if (temperature <= 0) // FILL IN THIS LINE 
    { 
        cout << "Invalid temperature." << endl; 
        return 0; 
    } 

    // decide if you need to carry extra water based on the temperature 
    if (temperature > 85) // FILL IN THIS LINE 
    { 
        cout << "You need to carry extra water." << endl; 
    } 
    else 
    { 
        cout << "You don't need extra water." << endl; 
    } 

    return 0; 
}





// Number 2


#include <iostream>
using namespace std;

int main() {
    // Declare variables
    double budget;
    double miles;
    int nights;

    // Get inputs from the user matching the test case prompts exactly
    cout << "What is your budget?" << endl;
    cin >> budget;
    cout << "How many miles will you drive?" << endl;
    cin >> miles;
    cout << "How many nights do you want to spend there?" << endl;
    cin >> nights;

    // Input validation: ensure all inputs are non-negative
    if (budget < 0 || miles < 0 || nights < 0) {
        cout << "Invalid input(s)." << endl;
        return 0;
    }

  //Calculate the total amount of gas mileage using 16 cents per mile. 
    double gas_money = miles * 0.16;

    double remaining_budget = budget - gas_money;

    double money_per_night;
    if (nights == 0) {
        money_per_night = remaining_budget; 
    } else {
        money_per_night = remaining_budget / nights;
    }

    // Determine affordability and lodging tiers matching exact expected strings
    if (money_per_night < 20) {
        cout << "This trip is outside your budget." << endl;
    } 
    else if (money_per_night >= 100) {
        cout << "You can afford to stay in a nice hotel on this trip." << endl;
    } 
    else if (money_per_night >= 50) {
        cout << "You can afford to stay in a cheap motel on this trip." << endl;
    } 
    else {
        cout << "You can afford to go camping on this trip." << endl;
    }

    return 0;
}

//number 3 
#include <iostream>
using namespace std;

int main()
{
    double day1, day2, day3;

    cout << "Enter temperatures over the last three days:" << endl;
    cin >> day1 >> day2 >> day3;

    if (day1 < 0 || day2 < 0 || day3 < 0)
    {
        cout << "Invalid temperature input." << endl;
    }
    else if (day1 < day2 && day2 < day3)
    {
        cout << "It's getting warmer!" << endl;
    }
    else if (day1 > day2 && day2 > day3)
    {
        cout << "It's getting cooler!" << endl;
    }
    else
    {
        cout << "The temperature is changing unpredictably." << endl;
    }

    return 0;
}


//number 4
#include <iostream>
using namespace std;
#include <iostream>
using namespace std;

int main()
{
    char cartype;
    int days = 0;
    double baseprice = 0.0;
    double priceperday = 0.0;

    cout << "Which car type (A, B, C, or D) would you like to rent?" << endl;
    cin >> cartype;
    cout << "How many days would you like to rent this car?" << endl;
    cin >> days;

    if (cartype == 'A')
    {
        baseprice = 80;
        priceperday = 15;
    }
    else if (cartype == 'B')
    {
        baseprice = 110;
        priceperday = 25;
    }
    else if (cartype == 'C')
    {
        baseprice = 160;
        priceperday = 35;
    }
    else if (cartype == 'D')
    {
        baseprice = 220;
        priceperday = 45;
    }
    else
    {
        cout << "Please enter valid input." << endl;
        return 0;
    }

    if (days < 1)
    {
        cout << "Please enter valid input." << endl;
        return 0;
    }

    double total = 1.23 * (baseprice + days * priceperday);

    cout.setf(ios::fixed);
    cout.precision(2);
    cout << "Your total is $" << total << endl;

    return 0;
}