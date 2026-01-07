#ifndef MATCH_H
#define MATCH_H

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
    int nextTicketId = 1;
    vector<Ticket> tickets;

public:
    Match(int id, string code, int cap);

    // Getters for GUI
    int getMatchID() const;
    string getMatchCode() const;
    int getCapacity() const;
    int getBookedCount() const;

    // Logic
    bool isFull();
    bool bookSeat(string fanName);
    bool cancelTicket(int ticketId);
    
    // Returns a list of strings instead of printing to cout
    vector<string> getTicketsForFan(string fanName);
};

#endif