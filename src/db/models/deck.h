#pragma once
#include <string>

#include "Poco/Data/AbstractBinder.h"
#include "Poco/Data/AbstractExtractor.h"
#include "Poco/Data/AbstractPreparator.h"
#include "Poco/Data/TypeHandler.h"

namespace model {
struct Deck
{
public:
  Deck() = default;
  Deck(std::string name,
       std::string description,
       std::string tag,
       bool public_ = true,
       int id = 0);
  int id = 0;
  std::string name;
  std::string description;
  bool is_public = true;
  std::string tag;
};
}

namespace Poco {
namespace Data {

template<>
class TypeHandler<struct model::Deck>
{
public:
  static std::size_t size() { return 5; }

  static void bind(std::size_t pos,
            const model::Deck& obj,
            Poco::Data::AbstractBinder::Ptr pBinder,
            Poco::Data::AbstractBinder::Direction dir)
  {

    poco_assert_dbg(!pBinder.isNull());
    TypeHandler<int>::bind(pos++, obj.id, pBinder, dir);
    TypeHandler<std::string>::bind(pos++, obj.name, pBinder, dir);
    TypeHandler<std::string>::bind(pos++, obj.description, pBinder, dir);
    TypeHandler<bool>::bind(pos++, obj.is_public, pBinder, dir);
    TypeHandler<std::string>::bind(pos++, obj.tag, pBinder, dir);
  };

  static void prepare(std::size_t pos,
               const model::Deck& obj,
               Poco::Data::AbstractPreparator::Ptr pPreparator)
  {

    poco_assert_dbg(!pPreparator.isNull());
    TypeHandler<int>::prepare(pos++, obj.id, pPreparator);
    TypeHandler<std::string>::prepare(pos++, obj.name, pPreparator);
    TypeHandler<std::string>::prepare(pos++, obj.description, pPreparator);
    TypeHandler<bool>::prepare(pos++, obj.is_public, pPreparator);
    TypeHandler<std::string>::prepare(pos++, obj.tag, pPreparator);
  };

  static void extract(std::size_t pos,
               model::Deck& obj,
               const model::Deck& defVal,
               Poco::Data::AbstractExtractor::Ptr pExt)
  {

    poco_assert_dbg(!pExt.isNull());
    TypeHandler<int>::extract(pos++, obj.id, defVal.id, pExt);
    TypeHandler<std::string>::extract(pos++, obj.name, defVal.name, pExt);
    TypeHandler<std::string>::extract(
      pos++, obj.description, defVal.description, pExt);
    TypeHandler<bool>::extract(pos++, obj.is_public, defVal.is_public, pExt);
    TypeHandler<std::string>::extract(pos++, obj.tag, defVal.tag, pExt);
  };

};
}
}