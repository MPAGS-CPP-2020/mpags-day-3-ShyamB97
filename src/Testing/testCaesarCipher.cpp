#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

TEST_CASE("Encryption", "[cipher]")
{
    const size_t key {1};
    const std::string input {"ABCD"};
    const std::string output {"BCDE"};
    CaesarCipher cipher {key};
    
    REQUIRE( cipher.applyCipher(input, CipherMode::ENCRYPT) == output );
}

TEST_CASE("Decryption", "[cipher]")
{
    const size_t key {1};
    const std::string input {"BCDE"};
    const std::string output {"ABCD"};
    CaesarCipher cipher {key};
    
    REQUIRE( cipher.applyCipher(input, CipherMode::DECRYPT) == output );
}