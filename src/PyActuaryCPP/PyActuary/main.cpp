#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include "LifeTable.h"




namespace py = pybind11;

PYBIND11_MODULE(pyactuary, m) {

    py::class_<LifeTable, std::shared_ptr<LifeTable>>(m, "LifeTable")
        .def(py::init<std::map<int,double>>())
        .def("ix", &LifeTable::ix)
        .def("qx", &LifeTable::qx)
        .def("tpx", &LifeTable::tpx)
        .def("eol", &LifeTable::eol);


}
