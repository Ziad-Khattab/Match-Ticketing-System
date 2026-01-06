#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <vector>
#include <string>
#include "Ticket.h"
using namespace std;

class Match {
private:
    int match_id;
    string matchCode;
    int capacity;
    int bookedCount;
    int nextTicketId = 1; // For unique ticket IDs
    vector<Ticket> tickets;

public:
    Match(int id, string code, int cap);

    bool isFull();
    string getMatchCode();
    int getMatchId() const { return match_id; }
    bool bookSeat(string fanName);
    void showTickets(string name);
    void showAvailableSeats();
    bool cancelTicket(int ticketId);
    bool setCapacity(int newCapacity);


    bool hasTicketFor(string name) {
        for (auto& t : tickets) {
            if (t.getOwnerName() == name)
                return true;
        }
        return false;
    }
    vector<Ticket>& getTickets() { return tickets; }
};

#endif
