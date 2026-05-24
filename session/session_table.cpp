#include "session_table.h"

void SessionTable::add(std::string id, Session s) {
    table[id] = s;
}

bool SessionTable::exists(std::string id) {
    return table.find(id) != table.end();
}