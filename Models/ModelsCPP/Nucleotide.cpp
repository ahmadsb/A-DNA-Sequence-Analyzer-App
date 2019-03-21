#include "../ModelsHeader/Nucleotide.h"
#include <iostream>
static bool validChar(const char &ch)
{
    if (ch == 'A' || ch == 'T' || ch == 'C' || ch == 'G')
        return true;
    return false;
}

Nucleotide::Nucleotide() {}

Nucleotide::Nucleotide(const char &ch)
{
    if (!validChar(ch))
        throw std::invalid_argument("DNA sequence is illegal");
    m_ch = ch;
}

void Nucleotide::operator=(char ch)
{
    if (!validChar(ch))
        throw std::invalid_argument("DNA sequence is illegal");
    m_ch = ch;
}

Nucleotide::~Nucleotide() {}
