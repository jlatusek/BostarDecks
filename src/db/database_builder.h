#pragma once

#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Data/Session.h"
#include <string>
namespace db {

class Model;

class DatabaseBuilder
{
public:
  explicit DatabaseBuilder(Poco::Data::Session& session);
  ~DatabaseBuilder();
  void createTables();
  void createDeckTable();
  void createDeckFlashcardTable();
  void createFlashcardTable();
  void createLevelTable();
  void createInfoTable();

private:
  Poco::Data::Session& session;
};

} // namespace db