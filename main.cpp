#include <iostream>
#include <vector>
#include "Match.h"
using namespace std;

void adminMenu(vector<Match>& matches);
void fanMenu(vector<Match>& matches);
int main() {
    vector<Match> matches;


    // TESTING MATCHES
    matches.push_back(Match(1, "AHLY-ZAMALEK", 2));  // MAtch of id 1 and name and capacity 2
    matches.push_back(Match(2, "REAL-BARCA", 1)); // MAtch of id 2 and name and capacity 1

    int userType;
    bool exitProgram = false;

    while (!exitProgram)   // Loop for main menu
    {
        cout << "\nLogin as:\n";
        cout << "1. Fan\n";
        cout << "2. Admin\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> userType;

        switch (userType)
        {
        case 1:
            fanMenu(matches); 
            break;
        case 2:
            adminMenu(matches); 
            break;
        case 3:
            cout << "Exiting program...\n";
            exitProgram = true;
            break;
        default:
            cout << "Invalid user type\n";
        }
    }

    cout << "Goodbye\n";
    return 0;
}


void adminMenu(vector<Match>& matches) {
    int choice;
    do {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Add Match\n";
        cout << "2. Delete Match\n";
        cout << "3. Set Match Capacity\n";
        cout << "4. View Match Tickets\n";
        cout << "5. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 3: {
                int id, cap;
                cout << "Match ID: ";
                cin >> id;
                cout << "New Capacity: ";
                cin >> cap;

                if (id >= 1 && id <= matches.size()) {
                    if (matches[id - 1].setCapacity(cap))
                        cout << "Capacity updated\n";
                    else
                        cout << "Invalid capacity\n";
                }
                break;
            }
        }
    } while (choice != 5);
}

void fanMenu(vector<Match>& matches) {
    int id;
    string fanName;
    bool found;
    int choice;
    do {
        cout << "\n--- Fan Menu ---\n";
        cout << "1. View Matches\n";
        cout << "2. Book Ticket\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
            {
            case 1:
                cout << "Viewing Matches\n";
                for (int i = 0; i < matches.size(); i++)
                {
                    matches[i].showAvailableSeats();
                }
                break;
            case 2:
                cout << "Booking Match\n";

                found = false;

                cout << "Enter Match ID: ";
                cin >> id;

                cout << "Enter Your Name: ";
                cin >> fanName;

                for (int i = 0; i < matches.size(); i++)
                {
                    if (matches[i].getMatchCode() != "" && id >= 1 && id <= matches.size())
                    {
                        found = true;
                        if (matches[id - 1].bookSeat(fanName))
                            cout << "Ticket Generated Successfully\n";
                        else
                            cout << "Match is Full\n";
                        break;
                    }
                }

                if (!found)
                    cout << "Invalid Match ID\n";
                break;
            case 3:
                cout<<"Cancel Ticket"<<endl;

                int matchId, ticketId;
                cout << "Enter Match ID: ";
                cin >> matchId;
                cout << "Enter Ticket ID: ";
                cin >> ticketId;

                if (matchId >= 1 && matchId <= matches.size())
                {
                    if (matches[matchId - 1].cancelTicket(ticketId))
                        cout << "Ticket cancelled successfully\n";
                    else
                        cout << "Ticket not found\n";
                }
                else
                {
                    cout << "Invalid Match ID\n";
                }
                break;

            case 4:
                cout << "Back to main menu...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }

        }
       } while (choice != 4);

        cout << "Goodbye" << endl;
}
