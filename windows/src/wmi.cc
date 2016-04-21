#include <leatherman/windows/wmi.hpp>
#include <leatherman/logging/logging.hpp>

using namespace std;
#define _ leatherman::locale::translate

namespace leatherman { namespace windows {

    wmi_exception::wmi_exception(string const& message) :
        runtime_error(message)
    {
    }

    wmi::~wmi()
    {
    }

    unique_ptr<wmi> wmi::get_wmi()
    {
        return unique_ptr<wmi>(new wmi_com());
    }

    string const& wmi::get(wmi::imap const& kvmap, string const& key)
    {
        static const string empty = {};
        auto valIt = kvmap.find(key);
        if (valIt == kvmap.end()) {
            return empty;
        } else {
            if (kvmap.count(key) > 1) {
                LOG_DEBUG("only single value requested from array for key {1}", key);
            }
            return valIt->second;
        }
    }

    wmi::kv_range wmi::get_range(wmi::imap const& kvmap, string const& key)
    {
        return kv_range(kvmap.equal_range(key));
    }

    string const& wmi::get(wmi::imaps const& kvmaps, string const& key)
    {
        if (kvmaps.size() > 0) {
            if (kvmaps.size() > 1) {
                LOG_DEBUG("only single entry requested from array of entries for key {1}", key);
            }
            return get(kvmaps[0], key);
        } else {
            throw wmi_exception(_("unable to get from empty array of objects"));
        }
    }

    wmi::kv_range wmi::get_range(wmi::imaps const& kvmaps, string const& key)
    {
        if (kvmaps.size() > 0) {
            if (kvmaps.size() > 1) {
                LOG_DEBUG("only single entry requested from array of entries for key {1}", key);
            }
            return get_range(kvmaps[0], key);
        } else {
            throw wmi_exception(_("unable to get_range from empty array of objects"));
        }
    }
}}  // namespace leatherman::windows
