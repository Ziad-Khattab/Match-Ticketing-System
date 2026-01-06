#ifndef TICKET_H
#define TICKET_H

#include <string>
using namespace std;

class Ticket {
private:
    int ticket_id;
    int match_id;
    string ownerName;

public:
    Ticket(int tId, int mId, string owner);
    int getTicketId();
    string getOwnerName();
    void setOwnerName(string name);
};

#endif
