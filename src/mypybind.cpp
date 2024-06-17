// #include <pybind11/pybind11.h>
#include <pybind11/numpy.h>

#include "mwvd.h"
#include "defs.h"


namespace py = pybind11;

 int add(int i, int j)
{
    return i + j;
}

void weighted_voronoi_diagram()
{
    std::string inFile = "my_input.pnts";
    std::string ipeFile, csvFile;
    bool bEnableView = false;
    const auto vorDiag = VorDiag{inFile, true, ipeFile, csvFile, bEnableView};
}

PYBIND11_MODULE(wevo_py, m)
{
    m.doc() = "Example module written in C++ by pybind11";

    m.def("weighted_voronoi_diagram", &weighted_voronoi_diagram, "computes weighted voronoi diagram from file and outputs to file");
}







// PYBIND11_MODULE(mypybind, m) {
//     m.doc() = "pybind11 example plugin"; // optional module docstring

//     m.def("add", &add, "A function which adds two numbers");
// }