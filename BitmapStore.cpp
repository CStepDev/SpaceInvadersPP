#include "BitmapStore.h"
#include <assert.h>
#include <iostream>

using namespace sf;

BitmapStore* BitmapStore::m_s_Instance = nullptr;

BitmapStore::BitmapStore()
{
	assert(m_s_Instance == nullptr);
	m_s_Instance = this;
}

void BitmapStore::addBitmap(std::string const& filename)
{
	// Get a reference to m_Textures using m_s_Instance
	auto& bitmapsMap = m_s_Instance->m_BitmapsMap;
	// auto is equivalent of map<string, Texture>

	// Create an interator to hold a key-value pair
	// and search for the required k-v p using the
	// passed in filename
	auto keyValuePair = bitmapsMap.find(filename);
	// auto is equivalent of map<string, Texture>::iterator

	// No match found? Save the texture in the map
	if (keyValuePair == bitmapsMap.end())
	{
		// Create a new key value pair using filename
		auto& texture = bitmapsMap[filename];
		texture.loadFromFile(filename);
	}
}

Texture& BitmapStore::getBitmap(std::string const& filename)
{
	// Get a reference to m_Textures using m_s_Instance
	auto& bitmapsMap = m_s_Instance->m_BitmapsMap;
	// auto is equivalent of map<string, Texture>

	// Create an iterator to hold a key-value pair
	// and search for the required k-v p using the
	// passed in filename
	auto keyValuePair = bitmapsMap.find(filename);
	// auto is equivalent of map<string, Texture>::iterator

	// Did we find a match?
	if (keyValuePair != bitmapsMap.end())
	{
		return keyValuePair->second;
	}
	else
	{
		#ifndef debuggingOnConsole
		std::cout << "BitmapStore::getBitmap() - Texture not found for " << filename << "." << std::endl;
		#endif // !debuggingOnConsole

		return keyValuePair->second;
	}

}