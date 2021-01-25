
#include <Database.h>

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>
#include <exception>
#include <utility>

namespace Database {

Database::Database(std::string a_filename) : filename(std::move(a_filename)) {}

void Database::open() {
  int rc = sqlite3_open(filename.c_str(), &db);
  if (rc) {
    throw DatabaseOpenError();
    BOOST_LOG_TRIVIAL(error) << "Can't open database: %s\n"
                             << sqlite3_errmsg(db);
  } else {
    BOOST_LOG_TRIVIAL(info) << "Opened database successfully\n";
  }
}

int Database::create_table(Model &model) {
  int rc =
      sqlite3_exec(db, model.create_table_sql.c_str(), nullptr, 0, &zErrMsg);
  if (rc) {
    BOOST_LOG_TRIVIAL(error) << "Can't open database: \n" << sqlite3_errmsg(db);
    sqlite3_free(zErrMsg);
  } else {
    BOOST_LOG_TRIVIAL(info) << "Table created successfully\\n";
  }
  return rc;
};

int Database::callback(void *NotUsed, int argc, char **argv, char **azColName) {
  int i;
  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}

void Database::close() { sqlite3_close(db); }
Database::~Database() { close(); }

Deck::Deck()
    : Model(
          "CREATE TABLE if not exists deck"
          "("
          "id          INTEGER NOT NULL,"
          "name        TEXT    NOT NULL,"
          "description TEXT,            "
          "owner_id    INTEGER DEFAULT 0,"
          "public      INTEGER DEFAULT 0,"
          "tag         TEXT,            "
          "PRIMARY KEY (id)             "
          ")                                "){};
void Deck::create_table(Database &db) { db.create_table(*this); }

Flashcard::Flashcard()
    : Model(
          "CREATE TABLE if not exists flashcard"
          "("
          "id INTEGER NOT NULL,"
          "name   TEXT,"
          "avers  TEXT,"
          "revers TEXT,"
          "tip    TEXT,"
          "PRIMARY KEY (id)"
          ")")
          {};
void Flashcard::create_table(Database &db) { db.create_table(*this); }
}  // namespace Database
