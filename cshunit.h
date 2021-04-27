#ifndef CSHUNIT_H
#define CSHUNIT_H
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

class CSHClassUnit : public ClassUnit
{
public:
    explicit CSHClassUnit(const std::string& name, Flags modifier = ClassUnit::PUBLIC);
    ~CSHClassUnit();
    std::string compile(unsigned int level = 0) const;
};

class CSHMethodUnit : public MethodUnit
{
public:
    explicit CSHMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    ~CSHMethodUnit();
    std::string compile(unsigned int level = 0) const;
};

class CSHPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CSHPrintOperatorUnit(const std::string& text);
    ~CSHPrintOperatorUnit();
    std::string compile(unsigned int level = 0) const;
};


#endif // CSHUNIT_H
