#ifndef CSHGEN_H
#define CSHGEN_H
#include "cshunit.h"
#include "GenInterface.h"

class GenerateCSH : public IGenerate
{
public:
    explicit GenerateCSH();
    ~GenerateCSH();

    std::shared_ptr<ClassUnit> GenClassUnit(const std::string name, unsigned int modifier = ClassUnit::DEFAULT);

    std::shared_ptr<MethodUnit> GenMethodUnit(const std::string name, const std::string returnType, unsigned int flags = MethodUnit::DEFAULT);

    std::shared_ptr<PrintOperatorUnit> GenPrintOperatorUnit(const std::string text);
};

#endif // CSHGEN_H
