//
// Created by jakub on 1/10/21.
//

#pragma once
#include <string>
#include <vector>

#include "db/database.h"

namespace db
{
class Model
{
  friend Database;

public:
  explicit Model(Database &a_db) : db(a_db){};
  virtual const std::string &getCreateTableSQL();

protected:
  Database &db;
  std::string create_table_sql;
};

class Deck : public Model
{
public:
  explicit Deck(Database &a_db);
  static std::string createTableSQL;
  const std::string &getCreateTableSQL() override;

private:
  unsigned int id = 0;
  std::string name;
  std::string description;
  bool public_ = true;
  std::string tag;
};

class Tag : public Model
{
private:
  std::string name;
  static std::string createTableSQL;
};

class Flashcard : public Model
{
private:
  static std::string createTableSQL;
  std::string name;
  std::string averse;
  std::string reverse;
  std::string tip;
  std::vector<Tag> tag;
};

class Level : Model
{
private:
  static std::string createTableSQL;
  std::string name;
  unsigned int repeat_frequency;
};

class DeckFlashcard : public Model
{
public:
  DeckFlashcard(Deck &a_deck, Flashcard &a_flashcard, Level &a_level);

private:
  static std::string createTableSQL;
  Deck &deck;
  Flashcard &flashcard;
  Level &level;
  unsigned int good_answers = 0;
  unsigned int bad_answers = 0;
};

} // namespace db