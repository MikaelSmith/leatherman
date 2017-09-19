#include <leatherman/util/scope_exit.hpp>

using namespace std;

namespace leatherman { namespace util {

    scope_exit::scope_exit(function<void()> callback) :
        _callback(std::move(callback))
    {
    }

    scope_exit::~scope_exit()
    {
        invoke();
    }

    void scope_exit::invoke()
    {
        if (_callback) {
            _callback();
            _callback = nullptr;
        }
    }

}}  // namespace leatherman::util
