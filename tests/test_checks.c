#include "../miniRT.h"
#include <criterion/criterion.h>

void setup(void) {
    puts("Runs before the test");
}

void teardown(void) {
    puts("Runs after the test");
}

Test(checks, is_number, .init = setup, .fini = teardown) {
    cr_expect(is_number("2t") == 0, "Expected \"2t\" to be false.");
	cr_expect(is_number("1") == 0, "Expected \"1\" to be true.");
	cr_expect(is_number("-1.09") == 0, "Expected \"-1.09\" to be true.");
	cr_expect(is_number("0.999") == 0, "Expected \"0.999\" to be true.");
}