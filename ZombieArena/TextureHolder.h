#pragma once
#ifndef TEXTURE_HOLDER_H
#define TEXTURE_HOLDER_H

#include <SFML/Graphics.hpp>
#include <map>

using namespace sf;
using namespace std;

class TextureHolder
{
private:
	//map hollding pair of strings and textures
	map<string, Texture> m_Textures;

	//a pointer of the sane type as the class itself
	//the one and only instance of the class
	static TextureHolder* m_s_Instance;
public:
	TextureHolder();
	//for getting a reference to a specific texture
	static Texture& GetTexture(string const& filename);
	int number = rand();
};


#endif // !TEXTURE_HOLDER_H