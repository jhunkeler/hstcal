/* These are the calibration steps that by default are not performed.
   This file is included only by lib/defswitch.c.
*/
#ifndef ACSOMIT_H
#define ACSOMIT_H

# define ACS_N_OMIT   3

static char omitsw[ACS_N_OMIT][9] = {"atodcorr", "shadcorr", "flshcorr"};

#endif
