#include <bits/stdc++.h>
#include <fstream>

using namespace std;

void mainMenu();

class Management {
public:
    Management() {
        mainMenu();
    }
};

class PassengerDetails {
public:
    static string passengerName, passengerGender;
    static int passengerId;
    int phoneNumber;
    int passengerAge;
    string address;
    char arr[100];

    void getInformation() {
        cout << "\nEnter the passenger ID : ";
        cin >> passengerId;
        cout << "\nEnter the passenger name : ";
        cin >> passengerName;
        cout << "\nEnter the passenger age : ";
        cin >> passengerAge;
        cout << "\nEnter the passenger Address : ";
        cin >> address;
        cout << "\nEnter the passenger gender : ";
        cin >> passengerGender;
        cout << "\nYour information saved \n ";
    }
};

int PassengerDetails::passengerId;
string PassengerDetails::passengerName;
string PassengerDetails::passengerGender;

class FlightRegistration {
public:
    static int choice;
    int choice1;
    int back;
    static float charges;

    void showFlights() {
        string flightDestinations[] = {"Dubai", "Canada", "UK", "USA", "Germany"};
        
        for (int i = 0; i < 5; i++) {
            cout << i + 1 << " Flight to " << flightDestinations[i] << endl;
        }

        cout << "Welcome to  SKYHIGH Airlines" << endl;
        cout << "Press the number for the flight: ";
        cin >> choice;

        switch (choice) {
            // Cases for different destinations
        }
    }
};

float FlightRegistration::charges;
int FlightRegistration::choice;

class Ticket : public FlightRegistration, public PassengerDetails {
public:
    void showBill() {
        string destination = "";
        ofstream outf("records.txt");

        outf << "___________ Sky High Airlines_________" << endl;
        outf << "____________Tickets_________" << endl;
        outf << "_____________________________" << endl;
        outf << "passenger ID: " << PassengerDetails::passengerId << endl;
        outf << "passenger Name: " << PassengerDetails::passengerName << endl;
        outf << "passenger Gender: " << PassengerDetails::passengerGender << endl;
        outf << "Description" << endl << endl;

        // Write more details to file

        outf.close();
    }

    void displayBill() {
        ifstream ifs("records.txt");
        {
            if (!ifs) {
                cout << "File error !" << endl;
            }

            while (!ifs.eof()) {
                ifs.getline(arr, 100);
                cout << arr << endl;
            }
        }
        ifs.close();
    }
};

void mainMenu() {
    int userChoice;
    int subChoice;
    int back;

    cout << "\t     SKY High Airlines  \n" << endl;
    cout << "\t______________Main Menu______________" << endl;
    cout << "\t________________________________________" << endl;
    cout << "\t|\t\t\t\t\t\t" << endl;
    cout << "\t|\t Press 1 To add the passenger details.           \t" << endl;
    cout << "\t|\t Press 2 For flight Registration.            	\t" << endl;
    cout << "\t|\t Press 3 To for tickets details.           		\t" << endl;
    cout << "\t|\t Press 4 To Exit.                                \t" << endl;
    cout << "\t|\t\t\t\t\t" << endl;

    cout << "Enter your choice :  ";
    cin >> userChoice;

    if (cin.fail())
        cout << " Please Press valid Integer" << endl;
    else {
        PassengerDetails pd;
        FlightRegistration fr;
        Ticket tk;

        switch (userChoice) {
            case 1: {
                cout << "_______________Passengers________________\n" << endl;
                pd.getInformation();

                cout << "Press 1 to go back to Main Menu :";
                cin >> back;

                if (back == 1)
                    mainMenu();
                else
                    mainMenu();

                break;
            }

            case 2: {
                cout << "_____________Book a flight ___________\n" << endl;
                fr.showFlights();
                break;
            }

            case 3: {
                cout << "__________Get YOUR Ticket_________\n" << endl;
                tk.showBill();

                cout << "Your ticket is ready, you can collect it \n" << endl;
                cout << "Press 1 to display your ticket ";

                cin >> back;

                if (back == 1) {
                    tk.displayBill();
                    cout << "Press any key to go back to Main menu";
                    cin >> back;

                    if (back == 1) {
                        mainMenu();
                    } else
                        mainMenu();

                } else
                    mainMenu();

                break;
            }

            case 4: {
                cout << "___________Thank - You___________\n" << endl;
                break;
            }

            default: {
                cout << "Invalid input, Please try again" << endl;
                mainMenu();
                break;
            }
        }
    }
}

int main() {
    Management();
}
