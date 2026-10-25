#include <iostream>
#include <string>
using namespace std;

// Grid boundaries for a 10x10 grid
 int MIN_CORD = 0;
 int MAX_CORD = 9;
// Function to move the rover forward if conditions are met
bool moveForward(int &x, int &y, string heading, int &battery) {
    if (battery < 2) {
        cout << "command F rejected: insufficient battery" << endl;
        return false;
    }

    int newX = x;
    int newY = y;

    if (heading == "North") {
        newY++;
    } else if (heading == "East") {
        newX++;
    } else if (heading == "South") {
        newY--;
    } else if (heading == "West") {
        newX--;
    }

    if (newX < MIN_CORD || newX > MAX_CORD ||
        newY < MIN_CORD || newY > MAX_CORD) {
        cout << "command F rejected: out of bounds" << endl;
        return false;
    }
    x = newX;
    y = newY;

    battery = battery - 2;
    return true;
}

// Function to turn the rover left if conditions are met
bool turnLeft(string &direction, int &battery) {
    if (battery < 1) {
        cout << "command L rejected: insufficient battery" << endl;
        return false;
    }
    if (direction == "North") {
        direction = "West";
    } else if (direction == "East") {
        direction = "North";
    } else if (direction == "South") {
        direction = "East";
    } else if (direction == "West") {
        direction = "South";
    }
    battery = battery - 1;
    return true;
}

// Function to turn the rover right if conditions are met
bool turnRight(string &direction, int &battery) {
    if (battery < 1) {
        cout << "command R rejected: insufficient battery" << endl;
        return false;
    }
    if (direction == "North") {
        direction = "East";
    } else if (direction == "East") {
        direction = "South";
    } else if (direction == "South") {
        direction = "West";
    } else if (direction == "West") {
        direction = "North";
    }
    battery = battery - 1;
    return true;
}

// Function to scan the current location if there is enough battery
bool scan(int &battery) {
    if (battery < 3) {
        cout << "command S rejected: insufficient battery" << endl;
        return false;
    }
    battery = battery - 3;
    return true;
}

// Function to recharge the battery to 40 if the rover is at (0,0)
bool charge(int x, int y, int &battery) {
    if (x == 0 && y == 0) {
        battery = 40;
        return true;
    } else {
        cout << "command C rejected: not at charging station" << endl;
        return false;
    }
}

int main() {
//intialaltion of rover position and where it is heading heading
    int roverX = 0;
    int roverY = 0;
    string heading = "East";
    int battery = 40;

 // Mission user input
    string mission;
    int goalX;
    int goalY;
 //while loop that will keep requesting a mission for the user until the quit is typed 
   
    cout << "Input mission: ";
    cin >> mission;

    while (mission != "quit" && mission != "QUIT") {
        cout << "Input goal x coordinate: ";
        cin >> goalX;
        cout << "Input goal y coordinate: ";
        cin >> goalY;

// checks and keeps track of how many successful commands there were and if the rover every reached the goal 
        int successCount = 0;
        bool reachedGoal = (roverX == goalX && roverY == goalY);


// For loop going through each command letter in the mission
        for (int i = 0; i < mission.length(); i++) {
            char command = mission[i];
            bool success = false;

            if (command == 'F' || command == 'f') {
                success = moveForward(roverX, roverY, heading, battery);
            } else if (command == 'L' || command == 'l') {
                success = turnLeft(heading, battery);
            } else if (command == 'R' || command == 'r') {
                success = turnRight(heading, battery);
            } else if (command == 'S' || command == 's') {
                success = scan(battery);
            } else if (command == 'C' || command == 'c') {
                success = charge(roverX, roverY, battery);
            } else {
                cout << "command " << command << " rejected: unknown command" << endl;
            }

// Print the success line for every command that worked
            if (success) {
                cout << "Command " << command << " succeeded. Current coordinates: ("
                     << roverX << "," << roverY << ") Heading: " << heading
                     << " Battery: " << battery << endl;
                successCount++;

// checks the full mission summary and checks if the rover reached the goal
                if (roverX == goalX && roverY == goalY) {
                    reachedGoal = true;
                }
            }
        }   
// displays the final summery of the misson to the user depending on what peramters  where met 
        cout << "Mission Complete!" << endl;
        cout << "Rover ended at coordinates (" << roverX << "," << roverY
             << ") with heading " << heading << " and battery " << battery << "." << endl;
        cout << "Number of Successful Commands: " << successCount << endl;

// Checks WHERE the rover is and checks the battery to see if the rover was reset 
        bool reset = (roverX == 0 && roverY == 0 && battery == 40);

        if (reachedGoal && reset) {
            cout << "Goal reached and rover reset." << endl;
        } else if (reachedGoal && !reset) {
            cout << "Goal reached but rover not reset." << endl;
        } else if (!reachedGoal && reset) {
            cout << "Goal not reached but rover rese t." << endl;
               } else {
             cout << "Goal not reached and rover not reset." << endl;
        }

        cout << "Input mission: ";
        cin >> mission;
    }

    cout << "Exiting Mission command: aborting mission." << endl;
    return 0;
}
