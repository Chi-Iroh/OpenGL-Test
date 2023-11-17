#pragma once

#ifdef PREFIX_INCREMENTATION
    #error "PREFIX_INCREMENTATION macro already exists !"
#endif
#define PREFIX_INCREMENTATION

#ifdef POSTFIX_INCREMENTATION
    #error "POSTFIX_INCREMENTATION macro already exists !"
#endif
#define POSTFIX_INCREMENTATION int

#ifdef PREFIX_DECREMENTATION
    #error "PREFIX_DECREMENTATION macro already exists !"
#endif
#define PREFIX_DECREMENTATION

#ifdef POSTFIX_DECREMENTATION
    #error "POSTFIX_DECREMENTATION macro already exists !"
#endif
#define POSTFIX_DECREMENTATION int