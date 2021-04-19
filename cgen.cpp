#include "cgen.h"

GenerateCplus::GenerateCplus() {}

GenerateCplus::~GenerateCplus() {}

std::shared_ptr<ClassUnit>GenerateCplus::GenClassUnit(const std::string name, unsigned int modifier)
{
    return std::make_shared<CPPClassUnit >(name, ClassUnit::DEFAULT);
}

std::shared_ptr<MethodUnit>GenerateCplus::GenMethodUnit(const std::string name, const std::string returnType, unsigned int Flags)
{
    return std::make_shared<CPPMethodUnit >(name, returnType, Flags);
}

std::shared_ptr<PrintOperatorUnit>GenerateCplus::GenPrintOperatorUnit(const std::string text)
{
    return std::make_shared<CPPPrintOperatorUnit >(text);
}
