#include "perl++.h"
#include "tap++.h"

using namespace perl;
using namespace TAP;

int main() {
	plan(2);
	Interpreter universe;
	Regex first = universe.regex("a*b");
	ok(first.match(universe.value_of("aab")), "\"aab\" =~ /a*b/;");
	not_ok(first.match("aaa"), "\"aaa\" !~ /a*b/;");
	return exit_status();
}
