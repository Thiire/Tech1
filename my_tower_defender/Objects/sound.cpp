/*
** EPITECH PROJECT, 2019
** sound.cpp
** File description:
** sound.cpp
*/

#include "sound.hpp"

Sound::Sound()
{
    if (_arbalete.loadFromFile("Son/arbalete.ogg"))    
        arbalete.setBuffer(_arbalete);
    if (_arc.loadFromFile("Son/arc.ogg"))
        arc.setBuffer(_arc);
    if (_click_constru.loadFromFile("Son/click_constru.ogg"))
       click_constru.setBuffer(_click_constru);
    if (_click_menu.loadFromFile("Son/click_menu.ogg"))
        click_menu.setBuffer(_click_menu);
    if (_defaite.loadFromFile("Son/defaite.ogg"))
        defaite.setBuffer(_defaite);
    if (_defense.loadFromFile("Son/defense.ogg"))
        defense.setBuffer(_defense);
    if (_fire.loadFromFile("Son/fire.ogg"))
        fire.setBuffer(_fire);
    if (_freeze.loadFromFile("Son/freeze.ogg"))
        freeze.setBuffer(_freeze);
    if (_labo.loadFromFile("Son/labo.ogg"))
        labo.setBuffer(_labo);
    if (_magie.loadFromFile("Son/magie.ogg"))
        magie.setBuffer(_magie);
    if (_victoire.loadFromFile("Son/Victoire.ogg"))
        victoire.setBuffer(_victoire);
    if (_zap.loadFromFile("Son/zap.ogg"))
        zap.setBuffer(_zap);
}

Music::Music()
{
    if (!menu.openFromFile("Son/menu.ogg"))
        std::cout << "nique" << std::endl;
    if (!game.openFromFile("Son/game.ogg"))
        std::cout << "nique" << std::endl;
}