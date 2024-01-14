class PassFailGraph
{
    int nPass;
    int nFail;

public:
    PassFailGraph() {}
    ~PassFailGraph() {}
    void setNPass(int n);
    void setNFail(int n);
    int getNPass();
    int getNFail();
    void draw();
};