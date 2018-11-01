#include <iostream>
#include <vector>
#include <string>


typedef struct arg_t
{
	std::vector<std::string>	input_file;
	std::string					type;
	std::string					type_name;
	std::vector<std::string>	write_name;
	std::string					output_file;
};


void usage()
{
	fprintf(stdout, "gene_tester.exe usage\n\n");
	fprintf(stdout, "Usage.\n");
	fprintf(stdout, "  gene_tester.exe --input infile [options] --output outfile\n");
	fprintf(stdout, "\n\n");
}


int get_opt(int argc, char **argv, arg_t *_argt)
{

	if (argc < 2)	goto usage;

	while(--argc)
	{
		if(strcmp(argv[argc], "--input") == 0)
		{
			_argt->input_file.push_back(argv[argc+1]);
		}
		else if(strcmp(argv[argc], "--type") == 0)
		{
			_argt->type = argv[argc+1];
		}
		else if(strcmp(argv[argc], "--output") == 0)
		{
			_argt->output_file = argv[argc+1];
		}

	}
	return 0;

usage:
	usage();
	return -1;
}
int main (int argc, char *argv[])
{
	int err_code = 0;
	arg_t _argt;
	err_code = get_opt(argc, argv, &_argt);
	if(err_code != 0)		return 0;


	std::cout << "Input: " << _argt.input_file[0] << std::endl;
	std::cout << "Type: " << _argt.type << std::endl;
	std::cout << "Output: " << _argt.output_file << std::endl;

	return 0;
}
