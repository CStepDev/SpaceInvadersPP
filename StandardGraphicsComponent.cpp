#include "StandardGraphicsComponent.h"
#include "BitmapStore.h"

void StandardGraphicsComponent::initialiseGraphics(std::string bitmapName, Vector2f objectSize)
{
	BitmapStore::addBitmap("graphics/" + bitmapName + ".png");

	m_Sprite.setTexture(BitmapStore::getBitmap("graphics/" + bitmapName + ".png"));
	auto textureSize = m_Sprite.getTexture()->getSize();
	m_Sprite.setScale(float(objectSize.x) / textureSize.x, float(objectSize.y) / textureSize.y);
	m_Sprite.setColor(Color(0, 255, 0));
}

void StandardGraphicsComponent::draw(RenderWindow& window, std::shared_ptr<TransformComponent> t)
{
	m_Sprite.setPosition(t->getLocation());
	window.draw(m_Sprite);
}
