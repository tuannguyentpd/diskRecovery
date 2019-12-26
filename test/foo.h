#include <boost/python.hpp>

class A {
    public:
        A(int i);

        int get_i() const;
    private:
  // don't use names such as `_i`; those are reserved for the
  // implementation
        int m_i;
};

BOOST_PYTHON_MODULE(foo) {
  using namespace boost::python;

  class_<A>("A", init<int>())
      .def("get_i", &A::get_i, "This is the docstring for A::get_i")
      ;
}