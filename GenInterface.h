#ifndef GENINTERFACE_H
#define GENINTERFACE_H
#include "ClassUnit.h"
#include "Unit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

class IGenerate
{
public:

    virtual std::shared_ptr<ClassUnit>GenClassUnit(const std::string name, unsigned int modifier = ClassUnit::DEFAULT) = 0;

    virtual std::shared_ptr<MethodUnit>GenMethodUnit(const std::string name, const std::string returnType, unsigned int Flags = MethodUnit::DEFAULT) = 0;

    virtual  std::shared_ptr<PrintOperatorUnit>GenPrintOperatorUnit(const std::string text) = 0;

    virtual ~IGenerate() {};
};

#endif // GENINTERFACE_H
