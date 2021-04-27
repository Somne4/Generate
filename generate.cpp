#include "generate.h"

Generate::Generate(const std::shared_ptr<IGenerate>& Gen):
    gener(Gen) {}

void Generate::setGen(const std::shared_ptr<IGenerate>& Gen)
{
    gener = Gen;
}

std::shared_ptr<IGenerate> Generate::getGen()
{
    return gener;
}

std::string Generate::generate()
{
    auto p = gener->GenClassUnit("MyClass", ClassUnit::PUBLIC | ClassUnit::ABSTRACT);
    auto method1 = gener->GenMethodUnit( "testFunc1", "void", 0 );
    auto method2 = gener->GenMethodUnit( "testFunc2", "void",MethodUnit::ABSTRACT | MethodUnit::INTERNAL );
    auto method3 = gener->GenMethodUnit( "testFunc3", "void",MethodUnit::VIRTUAL | MethodUnit::CONST );
    auto method4 = gener->GenMethodUnit( "testFunc4", "void",MethodUnit::STATIC );
    auto print = gener -> GenPrintOperatorUnit( R"(Hello,world!\n)" );

    method4->add(print);

    p->add(method1, ClassUnit::PUBLIC );
    p->add(method2, ClassUnit::PRIVATE);
    p->add(method3, ClassUnit::PUBLIC);
    p->add(method4, ClassUnit::PROTECTED);

    return p->compile();
}
