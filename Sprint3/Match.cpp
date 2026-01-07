#include "Match.h"

Match::Match(int id, string code, int cap) {
    this->match_id = id;
    this->matchCode = code;
    this->capacity = cap;
    this->bookedCount = 0;
}

int Match::getMatchID() const { return match_id; }
string Match::getMatchCode() const { return matchCode; }
int Match::getCapacity() const { return capacity; }
int Match::getBookedCount() const { return bookedCount; }

bool Match::isFull() {
    return bookedCount >= capacity;
}

bool Match::bookSeat(string fanName) {
    if (isFull()) return false;
    Ticket t(nextTicketId++, match_id, fanName);
    tickets.push_back(t);
    bookedCount++;
    return true;
}

bool Match::cancelTicket(int ticketId) {
    for (auto it = tickets.begin(); it != tickets.end(); ++it) {
        if (it->getTicketId() == ticketId) {
            tickets.erase(it);
            bookedCount--;
            return true;
        }
    }
    return false;
}

vector<string> Match::getTicketsForFan(string fanName) {
    vector<string> results;
    for (auto& t : tickets) {
        if (t.getOwnerName() == fanName) {
            results.push_back("Ticket #" + to_string(t.getTicketId()) + " for Match: " + matchCode);
        }
    }
    return results;
}