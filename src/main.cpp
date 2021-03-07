#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Data/Session.h"
#include "db/database_builder.h"
#include "db/models/deck.h"
#include <iostream>
#include <vector>

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

int
main(int argc, char** argv)
{
  // register SQLite connector
  Poco::Data::SQLite::Connector::registerConnector();

  // create a session
  Session session("SQLite", "sample.db");

  db::DatabaseBuilder dbBuilder(session);
  dbBuilder.createTables();
  model::Deck deck("name", "description", "tag", true, 5);

  Statement insert(session);
  insert << "INSERT INTO deck VALUES(?, ?, ?, ?, ?)", use(deck), now;
  insert.execute();

  return 0;
}