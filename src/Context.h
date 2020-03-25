#ifndef _CONTEXT_H
#define _CONTEXT_H

namespace Antix{
    struct Context
    {
        int major_version, minor_version;
        bool core;

        Context()
        {
            major_version = 3;
            minor_version = 3;
            core = true;
        }

        Context(int major_version, int minor_version, bool core)
        {
            this->major_version = major_version;
            this->minor_version = minor_version;
            this->core = core;
        }
    };
}
#endif