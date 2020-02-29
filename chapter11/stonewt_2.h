//stonewt.h -- with all six relational operators reloaded

#ifndef STONEWT_H_
#define STONEWT_H_
class Stonewt{
private:
    enum {Lbs_per_stn = 14};
    int stone;         // whole stones
    double pds_left;   // fractional pounds
    double pounds;     // entire weight in pounds
public:
    Stonewt(double lbs);
    Stonewt(int stn, double lbs);
    Stonewt();
    ~Stonewt();
    void show_lbs() const;
    void show_stn() const;
    //operator overloading
    bool operator==(Stonewt & s) const;
    bool operator!=(Stonewt & s) const;
    bool operator>(Stonewt & s) const;
    bool operator>=(Stonewt & s) const;
    bool operator<(Stonewt & s) const;
    bool operator<=(Stonewt & s) const;
};

#endif
