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

#include <curl/curl.h>

int main(int argc, char* argv[]) {
  const char* url = "https://kotori.dromozoa.com/";
  if (argc > 1) {
    url = argv[1];
  }
  CURLcode result = curl_global_init(CURL_GLOBAL_ALL);
  if (result != CURLE_OK) {
    return 1;
  }
  CURL* easy = curl_easy_init();
  if (!easy) {
    return 1;
  }
  if (curl_easy_setopt(easy, CURLOPT_URL, url) != CURLE_OK) {
    return 1;
  }
  if (curl_easy_setopt(easy, CURLOPT_VERBOSE, 1) != CURLE_OK) {
    return 1;
  }
  if (curl_easy_perform(easy)) {
    return 1;
  }
  curl_easy_cleanup(easy);
  curl_global_cleanup();
  return 0;
}
