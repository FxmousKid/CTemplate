#include <stdio.h>
#include <stdlib.h>

#include "parser/parser_cli.h"


int main(int argc, char *argv[])
{
	struct s_data ctx = {0};

	if (!parse_cli(&argc, argv, &ctx)) {
		ERR_MSG("failed to parse_cli")
		return EXIT_FAILURE;
	}


	printf("sucess\n");
	return EXIT_SUCCESS;
}
