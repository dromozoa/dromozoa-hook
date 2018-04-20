# Copyright (C) 2016,2018 Tomoyuki Fujimori <moyu@dromozoa.com>
#
# This file is part of dromozoa-hook.
#
# dromozoa-hook is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# dromozoa-hook is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with dromozoa-hook.  If not, see <http://www.gnu.org/licenses/>.

EXTRA_DIST = .gitignore README.md $(bin_SCRIPTS) $(TESTS)
TESTS = test1.sh test2-0.sh test2-1.sh test3.sh test4.sh test5.sh

bin_PROGRAMS = dromozoa-hook-version
bin_SCRIPTS = dromozoa-memcheck
lib_LTLIBRARIES = libdromozoa-hook.la
dist_pkgdata_DATA = dromozoa-memcheck.supp
noinst_PROGRAMS = test1.exe test2.exe test3.exe test4.exe test5.exe
noinst_LTLIBRARIES = libtest3-handler.la

libdromozoa_hook_la_LDFLAGS = -shared
libdromozoa_hook_la_SOURCES = hook.cpp
dromozoa_hook_version_SOURCES = version.cpp
test1_exe_SOURCES = test1.cpp
test2_exe_SOURCES = test2.cpp
test3_exe_SOURCES = test3.c
test4_exe_SOURCES = test4.cpp
test4_exe_LDADD = -lcurl
test5_exe_SOURCES = test5.cpp
test5_exe_LDADD = -lcurl
libtest3_handler_la_LDFLAGS = -shared -rpath $(abs_top_builddir)/.libs
libtest3_handler_la_SOURCES = test3-handler.cpp
