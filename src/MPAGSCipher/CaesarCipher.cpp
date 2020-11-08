#include <string>
#include <iostream>

#include "CaesarCipher.hpp"
#include "CipherMode.hpp"

CaesarCipher::CaesarCipher(const size_t key)
: key_{key}
{
}

CaesarCipher::CaesarCipher(const std::string key)
: key_{0}
{
  // We have the key as a string, but the Caesar cipher needs an unsigned long, so we first need to convert it
  // We default to having a key of 0, i.e. no encryption, if no key was provided on the command line
  if ( ! key.empty() ) {
    // Before doing the conversion we should check that the string contains a
    // valid positive integer.
    // Here we do that by looping through each character and checking that it
    // is a digit. What is rather hard to check is whether the number is too
    // large to be represented by an unsigned long, so we've omitted that for
    // the time being.
    for ( const auto& elem : key ) {
      if ( ! std::isdigit(elem) ) {
	std::cerr << "[error] cipher key must be an unsigned long integer for Caesar cipher,\n"
	          << "        the supplied key (" << key << ") could not be successfully converted" << std::endl;
	return;
      }
    }
    key_ = std::stoul(key);
  }
}

const std::string CaesarCipher::applyCipher(const std::string& inputText, const CipherMode mode)
{
    // Create the output string
    std::string outputText {};

    // Make sure that the key is in the range 0 - 25
    const size_t truncatedKey { key_ % alphabetSize_ };

    // Loop over the input text
    char processedChar {'x'};
    for ( const auto& origChar : inputText )
    {
        // For each character in the input text, find the corresponding position in
        // the alphabet by using an indexed loop over the alphabet container
        for ( size_t i{0}; i < alphabetSize_; ++i )
        {
            if ( origChar == alphabet_[i] )
            {
              // Apply the appropriate shift (depending on whether we're encrypting
              // or decrypting) and determine the new character
              // Can then break out of the loop over the alphabet
              switch (mode)
              {
              case CipherMode::ENCRYPT:
                processedChar = alphabet_[ (i + truncatedKey) % alphabetSize_ ];
                break;
              
              case CipherMode::DECRYPT:
                processedChar = alphabet_[ (i + alphabetSize_ - truncatedKey) % alphabetSize_ ];
              
              default:
                break;
              }
            }
        }

        // Add the new character to the output text
        outputText += processedChar;
    }

    return outputText;
}