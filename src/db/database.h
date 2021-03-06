#pragma once

#include "Poco/Data/SQLite/Connector.h"
#include "Poco/Data/Session.h"
namespace db {
class Database
{
  explicit Database(Poco::Data::Session& session);
};
}