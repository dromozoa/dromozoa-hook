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

#include <stdexcept>
#include <iostream>

namespace {
  void f(const char* ptr) {
    if (ptr) {
      std::cout << ptr << "\n";
    } else {
      throw std::runtime_error("ptr is null");
    }
  }

  void handle(const char* ptr) {
    try {
      f(ptr);
    } catch (const std::exception& e) {
      std::cerr << "caught exception: " << e.what() << "\n";
    }
  }
}

extern "C" int handler(const char* ptr) {
  handle(ptr);
  return 0;
}
