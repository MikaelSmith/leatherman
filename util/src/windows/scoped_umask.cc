#include <leatherman/util/scoped_umask.hpp>

using namespace std;

namespace leatherman { namespace util {

    scoped_umask::scoped_umask(uint16_t numask) : scoped_resource()
    {
    }

    void scoped_umask::restore(uint16_t& oldmask)
    {
    }

}}  // namespace leatherman::util
