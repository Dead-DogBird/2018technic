#include "stdafx.h"
#include "GrapicManager.h"


GrapicManager::GrapicManager()
{
}


GrapicManager::~GrapicManager()
{

}

void GrapicManager::Init()
{
	direct = Direct3DCreate9(D3D_SDK_VERSION);

	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));
	d3dpp.Windowed = FALSE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;

	if (FAILED(direct->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, window,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp, &device)))
	{
		exit(0);
		return;
	}

	D3DXCreateSprite(device, &sprite);
}

void GrapicManager::Update()
{

}

void GrapicManager::Render()
{
	device->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,0), 1.0f, 0);
	device->BeginScene();
	sprite->Begin(D3DXSPRITE_ALPHABLEND);

	ObjectManager::Get()->Render();
	ObjectManager::Get()->LateRender();

	if (GetAsyncKeyState('M'))
	{
		ObjectManager::Get()->MapRender();
	}

	

	sprite->End();
	device->EndScene();
	device->Present(0, 0, 0, 0);
}

void GrapicManager::TextureRender(TextureEx ex)
{
	D3DXMATRIX mat;
	D3DXMATRIX center;
	D3DXMATRIX position;
	D3DXMATRIX rotation;
	D3DXMATRIX scale;
	D3DXMATRIX screen_position;
	D3DXMATRIX camera_position;
	D3DXMATRIX camera_roatation;

	float camera_size = Camera::Get()->size;
	if (ex.camera_on == false)
		camera_size = 1;

	D3DXMatrixTranslation(&center, -ex.center.x , -ex.center.y , 0);
	D3DXMatrixRotationZ(&rotation, D3DXToRadian(ex.image_angle));
	D3DXMatrixTranslation(&position, ex.x * camera_size, ex.y * camera_size, 0);
	D3DXMatrixScaling(&scale, ex.image_xscale* camera_size, ex.image_yscale* camera_size, 1);
	
	

	mat = center *scale * rotation * position;

	if (ex.camera_on == true)
	{
		D3DXMatrixRotationZ(&camera_roatation, D3DXToRadian(Camera::Get()->rotation));
		D3DXMatrixTranslation(&screen_position, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2, 0);
		D3DXMatrixTranslation(&camera_position,- Camera::Get()->x* Camera::Get()->size, -Camera::Get()->y* Camera::Get()->size, 0);

		mat *= camera_position;
		mat *= camera_roatation;
		mat *= screen_position;
	}
		

	

	sprite->SetTransform(&mat);

	sprite->Draw(ex.texture, &ex.texture_size, 0, 0,ex.image_blend);

}
