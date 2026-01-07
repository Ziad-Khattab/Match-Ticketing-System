#include "Match.h"

Match::Match(int id, string code, int cap) {
    this->match_id = id;
    this->matchCode = code;
    this->capacity = cap;
    this->bookedCount = 0;
}

bool Match::isFull() {
    return bookedCount >= capacity;
}

string Match::getMatchCode() {
    return matchCode;
}

bool Match::bookSeat(string fanName) {
    if (isFull())
        return false;

    Ticket t(nextTicketId++, match_id, fanName); // unique ID
    tickets.push_back(t);
    bookedCount++;
    return true;
}

void Match::showTickets(string name) {
    bool found = false;

    for (int i = 0; i < tickets.size(); i++) {
        if (name.empty() || tickets[i].getOwnerName() == name) {
            cout << "Match ID: " << match_id
                 << " | Match Code: " << matchCode
                 << " | Ticket ID: " << tickets[i].getTicketId()
                 << " | Owner: " << tickets[i].getOwnerName()
                 << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No tickets found.\n";
    }
}

void Match::showAvailableSeats() {
    cout << match_id << " - " << matchCode
         << " | Available: " << (capacity - bookedCount) << endl;
}

bool Match::cancelTicket(int ticketId) {
    vector<Ticket>::iterator it;

    for (it = tickets.begin(); it != tickets.end(); ++it) {
        if (it->getTicketId() == ticketId) {
            tickets.erase(it);
            bookedCount--;
            return true;
        }
    }
    return false;
}

bool Match::setCapacity(int newCapacity) {
    if (newCapacity < bookedCount) {
        return false;
    }
    capacity = newCapacity;
    return true;
}
