#include "Version.hpp"

namespace Moo {

std::ostream &operator<<(std::ostream &os, Version version) {
  int major, minor;
  std::tie(major, minor) = version;
  return os << "version " << major << "." << minor;
}

const Version version{1, 0};

} /* Moo */
