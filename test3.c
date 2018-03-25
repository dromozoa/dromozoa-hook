// Copyright (C) 2018 Tomoyuki Fujimori <moyu@dromozoa.com>
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

#include <dlfcn.h>

int main(int arc, char* argv[]) {
  typedef int (*handler_t)(const char*);

  const char* filename = argv[1];

  void* handle = dlopen(filename, RTLD_LAZY | RTLD_GLOBAL);
  if (!handle) {
    return 1;
  }

  int result = 0;
  do {
    handler_t symbol = (handler_t)dlsym(handle, "handler");
    if (!symbol) {
      result = 1;
      break;
    }
    symbol("foo");
    symbol(0);
  } while (0);

  dlclose(handle);
  return result;
}
