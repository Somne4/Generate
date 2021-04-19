#ifndef CGEN_H
#define CGEN_H
#include "cppunit.h"
#include "GenInterface.h"

class GenerateCplus : public IGenerate
{
public:
    explicit GenerateCplus();
    ~GenerateCplus();

    std::shared_ptr<ClassUnit>GenClassUnit(const std::string name, unsigned int modifier = ClassUnit::DEFAULT);

    std::shared_ptr<MethodUnit>GenMethodUnit(const std::string name, const std::string returnType, unsigned int Flags = MethodUnit::DEFAULT);

    std::shared_ptr<PrintOperatorUnit>GenPrintOperatorUnit(const std::string text);
};

#endif // CGEN_H

