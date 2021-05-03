#ifndef CPPCLASSUNIT_H
#define CPPCLASSUNIT_H
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

class CPPClassUnit : public ClassUnit
{
public:
    explicit CPPClassUnit(const std::string& name, Flags modifier = ClassUnit::DEFAULT);
    ~CPPClassUnit();
    std::string compile(unsigned int level = 0) const;
};

class CPPMethodUnit : public MethodUnit
{
public:
    explicit CPPMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    ~CPPMethodUnit();
    std::string compile(unsigned int level = 0) const;
};

class CPPPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CPPPrintOperatorUnit(const std::string& text);
    ~CPPPrintOperatorUnit();
    std::string compile(unsigned int level = 0) const;
};

#endif // CPPUNIT_H
