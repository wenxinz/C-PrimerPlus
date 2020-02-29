//classic_d.h

#include "cd_d.h"

class Classic :public Cd{
private:
     char * primarywork;
public:
     Classic(const char * s0, const char * s1, const char * s2, int n, double x);
     Classic(const Cd & d, const char * s0);
     Classic();
     ~Classic();
     virtual void Report() const;
     Classic & operator=(const Classic & c);
};
