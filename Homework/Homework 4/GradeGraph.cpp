#include "GradeGraph.h"
#include "BarGraph.h"
#include <math.h>

void GradeGraph::set(int numAs, int numBs, int numCs, int numDs, int numFs)
{
    nAs = numAs;
    nBs = numBs;
    nCs = numCs;
    nDs = numDs;
    nFs = numFs;
}

void GradeGraph::draw()
{
    BarGraph::displayAxis('+');
    BarGraph *BarA = new BarGraph;
    BarGraph *BarB = new BarGraph;
    BarGraph *BarC = new BarGraph;
    BarGraph *BarD = new BarGraph;
    BarGraph *BarF = new BarGraph;

    int sum = nAs + nBs + nCs + nDs + nFs;
    BarA->setSize(ceil(nAs / (sum / 50.0)));
    BarA->setSymbol('A');
    BarA->getBar();
    BarB->setSize(ceil(nBs / (sum / 50.0)));
    BarB->setSymbol('B');
    BarB->getBar();
    BarC->setSize(ceil(nCs / (sum / 50.0)));
    BarC->setSymbol('C');
    BarC->getBar();
    BarD->setSize(ceil(nDs / (sum / 50.0)));
    BarD->setSymbol('D');
    BarD->getBar();
    BarF->setSize(ceil(nFs / (sum / 50.0)));
    BarF->setSymbol('F');
    BarF->getBar();
}