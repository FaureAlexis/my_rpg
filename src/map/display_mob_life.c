/*
** EPITECH PROJECT, 2022
** my_rpg
** File description:
** display_mob_life
*/

#include "rpg.h"

void display_mob_life(map_t *map)
{
    mobe_t *mob = map->mobe;

    while (mob != NULL) {
        sfText_setString(mob->life_txt, mob->life_str);
        sfText_setPosition(mob->life_txt,
        (sfVector2f){mob->object->position.x - 50,
        mob->object->position.y - 30});
        mob = mob->next;
    }
}
