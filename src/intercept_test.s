/**
 * intercept_test.s
 * Author: Lan
 * Date created: MM/DD/20XX
 * Description
 * This is used to intercept or simply change various functions in order to experiment with them
*/

.thumb
.section .text

#include "../Include/intercept_test.h"
#include "../Scripts/_Scripts.h"

run_test:
    l: b l
	bl call_shuko_please
