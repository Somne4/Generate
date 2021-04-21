#ifndef GENERATE_H
#define GENERATE_H
#include "GenInterface.h"

class Generate
{
private:
    std::shared_ptr<IGenerate> gener;
public:
    explicit Generate(const std::shared_ptr<IGenerate>& Gen);
    ~Generate() {};
    void setGen(const std::shared_ptr<IGenerate>& Gen);
    std::shared_ptr<IGenerate> getGen();
    std::string generate();
};

#endif // GENERATE_H
