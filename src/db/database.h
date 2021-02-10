#pragma once

#include <sqlite3.h>
#include <string>
namespace db
{

class DatabaseOpenError : public std::exception
{
};

class Model;

class Database
{
public:
  explicit Database(std::string filename = "bostardeck_database.sql");
  ~Database();
  void open();
  void close();
  int createTables();
  int listTableColumn(std::string tableName);
  static int callback(void *NotUsed, int argc, char **argv, char **azColName);

private:
  int exec(std::string);
  sqlite3 *db = nullptr;
  char *zErrMsg;
  std::string filename;
  char *sql = nullptr;
};

} // namespace db