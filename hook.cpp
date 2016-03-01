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

namespace {
  void atexit_cb() {
    std::cerr << "test" << std::endl;
  }
}

__attribute((constructor)) void constructor() {
  if (getenv("DROMOZOA_HOOK_ATEXIT")) {
    atexit(&atexit_cb);
  }
}
