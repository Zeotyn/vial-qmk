BOOTLOADER          = rp2040
CONVERT_TO			= helios
VIA_ENABLE          = yes
VIAL_ENABLE         = yes
VIAL_INSECURE       = yes
LTO_ENABLE          = yes

RGBLIGHT_ENABLE     = no
RGB_MATRIX_ENABLE   = yes # Can't have RGBLIGHT and RGB_MATRIX at the same time.
MOUSEKEY_ENABLE     = yes
OLED_ENABLE         = yes
OLED_DRIVER         = ssd1306
EXTRAKEY_ENABLE     = yes
COMBO_ENABLE        = yes
TRI_LAYER_ENABLE    = yes
REPEAT_KEY_ENABLE   = yes
CAPS_WORD_ENABLE	= yes

WPM_ENABLE		    = yes

QMK_SETTINGS        = yes

CONSOLE_ENABLE      = false # Disable log in case i'm done with debugging
