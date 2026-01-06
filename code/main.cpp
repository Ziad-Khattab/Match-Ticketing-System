#include <iostream>
#include <vector>
#include <string>
#include "Match.h"
using namespace std;

void adminMenu(vector<Match>& matches);
void fanMenu(vector<Match>& matches);

int main() {
    vector<Match> matches;

    // TESTING MATCHES
    matches.push_back(Match(1, "AHLY-ZAMALEK", 2));
    matches.push_back(Match(2, "REAL-BARCA", 1));

    int userType;
    bool exitProgram = false;

    while (!exitProgram) {
        cout << "\nLogin as:\n";
        cout << "1. Fan\n";
        cout << "2. Admin\n";
        cout << "3. Exit\n";
        cout << "Choice: ";
        cin >> userType;

        switch (userType) {
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
            case 1: { // Add Match
                int id, cap;
                string name;
                cout << "Enter Match ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Match Name: ";
                getline(cin, name);
                cout << "Enter Match Capacity: ";
                cin >> cap;
                matches.push_back(Match(id, name, cap));
                cout << "Match added successfully.\n";
                break;
            }
            case 2: { // Delete Match
                int id;
                cout << "Enter Match ID to delete: ";
                cin >> id;
                bool found = false;
                for (auto it = matches.begin(); it != matches.end(); ++it) {
                    if (it->getMatchId() == id) {
                        matches.erase(it);
                        found = true;
                        cout << "Match deleted.\n";
                        break;
                    }
                }
                if (!found) cout << "Match not found.\n";
                break;
            }
            case 3: { // Set Capacity
                int id, cap;
                cout << "Enter Match ID: ";
                cin >> id;
                cout << "Enter New Capacity: ";
                cin >> cap;
                bool found = false;
                for (auto& m : matches) {
                    if (m.getMatchId() == id) {
                        if (m.setCapacity(cap))
                            cout << "Capacity updated successfully.\n";
                        else
                            cout << "Invalid capacity\n";
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Invalid Match ID\n";
                break;
            }
            case 4: { // View Tickets
                int id;
                cout << "Enter Match ID to view tickets: ";
                cin >> id;
                bool found = false;
                for (auto& m : matches) {
                    if (m.getMatchId() == id) {
                        m.showTickets(""); // show all tickets
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Invalid Match ID\n";
                break;
            }
            case 5:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
}

void fanMenu(vector<Match>& matches) {
    int choice;
    do {
        cout << "\n--- Fan Menu ---\n";
        cout << "1. View Matches\n";
        cout << "2. Book Ticket\n";
        cout << "3. Cancel Ticket\n";
        cout << "4. View My Tickets\n";
        cout << "5. Back\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: { // View Matches
                cout << "\nAvailable Matches:\n";
                for (int i = 0; i < matches.size(); i++)
                    matches[i].showAvailableSeats();
                break;
            }
            case 2: { // Book Ticket
                int id;
                string fanName;
                cout << "Enter Match ID: ";
                cin >> id;
                cin.ignore();
                cout << "Enter Your Name: ";
                getline(cin, fanName);

                bool found = false;
                for (auto& m : matches) {
                    if (m.getMatchId() == id) {
                        found = true;
                        if (m.bookSeat(fanName))
                            cout << "Ticket booked successfully!\n";
                        else
                            cout << "Match is full.\n";
                        break;
                    }
                }
                if (!found)
                    cout << "Invalid Match ID\n";
                break;
            }
            case 3: { // Cancel Ticket
                int matchId, ticketId;
                cout << "Enter Match ID: ";
                cin >> matchId;
                cout << "Enter Ticket ID: ";
                cin >> ticketId;

                bool found = false;
                for (auto& m : matches) {
                    if (m.getMatchId() == matchId) {
                        found = true;
                        if (m.cancelTicket(ticketId))
                            cout << "Ticket cancelled successfully\n";
                        else
                            cout << "Ticket not found\n";
                        break;
                    }
                }
                if (!found)
                    cout << "Invalid Match ID\n";
                break;
            }
            case 4: { // View My Tickets
                string fanName;
                cin.ignore();
                cout << "Enter Your Name: ";
                getline(cin, fanName);

                bool hasTickets = false;
                for (int i = 0; i < matches.size(); i++) {
                    if (matches[i].hasTicketFor(fanName)) {
                        matches[i].showTickets(fanName);
                        hasTickets = true;
                    }
                }
                if (!hasTickets)
                    cout << "No tickets found.\n";
                break;
            }
            case 5:
                cout << "Returning to main menu...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);
}
