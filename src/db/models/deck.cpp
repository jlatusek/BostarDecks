#include "db/models/deck.h"

namespace model {

Deck::Deck(std::string name,
           std::string description,
           std::string tag,
           bool public_,
           int id)
  : name(name)
  , description(description)
  , public_(public_)
  , tag(tag)
{}

int
Deck::getId() const
{
  return id;
}

void
Deck::setId(int id)
{
  Deck::id = id;
}
std::string
Deck::getName() const
{
  return name;
}
void
Deck::setName(std::string name)
{
  Deck::name = name;
}
std::string
Deck::getDescription() const
{
  return description;
}

void
Deck::setDescription(std::string description)
{
  Deck::description = description;
}

bool
Deck::isPublic() const
{
  return public_;
}
void
Deck::setPublic(bool public_)
{
  public_ = public_;
}
std::string
Deck::getTag() const
{
  return tag;
}
void
Deck::setTag(std::string tag)
{
  Deck::tag = tag;
}
}
