#include "cshunit.h"

CSHClassUnit::CSHClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier) {}

CSHClassUnit::~CSHClassUnit() {}

std::string CSHClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_modifier & PROTECTED_INTERNAL)
        result += "protected internal ";

    else if (m_modifier & PRIVATE_PROTECTED)
        result += "private protected ";
    else
        result += "public ";

    result += "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        for (const auto& f : m_fields[i])
        {
            if (f)
                result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level);
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

CSHMethodUnit::CSHMethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
    MethodUnit(name, returnType, flags) {}

CSHMethodUnit::~CSHMethodUnit() {}

std::string CSHMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & STATIC)
        result += "static ";

    else if (m_flags & VIRTUAL)
        result += "virtual ";
    // Классы и структуры, объявленные без модификатора, по умолчанию имеют доступ internal.
    else
        result += "internal ";

    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";

    for (const auto& b : m_body)
    {
        if (b)
            result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";

    return result;
}

CSHPrintOperatorUnit::CSHPrintOperatorUnit(const std::string& text) :
    PrintOperatorUnit(text) {}

CSHPrintOperatorUnit::~CSHPrintOperatorUnit() {}

std::string CSHPrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "Console.WriteLine( \"" + m_text + "\" );\n";
}
