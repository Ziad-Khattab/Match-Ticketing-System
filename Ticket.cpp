#include "Ticket.h"

Ticket::Ticket(int tId, int mId, string owner) {
    this->ticket_id = tId;
    this->match_id = mId;
    this->ownerName = owner;
}

int Ticket::getTicketId() {
    return this->ticket_id;
}

string Ticket::getOwnerName() {
    return this->ownerName;
}

void Ticket::setOwnerName(string name) {
    this->ownerName = name;
}
