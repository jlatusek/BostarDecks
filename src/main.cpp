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

  return 0;
}