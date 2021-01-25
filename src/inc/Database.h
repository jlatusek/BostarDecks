#pragma once

#include <sqlite3.h>

#include <string>
namespace Database {

class DatabaseOpenError : public std::exception {};

class Database;

class Model {
  friend Database;

 public:
  Model(std::string a_create_table_sql)
      : create_table_sql(a_create_table_sql){};
  virtual void create_table(Database &db) = 0;

 private:
  const std::string create_table_sql;
};

class Database {
 public:
  Database(std::string filename = "bostardeck_database.sql");
  ~Database();
  void open();
  void close();
  int create_table(Model &model);
  int callback(void *NotUsed, int argc, char **argv, char **azColName);

 private:
  sqlite3 *db = nullptr;
  char *zErrMsg;
  std::string filename;
  char *sql = nullptr;
};

class Deck : public Model {
 public:
  Deck();
  void create_table(Database &db) override;
};
class Flashcard : public Model {
 public:
  Flashcard();
  void create_table(Database &db) override;
};
}  // namespace Database