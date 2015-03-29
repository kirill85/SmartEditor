#ifndef KEYWORDS
#define KEYWORDS
#include <QString>
#include <initializer_list>

static QString keywords[] = std::initializer_list<QString>{"if", "else", "for", "while", "do",
        "#import", "#if", "#else", "#elseif", "#endif", "#ifdef", "defined", "#ifndef",
        "id", "nill", "@try", "@catch", "@trow", "@class", "@interface", "@implementation",
        "@end", "@synthesize", "@private", "@protected", "@public", "@selector", "typedef",
        "float", "double", "char", "signed", "unsigned", "short", "int", "long", "void", "@protocol",
        "@finally", "@synchronized", "const", "@property", "struct"};

#endif // KEYWORDS

