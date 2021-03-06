#include <string>

#include "Poco/Data/AbstractBinder.h"
#include "Poco/Data/AbstractExtractor.h"
#include "Poco/Data/TypeHandler.h"

namespace model {
class Deck
{
public:
  Deck(std::string name,
       std::string description,
       std::string tag,
       bool public_ = true,
       int id = 0);
  int getId() const;
  void setId(int id);
  void setName(std::string name);
  void setDescription(std::string description);
  void setOwnerId(int ownerId);
  void setPublic(bool public_);
  void setTag(std::string tag);
  std::string getName() const;
  std::string getDescription() const;
  int getOwnerId() const;
  bool isPublic() const;
  std::string getTag() const;

private:
  int id = 0;
  std::string name;
  std::string description;
  bool public_ = true;
  std::string tag;
};
}

namespace Poco::Data {

template<>
class TypeHandler<struct model::Deck>
{
public:
  static std::size_t size() { return 5; }

  void bind(std::size_t pos,
            const model::Deck& obj,
            Poco::Data::AbstractBinder::Ptr pBinder,
            Poco::Data::AbstractBinder::Direction dir)
  {

    // the table is defined as Person (LastName VARCHAR(30), FirstName VARCHAR,
    // Age INTEGER(3)) Note that we advance pos by the number of columns the
    // datatype uses! For string/int this is one.
    poco_assert_dbg(!pBinder.isNull());
    TypeHandler<int>::bind(pos++, obj.getId(), pBinder, dir);
    TypeHandler<std::string>::bind(pos++, obj.getName(), pBinder, dir);
    TypeHandler<std::string>::bind(pos++, obj.getDescription(), pBinder, dir);
    TypeHandler<bool>::bind(pos++, obj.isPublic(), pBinder, dir);
    TypeHandler<std::string>::bind(pos++, obj.getTag(), pBinder, dir);
  };

  void prepare(std::size_t pos,
               const model::Deck& obj,
               Poco::Data::AbstractPreparator::Ptr pPreparator)
  {

    // the table is defined as Person (LastName VARCHAR(30), FirstName VARCHAR,
    // Age INTEGER(3))
    poco_assert_dbg(!pPreparator.isNull());
    TypeHandler<int>::prepare(pos++, obj.getId(), pPreparator);
    TypeHandler<std::string>::prepare(pos++, obj.getName(), pPreparator);
    TypeHandler<std::string>::prepare(pos++, obj.getDescription(), pPreparator);
    TypeHandler<bool>::prepare(pos++, obj.isPublic(), pPreparator);
    TypeHandler<std::string>::prepare(pos++, obj.getTag(), pPreparator);
  };

  void extract(std::size_t pos,
               model::Deck& obj,
               const model::Deck& defVal,
               Poco::Data::AbstractExtractor::Ptr pExt)
  {

    // defVal is the default person we should use if we encunter NULL entries,
    // so we take the individual fields as defaults. You can do more complex
    // checking, ie return defVal if only one single entry of the fields is null
    // etc...
    poco_assert_dbg(!pExt.isNull());
    int id;
    std::string name;
    std::string description;
    bool public_;
    std::string tag;
    // the table is defined as Person (LastName VARCHAR(30), FirstName VARCHAR,
    // Age INTEGER(3))
    TypeHandler<int>::extract(pos++, id, defVal.getId(), pExt);
    TypeHandler<std::string>::extract(pos++, name, defVal.getName(), pExt);
    TypeHandler<std::string>::extract(
      pos++, description, defVal.getDescription(), pExt);
    TypeHandler<bool>::extract(pos++, public_, defVal.isPublic(), pExt);
    TypeHandler<std::string>::extract(pos++, tag, defVal.getTag(), pExt);
    obj.setId(id);
    obj.setName(name);
    obj.setDescription(description);
    obj.setPublic(public_);
    obj.setTag(tag);
  };
};
} // namespace Poco