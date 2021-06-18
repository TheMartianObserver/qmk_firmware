#pragma once

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 200

#define LONG_TAPPING_TERM 1000

// Prevent normal rollover on alphas from accidentally triggering mods.
// #define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
// #define TAPPING_FORCE_HOLD
#define TAPPING_FORCE_HOLD_PER_KEY

// Apply the modifier on keys that are tapped during a short hold of a modtap
// #define PERMISSIVE_HOLD

#define ONESHOT_TAP_TOGGLE 3  /* Tapping this number of times holds the key until tapped once again. */
#define ONESHOT_TIMEOUT 5000  /* Time (in ms) before the one shot key is released */

#define MARTIAN_OS_MOD_TIMEOUT 15000
#define AUTO_SHIFT_TIMEOUT 175
#define AUTO_SHIFT_REPEAT
#define NO_AUTO_SHIFT_ALPHA
