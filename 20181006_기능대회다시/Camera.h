#pragma once
class Camera : public Singleton<Camera>
{
public:
	Camera();
	~Camera();

	float x = 0;
	float y = 0;
	
	float rotation = 0;
	float size = 1;


	D3DXMATRIX GetCameraMatrix();

};

