#include <gtest/gtest.h>

#include "db/database.h"
#include <iostream>

TEST(Database, OpenDatabase)
{
  db::Database database("testDB.sql");
  database.open();
  database.createTables();
  database.listTableColumn("deck");
  database.open();
  database.close();
}
