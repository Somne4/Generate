#include <memory>
#include "cgen.h"
#include "generate.h"
#include "javagen.h"
#include "cshgen.h"

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

    cout << "CSharp generator:" << std::endl;
    cout << std::endl;
    Generate Csh(std::make_shared<GenerateCSH>());
    cout << Csh.generate() << std::endl;

    return 0;
}


