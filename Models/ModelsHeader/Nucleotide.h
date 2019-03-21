#ifndef NECLEOTIDE_H
#define NECLEOTIDE_H

#include <ostream>

class Nucleotide
{
  public:
    Nucleotide();
    Nucleotide(const char &ch);
    ~Nucleotide();
    void operator=(char ch); //?
    char getNucleotide();
    void setNucleotide(char ch);

    Nucleotide pair();

  private:
    char m_ch;
};

inline char Nucleotide::getNucleotide() { return m_ch; }

inline void Nucleotide::setNucleotide(char ch) { m_ch = ch; }

inline Nucleotide Nucleotide::pair()
{
    char ch;
    switch (m_ch)
    {
    case 'A':
        ch = 'T';
    case 'T':
        ch = 'A';
    case 'G':
        ch = 'C';
    case 'C':
        ch = 'G';
    }
    return ch;
}

#endif