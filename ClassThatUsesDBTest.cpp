#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "ClassThatUsesDB.h"
#include "MockDBConnection.h"

using ::testing::Return;

TEST(ClassThatUsesDBTest, OpenConnection) {
    MockDBConnection mockDb;
    ClassThatUsesDB classThatUsesDB(&mockDb);

    EXPECT_CALL(mockDb, open())
        .Times(1)
        .WillOnce(Return(true));

    EXPECT_TRUE(classThatUsesDB.openConnection());
}

TEST(ClassThatUsesDBTest, UseConnection) {
    MockDBConnection mockDb;
    ClassThatUsesDB classThatUsesDB(&mockDb);

    EXPECT_CALL(mockDb, open())
        .Times(1)
        .WillOnce(Return(true));
    EXPECT_CALL(mockDb, execQuery("SELECT * FROM table"))
        .Times(1)
        .WillOnce(Return("query result"));
    EXPECT_CALL(mockDb, close())
        .Times(1);

    classThatUsesDB.useConnection();
}

TEST(ClassThatUsesDBTest, CloseConnection) {
    MockDBConnection mockDb;
    ClassThatUsesDB classThatUsesDB(&mockDb);

    EXPECT_CALL(mockDb, close())
        .Times(1);

    classThatUsesDB.closeConnection();
}