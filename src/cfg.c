#include "cfg.h"
#include <string.h> // memset()
#include <stdio.h> // snprintf()

void cfg_clear(cfg_t *cfg)
{
	if (cfg == NULL)
		return;

	memset(cfg->movie_filename, 0, sizeof(cfg->movie_filename));
	snprintf(cfg->movie_filename, sizeof(cfg->movie_filename)-1, "%s", DEFAULT_MOVIE_FILENAME);
	cfg->raytrace = 0;
	cfg->scene = DEFAULT_SCENE;
	cfg->numThreads = DEFAULT_NUM_THREADS;
	cfg->frames = DEFAULT_FRAMES;
	cfg->verbose = 0;
}

