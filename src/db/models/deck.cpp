#include "db/models/deck.h"

namespace model {
Deck::Deck(std::string name,
           std::string description,
           std::string tag,
           bool is_public,
           int id)
  : name(name)
  , description(description)
  , tag(tag)
  , is_public(is_public)
  , id(id)
{}

}
