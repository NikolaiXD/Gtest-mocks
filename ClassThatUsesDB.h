#ifndef CLASSTHATUSESDB_H
#define CLASSTHATUSESDB_H

#include "DBConnection.h"

class ClassThatUsesDB {
public:
    ClassThatUsesDB(DBConnection* db) : dbConnection(db) {}
    bool openConnection() {
        return dbConnection->open();
    }
    void useConnection() {
        if (dbConnection->open()) {
            std::string result = dbConnection->execQuery("SELECT * FROM table");
            // Обработка результата
            dbConnection->close();
        }
    }
    void closeConnection() {
        dbConnection->close();
    }

private:
    DBConnection* dbConnection;
};

#endif // CLASSTHATUSESDB_H