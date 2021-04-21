#ifndef JAVAGEN_H
#define JAVAGEN_H
#include "javaunit.h"
#include "GenInterface.h"

class GenerateJava : public IGenerate
{
public:
    explicit GenerateJava();
    ~GenerateJava();

    std::shared_ptr<ClassUnit> GenClassUnit(const std::string name, unsigned int modifier = ClassUnit::DEFAULT);

    std::shared_ptr<MethodUnit> GenMethodUnit(const std::string name, const std::string returnType, unsigned int flags = MethodUnit::DEFAULT);

    std::shared_ptr<PrintOperatorUnit> GenPrintOperatorUnit(const std::string text);
};

#endif // JAVAGEN_H
