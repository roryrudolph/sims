#ifndef CFG_H
#define CFG_H

#ifdef __cplusplus
extern "C"
{
#endif


#define DEFAULT_DIRECTORY       "."
#define DEFAULT_MOVIE_FILENAME  "movie.mpeg"
#define DEFAULT_SCENE           1
#define DEFAULT_NUM_THREADS     1
#define DEFAULT_FPS             60
#define DEFAULT_FRAMES          (DEFAULT_FPS * 2)

/**
 * This is a structure to holds all the various program configuration options.
 * This is passed around to the various modules of the code
 */
typedef struct cfg
{
	char working_dir[128];
	char movie_filename[128];
	int raytrace;
	unsigned int scene;
	unsigned int numThreads;
	unsigned int frames;
	int verbose; // If 1, means to print more messages
} cfg_t;

/**
 * Clear a configuration struct to its defaults
 * @param cfg The configuration struct to clear
 */
void cfg_clear(cfg_t *cfg);


#ifdef __cplusplus
}
#endif

#endif //CFG_H
