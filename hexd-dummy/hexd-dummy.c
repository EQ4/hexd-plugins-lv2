/*
 * Created on 2014-09-30 23:16:27 BRT
 * License is GPLv3, see COPYING.txt for more details.
 * @author: Danilo de Jesus da Silva Bellini
 */
#include "hexd.h"

typedef struct{ /* Ports (keeping manifest.ttl port index order) */
  float *in, *out;
} Plugin;

static void run(LV2_Handle instance, uint32_t n){
  Plugin *plugin = (Plugin*)instance;
  float *last, *in, *out;
  for(in = plugin->in, out=plugin->out, last=in + n; in <= last; in++, out++)
    *out = *in;
}

/* Creates the remaining functions and exports the plugin descriptor */
HEXD_DEFAULT_INSTANTIATE_WITHOUT_RATE
HEXD_DEFAULT_CONNECT_PORT
HEXD_DEFAULT_ACTIVATE
HEXD_DEFAULT_DEACTIVATE
HEXD_DEFAULT_CLEANUP
HEXD_DEFAULT_EXTENSION_DATA
HEXD_FINISH
