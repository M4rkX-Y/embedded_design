#include <iostream>
#include "GradeGraph.h"
#include "PassFailGraph.h"

using std::cin;
using std::cout;
using std::endl;

// Include all the necessary libraries/files
int main()
{
    int nAs, nBs, nCs, nDs, nFs; // Variables representing input grades.
    cout << "Welcome to the grade grapher." << endl;
    cout << "Enter the number of As, Bs, Cs, Ds and Fs." << endl;
    cout << "As: ";
    cin >> nAs;
    cout << "Bs: ";
    cin >> nBs;
    cout << "Cs: ";
    cin >> nCs;
    cout << "Ds: ";
    cin >> nDs;
    cout << "Fs: ";
    cin >> nFs;

    // A object is created which sets and calls the PassFailGraph.
    PassFailGraph *passFailGraph = new PassFailGraph;
    passFailGraph->setNPass(nAs + nBs + nCs);
    passFailGraph->setNFail(nDs + nFs);
    passFailGraph->draw();

    // A object is created which sets and calls the GradeGraph.
    GradeGraph *gradegraph = new GradeGraph;
    gradegraph->set(nAs, nBs, nCs, nDs, nFs);
    gradegraph->draw();

    // delete objects
    delete passFailGraph;
    delete gradegraph;
}