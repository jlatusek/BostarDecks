
#include "db/database_builder.h"

#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/trivial.hpp>
#include <exception>
#include <sstream>
#include <utility>

namespace db {

using namespace Poco::Data::Keywords;
using Poco::Data::Session;
using Poco::Data::Statement;

DatabaseBuilder::DatabaseBuilder(Poco::Data::Session& session)
  : session(session)
{}

void
DatabaseBuilder::createDeckTable()
{

  std::string sqlCommand =
    /*[[[cog
      from read_file import *
      read_file_as_string("../../db/deck.sql")
      ]]] */
    "CREATE TABLE if not exists deck"
    "("
    "    id          INTEGER NOT NULL,"
    "    name        TEXT    NOT NULL,"
    "    description TEXT,"
    "    is_public   INTEGER DEFAULT 0,"
    "    tag         TEXT,"
    "    PRIMARY KEY (id)"
    ")"
    // [[[end]]]
    ;
  session << sqlCommand, now;
}

void
DatabaseBuilder::createDeckFlashcardTable()
{

  std::string sqlCommand =
    /*[[[cog
      from read_file import *
      read_file_as_string("../../db/deckFlashcard.sql")
      ]]] */
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
    ")"
    // [[[end]]]
    ;
  session << sqlCommand, now;
}

void
DatabaseBuilder::createFlashcardTable()
{

  std::string sqlCommand =
    /*[[[cog
      from read_file import *
      read_file_as_string("../../db/flashcard.sql")
      ]]] */
    "CREATE TABLE if not exists flashcard"
    "("
    "    id      INTEGER NOT NULL,"
    "    name    TEXT,"
    "    averse  TEXT,"
    "    reverse TEXT,"
    "    tip     TEXT,"
    "    PRIMARY KEY (id)"
    ")"
    // [[[end]]]
    ;
  session << sqlCommand, now;
}

void
DatabaseBuilder::createLevelTable()
{
  std::string sqlCommand =
    /*[[[cog
      from read_file import *
      read_file_as_string("../../db/level.sql")
      ]]] */
    "CREATE TABLE if not exists level"
    "("
    "    id               INTEGER NOT NULL,"
    "    name             TEXT    NOT NULL,"
    "    repeat_frequency INTEGER DEFAULT 3600,"
    "    PRIMARY KEY (id)"
    ")"
    // [[[end]]]
    ;
  session << sqlCommand, now;
}

void
DatabaseBuilder::createInfoTable()
{
  std::string sqlCommand =
    /*[[[cog
      from read_file import *
      read_file_as_string("../../db/info.sql")
      ]]] */
    "CREATE TABLE if not exists info"
    "("
    "    id          INTEGER NOT NULL,"
    "    name        TEXT    NOT NULL,"
    "    value       TEXT    NOT NULL,"
    "    PRIMARY KEY (id)"
    ")"
    // [[[end]]]
    ;
  session << sqlCommand, now;
}

void
DatabaseBuilder::createTables()
{
  createDeckTable();
  createLevelTable();
  createFlashcardTable();
  createDeckFlashcardTable();
  createInfoTable();
}

DatabaseBuilder::~DatabaseBuilder()
{
}
} // namespace db
