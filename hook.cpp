// Copyright (C) 2016,2018 Tomoyuki Fujimori <moyu@dromozoa.com>
//
// This file is part of dromozoa-hook.
//
// dromozoa-hook is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// dromozoa-hook is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with dromozoa-hook.  If not, see <http://www.gnu.org/licenses/>.

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sstream>
#include <string>
#include <vector>

extern char** environ;

namespace {
  static const char* unset_envs[] = {
    "DROMOZOA_HOOK_ATEXIT=",
    "DYLD_INSERT_LIBRARIES=",
    "MallocPreScribble=",
    "MallocScribble=",
    "MallocStackLoggingNoCompact=",
    0,
  };

  bool starts_with(const char* input, const char* test) {
    return strncmp(input, test, strlen(test)) == 0;
  }

  void hook_atexit() {
    char** save = environ;
    try {
      if (char* command = getenv("DROMOZOA_HOOK_ATEXIT")) {
        std::vector<char*> envs;
        for (char** i = environ; *i != 0; ++i) {
          bool unset = false;
          for (const char* const* j = unset_envs; *j; ++j) {
            if (starts_with(*i, *j)) {
              unset = true;
              break;
            }
          }
          if (!unset) {
            envs.push_back(*i);
          }
        }
        std::ostringstream out;
        out << "DROMOZOA_HOOK_PID=" << getpid();
        std::string pid = out.str();
        envs.push_back(const_cast<char*>(pid.c_str()));
        envs.push_back(0);
        environ = &envs[0];
        system(command);
      }
    } catch (...) {}
    environ = save;
  }
}

__attribute((constructor)) void constructor() {
  if (getenv("DROMOZOA_HOOK_ATEXIT")) {
    atexit(hook_atexit);
  }
}
