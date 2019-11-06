#pragma once
using namespace std;
template <class T>
class Singleton;

struct TextureInfo
{
public:
	LPDIRECT3DTEXTURE9 texture;
	string path;
};


class TextureManager : public Singleton<TextureManager>
{
private:
	vector<TextureInfo> texture_vector;
	void AddTexture(string path);
public:
	TextureManager();
	~TextureManager();

	LPDIRECT3DTEXTURE9 LoadTexture(string path);
	
};

