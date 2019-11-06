#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

D3DXMATRIX Camera::GetCameraMatrix()
{
	D3DXMATRIX mat;
	D3DXMATRIX position;
	D3DXMATRIX mrotation;
	D3DXMATRIX screen_position;

	D3DXMatrixTranslation(&mat, -x * size, -y * size, 0);
	
	D3DXMatrixTranslation(&mat, 0,0, 0);


	mat = mrotation;

	//position * mrotation * 
	return mat;
}
