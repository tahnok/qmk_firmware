#include QMK_KEYBOARD_H

#define BASE 0
#define SECND 1

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = {
    { KC_PGDOWN, KC_PGUP }
    // { KC_SYSTEM_SLEEP, LCAG(KC_A)}
  },
  [SECND] = {
    { KC_LEFT, KC_RIGHT }
  }
};

enum combo_events {
  CHANGE_LAYER
  };

const uint16_t PROGMEM change_layer[] = {KC_PGDOWN, KC_PGUP, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [CHANGE_LAYER] = COMBO_ACTION(change_layer),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
  switch(combo_index) {
    case CHANGE_LAYER:
      if (pressed) {
        layer_invert(SECND);
      }
      break;
  }
}