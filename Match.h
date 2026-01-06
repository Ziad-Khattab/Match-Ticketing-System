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
    vector<Ticket> tickets;
    bool isFull();

public:
    Match(int id, string code, int cap);

    bool bookSeat(string fanName);
    string getMatchCode();
    void showTickets();
    void showAvailableSeats();

    bool cancelTicket(int ticketId);
};

#endif
