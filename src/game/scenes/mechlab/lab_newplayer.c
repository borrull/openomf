#include "game/scenes/mechlab/lab_newplayer.h"
#include "game/gui/xysizer.h"
#include "game/gui/spriteimage.h"
#include "game/gui/label.h"
#include "game/gui/textinput.h"
#include "resources/bk.h"

component* lab_newplayer_create(scene *s) {
    component *xy = xysizer_create();

    // Text config
    text_settings tconf;
    text_defaults(&tconf);
    tconf.font = FONT_SMALL;
    tconf.halign = TEXT_CENTER;
    tconf.cforeground = color_create(0, 0, 123, 255);

    // Background name box
    animation *main_sheets = &bk_get_info(&s->bk_data, 1)->ani;
    sprite *msprite = animation_get_sprite(main_sheets, 5);
    xysizer_attach(xy, spriteimage_create(msprite->data), msprite->pos.x, msprite->pos.y, -1, -1);

    // Dialog text
    xysizer_attach(xy, label_create(&tconf, "ENTER PILOTS NAME"), 110, 43, 100, 50);

    // Input field
    tconf.cforeground = color_create(0, 121, 0, 255);
    component *input = textinput_create(&tconf, "Name", "");
    component_select(input, 1);
    textinput_enable_background(input, 0);
    textinput_set_max_chars(input, 8);
    xysizer_attach(xy, input, 101, 62, 120, 8);

    return xy;
}