#include <memory>
#include "cgen.h"
#include "generate.h"

using std::cout;
using std::cin;

int main()
{
    cout << "CPlus generator:" << std::endl;
    Generate Cplus(std::make_shared<GenerateCplus>());
    cout << Cplus.generate() << std::endl;
    return 0;
}


