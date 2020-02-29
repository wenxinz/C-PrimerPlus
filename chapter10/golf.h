class Golf{
private:
    static const int Len = 40;
    char fullname[Len];
    int handicap;
public:
    Golf();
    Golf(const char * name, int hc);
    int setgolf();
    void rehandicap(int hc);
    void showgolf() const;
};
