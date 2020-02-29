//winei.h

#include <string>
#include <valarray>
#include "pairs.h"

typedef std::valarray<int> ArrayInt;
typedef Pair<ArrayInt, ArrayInt> PairArray;

class Wine :private std::string, private PairArray{
private:
    int years;
public:
    Wine() :std::string("null"), PairArray(ArrayInt(),ArrayInt()){}
    Wine(const char * l, int y, const int yr[], const int bot[])
           :std::string(l), years(y), PairArray(ArrayInt(yr,y),ArrayInt(bot,y)){}
    Wine(const char * l, int y)
           :std::string(l), years(y), PairArray(ArrayInt(y),ArrayInt(y)){}
    void GetBottles();
    const std::string & Label() const;
    int sum();
    void Show() const;
};
