//winec.h
#include <string>
#include <valarray>
#include "pairs.h"


class Wine{
private:
   typedef std::valarray<int> ArrayInt;
   typedef Pair<ArrayInt, ArrayInt> PairArray;
   std::string name;
   int years;
   PairArray info;
public:
   Wine() :name("null"), years(0), info(ArrayInt(),ArrayInt()) {} 
   //initialize label to l, number of years to y, vintage years to yr[]
   //,bottles to bot[]
   Wine(const char * l, int y, const int yr[], const int bot[])
        :name(l), years(y), info(ArrayInt(yr,y), ArrayInt(bot,y)) {}
   //initialize label to l, number of years to y, create array objects
   //of length y
   Wine(const char * l, int y)
        :name(l), years(y), info(ArrayInt(y), ArrayInt(y)) {}
   void GetBottles();
   std::string & Label();
   int sum();
   void Show() const;
};
