#ifndef DNA_H
#define DNA_H

#include "Nucleotide.h"
#include <string>
#include <iostream>
#include <ostream>
#include <cstring>
#include <cassert>
#include <vector>

class DNA
{

friend std::ostream &operator<<(std::ostream &os, const DNA &dna);

public:
    DNA(const char *dna);        //characters {A, C, T, G}. // const
    DNA(const std::string &dna); // {A, C, T, G} // const
    DNA(const DNA &other);       // copy Ctor
    ~DNA();

    // whye operator= returns 'DNA&' to order allows d1=d2=d3 chain 'shrshrt'
    DNA &operator=(const DNA &other);
    DNA &operator=(const std::string &str);
    DNA &operator=(const char *dna);
    std::string getSequence() const;

    // more function
    DNA getSlice(size_t from, size_t to);
    int count(const char *subseq);
    std::vector<int> findAll(const char *subseq);
    std::vector<DNA> FindConsensusSequences();

    bool operator==(const DNA &other);
    bool operator!=(const DNA &other);
    const Nucleotide operator[](size_t index) const; 
    Nucleotide &operator[](size_t index);
    inline size_t size() const;

private:
    Nucleotide *m_Nuc;
    mutable size_t m_length;
    void init(const char *dna);
    void initOperatorAssignment(const char *dna);
};

inline size_t DNA::size() const { return m_length; }

inline bool DNA::operator==(const DNA &other)
{
    if (m_length == other.size())
    {
        size_t i;
        for (i = 0; i < size(); ++i)
            if (m_Nuc[i].getNucleotide() != other.m_Nuc[i].getNucleotide())
                return false;
    }
    return true;
}

inline bool DNA::operator!=(const DNA &other)
{
    return !(*this == other);
}

inline const Nucleotide DNA::operator[](size_t index) const
{
    assert(0 <= index && index < size());
    return m_Nuc[index];
}

inline Nucleotide &DNA::operator[](size_t index)
{
    assert(0 <= index && index < size());
    return m_Nuc[index];
}

inline std::string DNA::getSequence() const
{
    std::string temp;
    for (size_t i = 0; i < size(); i++)
    {
        temp += m_Nuc[i].getNucleotide();
    }
    return temp;
}


#endif