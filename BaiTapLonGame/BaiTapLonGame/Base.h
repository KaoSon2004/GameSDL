#ifndef Base_h_
#define Base_h_
#include "ComF.h"
class Base
{
public:
	Base();
	~Base();
	void free();
	bool loadFromFile(string path);
	void render(int x, int y, SDL_Rect* clip = NULL);
	int getWidth();
	int getHeigth();


private:
	SDL_Texture* mTexture;
	int mWidth;
	int mHeight;
};


#endif // !Base_h_
