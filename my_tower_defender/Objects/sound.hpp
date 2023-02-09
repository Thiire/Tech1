/*
** EPITECH PROJECT, 2019
** sound.hpp
** File description:
** sound.hpp
*/

#include <iostream>
#include <cstdio>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <SFML/Audio.hpp>

#ifndef SOUND_HPP_
	#define SOUND_HPP_

class Sound
{
private:
	sf::SoundBuffer _arbalete;
	sf::SoundBuffer _arc;
	sf::SoundBuffer _click_constru;
	sf::SoundBuffer _click_menu;
	sf::SoundBuffer _defaite;
	sf::SoundBuffer _defense;
	sf::SoundBuffer _fire;
	sf::SoundBuffer _freeze;
	sf::SoundBuffer _labo;
	sf::SoundBuffer _magie;
	sf::SoundBuffer _victoire;
	sf::SoundBuffer _zap;
public:
	sf::Sound click_constru;
	sf::Sound click_menu;
	sf::Sound defaite;
	sf::Sound defense;
	sf::Sound fire;
	sf::Sound freeze;
	sf::Sound labo;
	sf::Sound magie;
	sf::Sound victoire;
	sf::Sound zap;
	sf::Sound arbalete;
	sf::Sound arc;
	Sound();
};

class Music
{
private:

public:
	sf::Music game;
	sf::Music menu;
	Music();
};
#endif /* !SOUND_HPP_ */
