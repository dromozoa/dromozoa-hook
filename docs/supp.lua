-- Copyright (C) 2018 Tomoyuki Fujimori <moyu@dromozoa.com>
--
-- This file is part of dromozoa-hook.
--
-- dromozoa-hook is free software: you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation, either version 3 of the License, or
-- (at your option) any later version.
--
-- dromozoa-hook is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License
-- along with dromozoa-hook.  If not, see <http://www.gnu.org/licenses/>.

local filename = ...

local handle = assert(io.open(filename))
local content = handle:read "*a"
handle:close()

for block in content:gmatch "{\n   <insert_a_suppression_name_here>.-\n}\n" do
  block = block:gsub("   fun:main\n", "   ...\n")
  io.write(block)
end
