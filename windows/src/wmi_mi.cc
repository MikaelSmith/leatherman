#include <leatherman/windows/wmi.hpp>
#include <leatherman/logging/logging.hpp>

using namespace std;

namespace leatherman { namespace windows {

    wmi_mi::wmi_mi()
    {
    }

    wmi_mi::~wmi_mi()
    {
    }

    wmi::imaps wmi_mi::query(string const& group, vector<string> const& keys, string const& extended) const
    {
        return {};
    }

}}  // namespace leatherman::windows
