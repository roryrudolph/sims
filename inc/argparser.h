#ifndef ARGPARSER_H
#define ARGPARSER_H

#include "cfg.h"
#include <getopt.h> // getopt_long()
#include <cstdio> // strncpy()
#include <cstdlib>

#ifdef __cplusplus
extern "C"
{
#endif

#define HELP_ARG  1000

/**
 * Parses the command-line options given in argv and populates the
 * @c ProgramConfig struct
 * @param argc The number of command-line arguments
 * @param argv A string array of the command-line arguments
 * @param cfg The ProgramConfig struct to populate. Execution returns
 * immediately if this is NULL.
 */
static void argparser(int argc, char **argv, cfg_t *cfg)
{
	int c;

	if (cfg == NULL)
		return;

	while (1)
	{
		static struct option long_opts[] =
		{
			{ "dir", required_argument, 0, 'd' },
			{ "frames", required_argument, 0, 'f' },
			{ "raytrace", no_argument, &cfg->raytrace, 'r' },
			{ "scene", required_argument, 0, 's' },
			{ "threads", required_argument, 0, 't' },
			{ "verbose", no_argument, &cfg->verbose, 'v' },
			{ "help", no_argument, 0, HELP_ARG },
			{ 0, 0, 0, 0 }
		};

		int i = 0;

		c = getopt_long(argc, argv, "d:f:rs:t:v?", long_opts, &i);

		if (c == -1)
			break;

		switch (c)
		{
			case 'd': // Relative working directory
				snprintf(cfg->working_dir, sizeof(cfg->working_dir)-1, "%s", optarg);
				break;
			case 'f': // Simulation time in seconds
				cfg->frames = strtoul(optarg, NULL, 10);
				break;
			case 'r': // Enable raytracing
				cfg->raytrace = 1;
				break;
			case 's': // Scene
				cfg->scene = strtoul(optarg, NULL, 10);
				if (cfg->scene < 1 or cfg->scene > 2)
					cfg->scene = 1;
				break;
			case 't': // Number of threads to use
				cfg->numThreads = strtoul(optarg, NULL, 10);
				break;
			case 'v': // Print more messages
				cfg->verbose = 1;
				break;
			case '?':
			case HELP_ARG:
				printf("\
Usage: %s [OPTIONS...]\n\
\n\
Options\n\
  -d, --directory <DIR>     Relative working directory\n\
  -f, --frames <NUM>        Total number of frames to simulate\n\
                            Default=unlimited for scene 1\n\
                            Default=300 for scene 2 (raytracing)\n\
  -t, --threads <NUM>       Number of threads to use. Default=1\n\
  -r, --raytrace            Enable raytracing. Only supported for scene 2\n\
  -s, --scene <1 or 2>      Scene to render.\n\
                            Only scene 2 supports raytracing.\n\
                            Default=1\n\
  -v, --verbose             Print debug messages\n\
  -h, --help                Print this help message and exit\n\
\n\
Report bugs to <rory.rudolph@gatech.edu>\n", argv[0]);
				exit(0);
				break;
			default: // Unknown argument, ignore
				break;
		}
	}
}

#ifdef __cplusplus
}
#endif

#endif //ARGPARSER_H

