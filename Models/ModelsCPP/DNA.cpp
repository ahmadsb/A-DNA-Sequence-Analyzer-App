#include "../ModelsHeader/DNA.h"

static std::string subString(const char *seq, int from, int to)
{
    std::string temp = "";
    int len = to - from, i;

    for (i = 0; i <= len; ++i)
        temp += seq[from + i];
    return temp;
}

static int find(std::string str, size_t len_root, const char *subseq, size_t len_sub)
{
    size_t i, j;
    for (i = 0; i <= (len_root - len_sub); ++i)
    {
        for (j = 0; j < len_sub; ++j)
            if (str[i + j] != subseq[j])
                break;

        if (j == len_sub)
            return (int)i;
    }

    return -1;
}

void DNA::init(const char *dna)
{

    size_t length = strlen(dna), i;
    try
    {
        m_Nuc = new Nucleotide[length];

        for (i = 0; i < length; ++i)
            m_Nuc[i] = Nucleotide(dna[i]); // operator= instane ctor of Nucleotide
    }
    catch (std::invalid_argument)
    {
        delete[] m_Nuc;
        m_Nuc = 0; //NULL
        throw;
    }
    catch (std::bad_alloc)
    {              // catch if the 'new' failed
        m_Nuc = 0; // = NULL
        throw;
    }
}

void DNA::initOperatorAssignment(const char *dna)
{
    size_t len = strlen(dna), i;
    delete[] m_Nuc;
    try
    {
        m_Nuc = new Nucleotide[len];
    }
    catch (std::bad_alloc)
    {              // catch if the 'new' failed
        m_Nuc = 0; // = NULL
        throw;
    }

    for (i = 0; i < len; ++i)
        m_Nuc[i] = Nucleotide(dna[i]); //operator= instance ctor of Nucleotide

    m_length = len;
}

DNA::DNA(const char *dna) : m_length(strlen(dna))
{
    init(dna);
}

DNA::DNA(const std::string &dna) : m_length(dna.length())
{
    init(dna.c_str());
}

DNA::DNA(const DNA &other)
{
    size_t len = other.size(), i;
    m_Nuc = new Nucleotide[len];
    for (i = 0; i < len; ++i)
        m_Nuc[i] = other.m_Nuc[i]; //operator= instance ctor of Nucleotide

    m_length = len;
}

// assigment = other ' copy ctor '  / str / char*

DNA &DNA::operator=(const DNA &other)
{
    if (this != &other)
    {
        size_t len = other.size(), i;

        delete[] m_Nuc; 
        m_Nuc = 0;      

        m_Nuc = new Nucleotide[len];

        for (i = 0; i < len; ++i)
            m_Nuc[i] = other.m_Nuc[i];
        m_length = len;
    }
    return *this;
}

DNA &DNA::operator=(const std::string &str)
{
    initOperatorAssignment(str.c_str());
    return *this;
}

DNA &DNA::operator=(const char *dna)
{
    initOperatorAssignment(dna);
    return *this;
}

DNA::~DNA() { delete[] m_Nuc; }

std::ostream &operator<<(std::ostream &os, const DNA &dna)
{
    if (dna.size())
    {
        size_t i;
        for (i = 0; i < dna.size(); ++i)
            os << dna.m_Nuc[i].getNucleotide();
    }
    return os;
}

DNA DNA::getSlice(size_t from, size_t to)
{
    std::string str = "";
    std::string temp = getSequence();
    const char *seq = temp.c_str();
    size_t i;
    for (i = from; i < to; ++i)
        str += seq[i];

    return DNA(str.c_str());
}


int DNA::count(const char *subseq)
{
    int counter = 0, position = 0;
    size_t len_sub = strlen(subseq), i;
    std::string temp = getSequence(), temp2 = getSequence();

    if (size() < len_sub)
        return counter; 

    for (i = 0; i < size(); ++i)
    {
        position = find(temp, temp.length(), subseq, len_sub);
        if (-1 != position)
        {
            temp[position] = '0';
            ++counter;
        }
    }

    return counter;
}

std::vector<int> DNA::findAll(const char *subseq)
{
    size_t len = count(subseq), len_root = size(), len_sub = strlen(subseq), i;
    int position = 0;
    std::vector<int> arr;
    std::string temp = getSequence();

    for (i = 0; i < len; ++i)
    {
        position = find(temp, len_root, subseq, len_sub);

        if (-1 != position)
        {
            arr.push_back(position);
        }
        temp[position] = '0';
    }
    return arr;
}

std::vector<DNA> DNA::FindConsensusSequences()
{
    std::vector<DNA> vecResult;
    std::vector<int> vetATG = findAll("ATG");
    std::vector<int> vecATT = findAll("TAA");
    std::vector<int> vecTGA = findAll("TGA");
    std::vector<int> vecTAG = findAll("TAG");
    size_t k, j;

    for (k = 0, j = 0; !vetATG.empty() && k < vetATG.size(); ++k)
    {

        int temp1 = vetATG.at(k), temp2 = -1, temp3 = -1, temp4 = -1;
        size_t counterTAA = 0, counterTGA = 0, counterTAG = 0, i;

        if (!vecATT.empty())
        {
            temp2 = vecATT.at(0);
            for (i = 0; i < vecATT.size(); ++i)
            {
                if (vetATG.at(k) < vecATT.at(i))
                    ++counterTAA;
            }
        }
        if (!vecTAG.empty())
        {
            temp3 = vecTAG.at(0);
            for (i = 0; i < vecTAG.size(); ++i)
            {
                std::cout << vetATG.at(k) << " < " << vecTAG.at(i) << std::endl;
                if (vetATG.at(k) < vecTAG.at(i))
                    ++counterTAG;
            }
        }

        if (!vecTGA.empty())
        {
            temp4 = vecTGA.at(0);
            for (i = 0; i < vecTGA.size(); ++i)
            {
                if (vetATG.at(k) < vecTGA.at(i))
                    ++counterTGA;
            }
        }

        std::cout << "TAA " << counterTAA << counterTAG << counterTGA << std::endl;

        j = 0;
        while (j < counterTAA)
        {

            if (((temp2 - temp1) - 1) % 3 == 2)
                vecResult.push_back(DNA(subString(getSequence().c_str(), temp1, temp2 + 2).c_str()));
            ++j;
            if (j < vecATT.size())
                temp2 = vecATT.at(j);
        }

        j = 0;

        while (j < counterTAG)
        {

            if (((temp3 - temp1) - 1) % 3 == 2)
                vecResult.push_back(DNA(subString(getSequence().c_str(), temp1, temp3 + 2).c_str()));
            ++j;
            if (j < vecTAG.size())
                temp3 = vecTAG.at(j);
        }
        j = 0;

        while (j < counterTGA)
        {

            if (((temp4 - temp1) - 1) % 3 == 2)
                vecResult.push_back(DNA(subString(getSequence().c_str(), temp1, temp4 + 2).c_str()));
            ++j;
            if (j < vecTGA.size())
                temp4 = vecTGA.at(j);
        }
    }
    return vecResult;
}
