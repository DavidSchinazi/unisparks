#ifndef UNISPARKS_CONFIG_H
#define UNISPARKS_CONFIG_H

#ifndef WEARABLE
#  define WEARABLE 0
#endif // WEARABLE

// Pick which vest to build here.
#if !defined(CAMP_SIGN) && !defined(ROPELIGHT) && !defined(ORANGE_VEST) && !defined(HAMMER) && !defined(GUPPY)
#  define ORANGE_VEST 1
// #define CAMP_SIGN 1
// #define GUPPY 1
#endif

#ifndef CAMP_SIGN
#  define CAMP_SIGN 0
#endif // CAMP_SIGN

#ifndef ROPELIGHT
#  define ROPELIGHT 0
#endif // ROPELIGHT

// Choose whether to enable button lock.
#ifndef BUTTON_LOCK
#  define BUTTON_LOCK 0
#endif // BUTTON_LOCK

#ifndef GLOW_ONLY
#  define GLOW_ONLY 0
#endif // GLOW_ONLY

#ifndef VARIANT
#  define VARIANT X
#endif // VARIANT

#ifndef REVISION
#  define REVISION 1
#endif // REVISION

// Extra indirection ensures preprocessor expands macros in correct order.
#define STRINGIFY_INNER(s) #s
#define STRINGIFY(s) STRINGIFY_INNER(s)

#ifndef BOOT_MESSAGE
#  define BOOT_MESSAGE STRINGIFY(VARIANT) "-" STRINGIFY(REVISION)
#endif // BOOT_MESSAGE

#endif // UNISPARKS_CONFIG_H
