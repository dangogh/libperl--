#include "perl++.h"
#include "tap++.h"

using namespace perl;
using namespace TAP;

int main() {
	plan(2);
	Interpreter universe;

   Regex word_at_start = universe.regex("^\\w\\+");
   Regex word_at_end = universe.regex("\\w\\+$");
   String t1 = universe.value_of("wassup?");
   ok(t1.match(word_at_start), "Matched start of string");

   // TODO: shouldn't this return a false value?
   not_ok(t1.match(word_at_end), "Didn't match word at end of string");

}
