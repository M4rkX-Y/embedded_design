class BarGraph
{
    int size;
    char symbol;

public:
    BarGraph() {}
    ~BarGraph() {}
    void setSize(int sz);
    void setSymbol(char sym);
    static void displayAxis(char sym);
    void getBar();
};