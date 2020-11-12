#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "ProcessCommandLine.hpp"

TEST_CASE("check if each command is processed", "[cmdLine]")
{
    ProgramSettings settings {};
    const std::vector<std::string> args = {"-h", "--help", "--version", "-i", "input.txt", "-o", "output.txt", "-k", "5", "--encrypt"};
    REQUIRE( processComandLine(args, settings) == true );
}

