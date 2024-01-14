class GradeGraph
{
    int nAs;
    int nBs;
    int nCs;
    int nDs;
    int nFs;

public:
    GradeGraph() {}
    ~GradeGraph() {}
    void set(int numAs, int numBs, int numCs, int numDs, int numFs);
    void draw();
};