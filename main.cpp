#include <memory>
#include "cgen.h"
#include "generate.h"
#include "javagen.h"

using std::cout;
using std::cin;

int main()
{
    cout << "CPlus generator:" << std::endl;
    cout << std::endl;
    Generate Cplus(std::make_shared<GenerateCplus>());
    cout << Cplus.generate() << std::endl;

    cout << "Java generator:" << std::endl;
    cout << std::endl;
    Generate Java(std::make_shared<GenerateJava>());
    cout << Java.generate() << std::endl;

    return 0;
}


