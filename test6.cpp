// Copyright (C) 2019 Tomoyuki Fujimori <moyu@dromozoa.com>
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

#include <openssl/err.h>
#include <openssl/evp.h>

#include <iostream>
#include <vector>

int main(int, char*[]) {
  std::vector<unsigned char> data(32);

  ERR_load_crypto_strings();

  EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
  EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), 0, data.data(), data.data());
  if (!EVP_CIPHER_CTX_set_key_length(ctx, 31)) {
    std::vector<char> buffer(256);
    ERR_error_string_n(ERR_get_error(), buffer.data(), buffer.size());
    std::cout << buffer.data() << "\n";
  }
  EVP_CIPHER_CTX_free(ctx);

  ERR_free_strings();

  return 0;
}
