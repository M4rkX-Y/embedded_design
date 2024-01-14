#include "PassFailGraph.h"
#include "BarGraph.h"
#include <math.h>

void PassFailGraph::setNPass(int n)
{
    nPass = n;
}
void PassFailGraph::setNFail(int n)
{
    nFail = n;
}
int PassFailGraph::getNPass()
{
    return nPass;
}
int PassFailGraph::getNFail()
{
    return nFail;
}
void PassFailGraph::draw()
{
    BarGraph::displayAxis('=');
    BarGraph *BarPass = new BarGraph;
    BarGraph *BarFail = new BarGraph;

    int sum = nPass + nFail;
    BarPass->setSize(ceil(getNPass() / (sum / 50.0)));
    BarPass->setSymbol('P');
    BarPass->getBar();
    BarFail->setSize(ceil(getNFail() / (sum / 50.0)));
    BarFail->setSymbol('F');
    BarFail->getBar();
}