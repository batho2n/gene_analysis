#include <iostream>
#include <vector>
#include <string>


typedef struct arg_t
{
	std::vectoer<std::string>	input_file;
	std::string					type;
	std::string					type_name;
	std::vector<std::string>	write_name;
	std::string					output_file;
}


void usage()
{
	fprintf(stdout, "gene_tester.exe usage\n\n");
	fprintf(stdout, "Usage.\n");
	fprintf(stdout, "  gene_tester.exe -i infile [options] -o outfile\n");
	fprintf(stdout, "\n\n");
}



int main (int argc, char *argv[])
{
	if( argc < 2)
	{
		usage();
		return 0;
	}

	int err_code = 0;
	arg_t _argt;
	err_code = get_opt(argc, argv, &_argt);
	if(err_code != 0)		return 0;



	std::cout << "Test" << std::endl;

	return 0;
}
