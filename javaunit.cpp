#include "javaunit.h"

JavaClassUnit::JavaClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier) {}

JavaClassUnit::~JavaClassUnit() {}

std::string JavaClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        result += ACCESS_MODIFIERS[i] + ":\n";

        for (const auto& f : m_fields[i])
        {
            if (f)
                result += f->compile(level + 1);
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

JavaMethodUnit::JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
    MethodUnit(name, returnType, flags) {}

JavaMethodUnit::~JavaMethodUnit() {}

std::string JavaMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & STATIC)
    {
        result += "static ";
    }

    else if (m_flags & VIRTUAL)
    {
            result += "virtual ";
    }

    result += m_returnType + " ";
    result += m_name + "()";
    if (m_flags & CONST)
    {
        result += " const";
    }
    result += " {\n";

    for (const auto& b : m_body)
    {
        if (b)
            result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";

    return result;
}

JavaPrintOperatorUnit::JavaPrintOperatorUnit(const std::string& text) :
    PrintOperatorUnit(text) {}

JavaPrintOperatorUnit::~JavaPrintOperatorUnit() {}

std::string JavaPrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "System.out.println( \"" + m_text + "\" );\n";
}
