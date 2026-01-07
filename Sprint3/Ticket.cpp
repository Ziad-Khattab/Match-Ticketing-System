#include "Ticket.h"

Ticket::Ticket(int tId, int mId, string owner) {
    ticket_id = tId;
    match_id = mId;
    ownerName = owner;
}

int Ticket::getTicketId() { return ticket_id; }
string Ticket::getOwnerName() { return ownerName; }
void Ticket::setOwnerName(string name) { ownerName = name; }