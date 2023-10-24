#ifndef MSGASSERTH
#define MSGASSERTH

#include <stdio.h>
#include <stdlib.h>

#define avisoAssert(e,m) ((void) ((e)?0: __avisoassert (#e,__FILE__,__LINE__,m)))
#define __avisoassert(e,file,line,m) ((void) fprintf(stderr,"%s:%u: Aviso: '%s' - %s\n",file,line,e,m),0)
#define erroAssert(e,m) ((void) ((e)?0: __erroassert (#e,__FILE__,__LINE__,m)))

#endif
