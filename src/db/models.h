#pragma once

#include "Poco/Data/AbstractBinder.h"
#include "Poco/Data/AbstractExtractor.h"
#include "Poco/Data/TypeHandler.h"
#include <string>
#include <vector>

#include "db/database.h"

namespace db{

struct Tag 
{
private:
  std::string name;
  static std::string createTableSQL;
};

struct Flashcard 
{
  static std::string createTableSQL;
  std::string name;
  std::string averse;
  std::string reverse;
  std::string tip;
  std::vector<Tag> tag;
};

struct Level 
{
  static std::string createTableSQL;
  std::string name;
  unsigned int repeat_frequency;
};

struct DeckFlashcard 
{
  static std::string createTableSQL;
  // model::Deck& deck;
  Flashcard& flashcard;
  Level& level;
  unsigned int good_answers = 0;
  unsigned int bad_answers = 0;
};

} // namespace db