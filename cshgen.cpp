#include "cshgen.h"

GenerateCSH::GenerateCSH() {}
GenerateCSH::~GenerateCSH() {}

std::shared_ptr<ClassUnit> GenerateCSH::GenClassUnit(std::string name, unsigned int modifier)
{
    return std::make_shared< CSHClassUnit >(name, modifier);
}

std::shared_ptr<MethodUnit> GenerateCSH::GenMethodUnit(std::string name, std::string returnType, unsigned int flags)
{
    return std::make_shared< CSHMethodUnit >(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> GenerateCSH::GenPrintOperatorUnit(std::string text)
{
    return std::make_shared< CSHPrintOperatorUnit >(text);
}
