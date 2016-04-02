#ifndef __MOO_VERSION_
#define __MOO_VERSION_

#include <tuple>
#include <ostream>
namespace Moo {

struct Version : public std::tuple<int, int> {
  using std::tuple<int, int>::tuple;
};

std::ostream &operator<<(std::ostream &os, Version version);

extern const Version version;
} /* Moo */

#endif /* end of include guard: __MOO_VERSION_ */
