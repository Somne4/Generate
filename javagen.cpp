#include "javagen.h"

GenerateJava::GenerateJava() {}
GenerateJava::~GenerateJava() {}

std::shared_ptr<ClassUnit> GenerateJava::GenClassUnit(std::string name, unsigned int modifier)
{
    return std::make_shared< JavaClassUnit >(name, modifier);
}

std::shared_ptr<MethodUnit> GenerateJava::GenMethodUnit(std::string name, std::string returnType, unsigned int flags)
{
    return std::make_shared< JavaMethodUnit >(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> GenerateJava::GenPrintOperatorUnit(std::string text)
{
    return std::make_shared< JavaPrintOperatorUnit >(text);
}
