#ifndef CLASSUNIT_H
#define CLASSUNIT_H
#include "Unit.h"
#include <vector>

class ClassUnit : public Unit
{
public:
    enum AccessModifier
    {
        PUBLIC,
        PROTECTED,
        PRIVATE,
        DEFAULT,
        FINAL, // java
        ABSTRACT, // java
        INTERNAL, // c#
        PROTECTED_INTERNAL, // c#
        PRIVATE_PROTECTED // c#
    };
    static const std::vector< std::string > ACCESS_MODIFIERS;
public:
    explicit ClassUnit(const std::string& name, Flags modifier = AccessModifier::DEFAULT);
    void add(const std::shared_ptr< Unit >& unit, Flags flags);
    std::string compile(unsigned int level = 0) const = 0;
protected:
    std::string m_name;
    Flags m_modifier;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

#endif // CLASSUNIT_H
