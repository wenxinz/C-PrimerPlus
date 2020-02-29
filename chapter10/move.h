class Move{
private:
    double x;
    double y;
public:
    Move(double a=0, double b=0);
    void showmove() const;
    Move add(const Move & m) const; // adds x of m to x of invoking object to
              // get new x, adds y of m to y of invoking object to get new y,
              // creates a new move object initialized to new x,y and return it
    void reset(double a=0, double b=0);
};
