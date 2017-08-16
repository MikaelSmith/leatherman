/**
 * @file
 * Declares the scoped resource for temporarily imposing a minimum umask.
 */
#pragma once

#include <leatherman/util/scoped_resource.hpp>
#include <string>

namespace leatherman { namespace util {

    /**
     * This is an RAII wrapper for temporarily imposing a minimum umask.
     * Does nothing on Windows. Generally not needed, as Windows inherits ACLs.
     */
    struct scoped_umask : scoped_resource<uint16_t>
    {
        /**
         * Temporarily imposes a minimum umask.
         * @param numask The minimum umask to apply.
         */
        explicit scoped_umask(uint16_t numask);

     private:
        static void restore(uint16_t&);
    };

}}  // namespace leatherman::util
