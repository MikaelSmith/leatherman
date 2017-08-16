#include <leatherman/util/scoped_umask.hpp>
#include <sys/stat.h>  // umask()

using namespace std;

namespace leatherman { namespace util {

    scoped_umask::scoped_umask(uint16_t numask) : scoped_resource()
    {
        _resource = umask(0);
        umask(_resource | numask);
        _deleter = scoped_umask::restore;
    }

    void scoped_umask::restore(uint16_t& oldmask)
    {
        umask(oldmask);
    }

}}  // namespace leatherman::util
