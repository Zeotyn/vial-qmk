// Copyright 2024 zeotyn
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// OLED
#define OLED_TIMEOUT 30000

// VIAL
// To regenerate: python3 util/vial_generate_keyboard_uid.py
#define VIAL_KEYBOARD_UID {0xEA, 0xFD, 0xE4, 0xA8, 0xE8, 0xA1, 0x19, 0xB1}

// Unlock combo: thumb keys SPC + ENT (matrix [4,4] and [9,4])
#define VIAL_UNLOCK_COMBO_ROWS {4, 9}
#define VIAL_UNLOCK_COMBO_COLS {4, 4}

// Split sync
#define SPLIT_LAYER_STATE_ENABLE
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_WPM_ENABLE
#define SPLIT_TRANSPORT_MIRROR

// Hand selection: USB side is always master
#define MASTER_LEFT

// Tap / hold
#define TAPPING_TERM 180
#define TAPPING_FORCE_HOLD

// Vial layer / feature budget
#define DYNAMIC_KEYMAP_LAYER_COUNT 5
#define VIAL_TAP_DANCE_ENTRIES 4
#define VIAL_COMBO_ENTRIES 8

// Save flash
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// TRI_LAYER
#define TRI_LAYER_LOWER_LAYER 2
#define TRI_LAYER_RAISE_LAYER 3
#define TRI_LAYER_ADJUST_LAYER 4
