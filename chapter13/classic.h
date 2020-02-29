//classic.h

#include "cd.h"

class Classic :public Cd{
private:
     char primarywork[50];
public:
     Classic(const char * s0, const char * s1, const char * s2, int n, double x);
     Classic(const Cd & d, const char * s0);
     Classic();
     virtual void Report() const;
     Classic & operator=(const Classic & c);
};
