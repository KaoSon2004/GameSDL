#ifndef Base_cpp_
#define Base_cpp_
#include "Base.h"
Base::Base()
{
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}

Base::~Base()
{
	free();
}
void Base::free()
{
	SDL_DestroyTexture(mTexture);
	mTexture = NULL;
	mWidth = 0;
	mHeight = 0;
}
int Base::getWidth() { return mWidth; }
int Base::getHeigth() {return mHeight;}
bool Base::loadFromFile(string path)
{
	bool success = true;
	SDL_Texture* newTexture = NULL;
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		cout << "Couldn't load image from " << path << endl;
		success = false;
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xff, 0xff));
		newTexture = SDL_CreateTextureFromSurface(g_renderer, loadedSurface);
		if (newTexture == NULL)
		{
			cout << "Couldn't create Texture from surface " << endl;
			success = false;
		}
		else
		{
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_FreeSurface(loadedSurface);
		mTexture = newTexture;
		return mTexture != NULL;
	}
}
void Base::render(int x, int y, SDL_Rect* clip)
{
	SDL_Rect rect;
	rect.x = x;
	rect.y = y;
	rect.w = mWidth;
	rect.h = mHeight;
	SDL_RenderCopy(g_renderer, mTexture, NULL, &rect);
}


#endif // Base_h_

