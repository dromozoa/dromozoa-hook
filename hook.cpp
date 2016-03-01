// Copyright (C) 2016 Tomoyuki Fujimori <moyu@dromozoa.com>
//
// This file is part of dromozoa-atexit.
//
// dromozoa-atexit is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// dromozoa-atexit is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with dromozoa-atexit.  If not, see <http://www.gnu.org/licenses/>.

#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sstream>
#include <string>
#include <vector>

extern char** environ;

namespace {
  bool starts_with(const char* input, const char* test) {
    return strncmp(input, test, strlen(test)) == 0;
  }

  void hook_atexit() {
    char** save = environ;
    std::string command = getenv("DROMOZOA_HOOK_ATEXIT");
    std::vector<char*> envp;
    for (char** i = environ; *i != '\0'; ++i) {
      const char* s = *i;
      if (starts_with(s, "DROMOZOA_HOOK_ATEXIT=")) {
        continue;
      }
      if (starts_with(s, "DYLD_INSERT_LIBRARIES=")) {
        continue;
      }
      envp.push_back(*i);
    }
    std::ostringstream out;
    out << "DROMOZOA_HOOK_PID=" << getpid();
    std::string pid = out.str();
    envp.push_back(const_cast<char*>(pid.c_str()));
    envp.push_back(0);

    environ = &envp[0];
    system(command.c_str());
    environ = save;
  }
}

__attribute((constructor)) void constructor() {
  if (getenv("DROMOZOA_HOOK_ATEXIT")) {
    atexit(hook_atexit);
  }
}
