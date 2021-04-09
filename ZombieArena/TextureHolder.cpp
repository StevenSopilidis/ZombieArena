#include "TextureHolder.h"

#include <assert.h>

TextureHolder* TextureHolder::m_s_Instance = nullptr;

TextureHolder::TextureHolder()
{
	//make sure that m_s_Instance is null ptr
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

Texture& TextureHolder::GetTexture(string const& filename)
{
	//Get a reference to m_Textures using the m_s_Instance
	map<string, Texture>& m = m_s_Instance->m_Textures;

	// Create an iterator to hold a key-value-pair (kvp)
	// and search for the required kvp     
	// using the passed in file name 
	map<string, Texture>::iterator keyValuePair = m.find(filename);

	//if we fond a match
	if (keyValuePair != m.end())
	{
		//Yes we found 
		//return the texture
		return keyValuePair->second;
	}else
	{
		//file name was not found
		//load the texture and return it
		Texture& texture = m[filename];
		texture.loadFromFile(filename);

		return texture;
	}
}