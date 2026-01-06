#include <iostream>
#include <vector>
#include "Match.h"
using namespace std;

int main() {
    vector<Match> matches;
    int id;
    string fanName;
    bool found;

    // TESTING MATCHES
    matches.push_back(Match(1, "AHLY-ZAMALEK", 2));  // MAtch of id 1 and name and capacity 2
    matches.push_back(Match(2, "REAL-BARCA", 1)); // MAtch of id 2 and name and capacity 1

    int choice;
    do {
        cout << "1. View Matches" << endl;
        cout << "2. Book Match" << endl;
        cout << "3. Cancel Ticket"<<endl;
        cout << "4. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Viewing Matches\n";
                for (int i = 0; i < matches.size(); i++) {
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

                for (int i = 0; i < matches.size(); i++) {
                    if (matches[i].getMatchCode() != "" && id >= 1 && id <= matches.size()) {
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
                else {
                    cout << "Invalid Match ID\n";
                }
                cout<<"------------------------------------------------"<<endl;
                break;

            case 4:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 4);

    cout << "Goodbye" << endl;
    return 0;
}
