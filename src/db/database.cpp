
#include "db/database.h"

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>
#include <exception>
#include <sstream>
#include <utility>

namespace db
{

Database::Database(std::string a_filename) : filename(std::move(a_filename))
{
}

void Database::open()
{
  int rc = sqlite3_open(filename.c_str(), &db);
  if (rc)
  {
    throw DatabaseOpenError();
    BOOST_LOG_TRIVIAL(error) << "Can't open database: %s" << sqlite3_errmsg(db);
  }
  else
  {
    BOOST_LOG_TRIVIAL(info) << "Opened database successfully";
  }
}

int Database::exec(std::string command)
{
  int rc = sqlite3_exec(db, command.c_str(), Database::callback, 0, &zErrMsg);
  if (rc)
  {
    BOOST_LOG_TRIVIAL(error) << "Can't open database:" << sqlite3_errmsg(db);
    sqlite3_free(zErrMsg);
  }
  else
  {
    BOOST_LOG_TRIVIAL(info) << "Table created successfully";
  }
  return rc;
}

int Database::listTableColumn(std::string tableName)
{
  std::ostringstream stringStream;
  stringStream << "pragma table_info(" << tableName << ")";
  exec(stringStream.str().c_str());
  return 0;
}

int Database::createTables()
{
  std::string createTablesSQL =
    /*[[[cog
      from read_file import *
      read_file_as_string("../../db/create_db.sql")
      ]]] */
    "CREATE TABLE if not exists deck"
    "("
    "    id          INTEGER NOT NULL,"
    "    name        TEXT    NOT NULL,"
    "    description TEXT,"
    "    owner_id    INTEGER DEFAULT 0,"
    "    public      INTEGER DEFAULT 0,"
    "    tag         TEXT,"
    "    PRIMARY KEY (id)"
    ");"
    "CREATE TABLE if not exists deckFlashcard"
    "("
    "    id           INTEGER NOT NULL,"
    "    deck_id      INTEGER NOT NULL,"
    "    flashcard_id INTEGER NOT NULL,"
    "    level_id     INTEGER NOT NULL,"
    "    bad_answers  INTEGER DEFAULT 0,"
    "    good_answers INTEGER DEFAULT 0,"
    "    PRIMARY KEY (id),"
    "    FOREIGN KEY (deck_id)"
    "        REFERENCES deck (id)"
    "        ON DELETE SET NULL"
    "        ON UPDATE no action,"
    "    FOREIGN KEY (flashcard_id)"
    "        REFERENCES flashcard (id)"
    "        ON DELETE SET NULL"
    "        ON UPDATE no action,"
    "    FOREIGN KEY (level_id)"
    "        REFERENCES level (id)"
    "        ON DELETE SET NULL"
    "        ON UPDATE no action"
    ");"
    "CREATE TABLE if not exists flashcard"
    "("
    "    id      INTEGER NOT NULL,"
    "    name    TEXT,"
    "    averse  TEXT,"
    "    reverse TEXT,"
    "    tip     TEXT,"
    "    PRIMARY KEY (id)"
    ");"
    "CREATE TABLE if not exists level"
    "("
    "    id               INTEGER NOT NULL,"
    "    name             TEXT    NOT NULL,"
    "    repeat_frequency INTEGER DEFAULT 3600,"
    "    PRIMARY KEY (id)"
    ");"
    // [[[end]]]
    ;
  return exec(createTablesSQL);
};

int Database::callback(void *NotUsed, int argc, char **argv, char **azColName)
{
  int i;
  for (i = 0; i < argc; i++)
  {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

void Database::close()
{
  sqlite3_close(db);
}
Database::~Database()
{
  close();
}
} // namespace db
